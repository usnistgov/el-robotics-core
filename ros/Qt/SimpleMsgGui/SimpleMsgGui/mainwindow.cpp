#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QProcess>
#include <QString>

#include <iostream>
#include <unistd.h>

//#include "NIST/Debug.h"
#include "NIST/Globals.h"
#include "simple_message_defs.h"
static int seqnum=1;
using namespace simple_message;
simple_message::robot_info simple_message::the_robot;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    angle_multiplier(1.0)
{
    ui->setupUi(this);
    m_menuBar = menuBar();
    m_menuBar->setNativeMenuBar(false);
    statusconnection = new QtStatusConnection( ) ;
    commandconnection = new QtCommandConnection();
    threads.push_back(commandconnection);
    threads.push_back(statusconnection);

    connect(statusconnection, SIGNAL(TypedMessageEmitted(int, QString)), this, SLOT(TypedMessage(int, QString)));
    connect(commandconnection, SIGNAL(TypedMessageEmitted(int, QString)), this, SLOT(TypedMessage(int, QString)));
    connect(statusconnection, SIGNAL(UpdateJointsEmitted()), this, SLOT(set_joint_display()));
 }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Message(QString str)
{
    if(Globals.bQuitting)
        return;
     ui->plainTextEdit->appendPlainText (str);
}

void MainWindow::CmdMessage(QString str)
{
    if(Globals.bQuitting)
        return;
     ui->plainTextEdit_cmd->appendPlainText (str);
}

void MainWindow::TypedMessage(int t, QString str)
{
    if(Globals.bQDebug)
    {
        qDebug(str.toStdString().c_str());
    }
    if(t==COMMAND)
        CmdMessage(str);
    else if(t==STATUS)
        Message(str);
    else
    {
        QMessageBox::information(NULL, QObject::tr("!!!"),
                              QObject::tr(str.toStdString().c_str()),
                              QMessageBox::Ok, 0);
    }
}
void MainWindow::configure()
{

    // menu configuration: radians or degress
    alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(ui->actionRadians);
    alignmentGroup->addAction(ui->actionDegrees);
    alignmentGroup->setExclusive(true);
    ui->actionRadians->setCheckable(true);
    ui->actionDegrees->setCheckable(true);

    jntedits.push_back(ui->lineEdit_jnt0);
    jntedits.push_back(ui->lineEdit_jnt1);
    jntedits.push_back(ui->lineEdit_jnt2);
    jntedits.push_back(ui->lineEdit_jnt3);
    jntedits.push_back(ui->lineEdit_jnt4);
    jntedits.push_back(ui->lineEdit_jnt5);
    jntedits.push_back(ui->lineEdit_jnt6);

    Globals.bDebugMask=DEBUG_ALL; // have to check all?
    on_actionAll_triggered();

    // set up robot names combo box
    ui->comboBoxRobots->clear();
    for(size_t i=0; i<Globals.robots.size(); i++)
        ui->comboBoxRobots->addItem(QString::fromStdString(Globals.robots[i].name));

    // Use current robot (0 for now to assign index)
    //Globals.index=0; // if this is set, no change done in mycurrentRobotIndexChanged
    int index=0;
    ui->comboBoxRobots->setCurrentIndex(index);
    mycurrentRobotIndexChanged(index);

    // Now we connect signal for robot combo box change - as before it made too many events
    connect(ui->comboBoxRobots, SIGNAL(currentIndexChanged(int)), SLOT(mycurrentRobotIndexChanged(int)));
    //    ui->lineEdit_ip->setText(Globals.robots[index].ip);
    //    simple_message::swap_byte_order  =  Globals.robots[index].byteswap;

}

void MainWindow::close()
{
    usleep(10000);
    QApplication::quit();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    Globals.bQuitting=true;

    for(size_t i=0; i< threads.size(); i++)
        threads[i]->stopThread();

    sleep(2);
}

void MainWindow::on_pushButton_pingcomputer_clicked()
{
     QString hostname = ui->lineEdit_ip->text();
     hostname=hostname.trimmed();

#if defined(WIN32)
     int exitCode = QProcess::execute("ping", QStringList() << "-n" << "1" << hostname);
   // QString parameter = "-n 1 ";
#else
     int exitCode = QProcess::execute("ping", QStringList() << "-c 1 "  << hostname);
    //QString parameter = "-c 1 ";
#endif

    if (exitCode==0) {
        std::string msg = Globals.StrFormat("%s is up\n", hostname.toStdString().c_str());
        emit  Message(QString::fromStdString(msg));
        //demo->bConnected=true;
    } else {
        std::string msg = Globals.StrFormat("%s is not up", hostname.toStdString().c_str());
        emit  Message(QString::fromStdString(msg));
        //demo->bConnected=false;
    }
}

void MainWindow::on_pushButton_pingMsg_clicked()
{
    simple_message::ping_request_message pmsg;
    if(simple_message::swap_byte_order)
        pmsg.byte_swap();
    commandconnection->writeBytes((void *) &pmsg, sizeof(pmsg));
}

void MainWindow::on_pushButton_connect_clicked()
{
    // Get ui fields for command connection
    QString hostname = ui->lineEdit_ip->text();
    QString cmdport = ui->lineEditCmdPort->text();

    // get button name and toggled settings
    QString button_name = ui->pushButton_connect->text();
    QString gocommand_name("Connect Command");
    QString stopcommand_name("Disconnect Command");
    if(button_name==gocommand_name)
    {
        commandconnection->connection(hostname, cmdport.toLong());
        commandconnection->startThread();
        ui->pushButton_connect->setText(stopcommand_name);
    }
    else
    {
        commandconnection->stopThread();
        ui->pushButton_connect->setText(gocommand_name);
    }
}

void MainWindow::set_joint_display()
{

    QStringList  vals;
    for(size_t j=0; j<  the_robot.joint_number; j++)
    {
        float pos;
        the_robot.get_robot_joint_pos(&pos,j);
        if(angle_multiplier==1.0)
             vals.append(QString::number(pos));
        else
            vals.append(QString::number(pos *  180.0 / M_PI ));
    }

    for(size_t i=0; i< vals.size(); i++)
        jntedits[i]->setText(vals[i]);
}

void MainWindow::on_pushButton_jointmsg_clicked()
{
    QStringList js;
    simple_message::joint_traj_pt_request_message jmsg;
    for(size_t i=0; i< Globals.max_joints; i++) {
        js << jntedits[i]->text();
        jmsg.set_pos((float)(js[i].toFloat()*angle_multiplier),i);

    }
    jmsg.set_seq_number(++seqnum);
    if(simple_message::swap_byte_order)
        jmsg.byte_swap();
    commandconnection->writeBytes((void *) &jmsg, sizeof(jmsg));
}

void MainWindow::on_actionRadians_triggered()
{
    angle_multiplier=1.0;
}

void MainWindow::on_actionDegrees_triggered()
{
    angle_multiplier=(double) ( M_PI / 180.0 );
}

void MainWindow::on_actionEndianness_triggered()
{
    bool bBigEndian = Globals.is_big_endian();
    QString msg;
    if(bBigEndian)
        msg="Platform Big Endian";
    else
        msg="Platform Little Endian";

    QMessageBox::information(NULL, QObject::tr("Endian"),
                          QObject::tr(msg.toStdString().c_str()),
                          QMessageBox::Ok, 0);

}

void MainWindow::on_actionByte_Swap_triggered()
{
    simple_message::swap_byte_order=simple_message::swap_byte_order? false: true;
}

void MainWindow::on_pushButton_connect_2_clicked()
{


    QString hostname = ui->lineEdit_ip->text();
    QString cmdport = ui->lineEditCmdPort->text();
    QString statusport = ui->lineEdit_StatusPort->text();

    QString button_name = ui->pushButton_connect_2->text();
    QString gostatus_name("Connect Status");
    QString stopstatus_name("Disconnect Status");
    if(button_name==gostatus_name)
    {
        statusconnection->connection(hostname, statusport.toLong());
        statusconnection->startThread();
        ui->pushButton_connect_2->setText(stopstatus_name);
    }
    else
    {
        statusconnection->stopThread();
        ui->pushButton_connect_2->setText(gostatus_name);
    }

}

void MainWindow::on_actionHex_Dump_triggered()
{
    Globals.bHexdump= (Globals.bHexdump)? false : true;
}


void MainWindow::on_actionQDebug_triggered()
{
    Globals.bQDebug=Globals.bQDebug?false: true;
}

void MainWindow::on_actionNone_triggered()
{
    ui->actionNone->setChecked(true);
    ui->actionAll->setChecked(false);
    ui->actionReply->setChecked(false);
    ui->actionState->setChecked(false);
    ui->actionFeedback->setChecked(false);
    ui->actionRun->setChecked(false);
    Globals.bDebugMask=DEBUG_NONE;
}

void MainWindow::on_actionAll_triggered()
{
    ui->actionNone->setChecked(false);
    ui->actionAll->setChecked(true);
    ui->actionReply->setChecked(true);
    ui->actionState->setChecked(true);
    ui->actionFeedback->setChecked(true);
    ui->actionRun->setChecked(true);
    Globals.bDebugMask=DEBUG_ALL;

}

void MainWindow::on_actionFeedback_triggered()
{
    Globals.bDebugMask&= Globals.bDebug ? ~DEBUG_FEEDBACK : DEBUG_FEEDBACK;
}

void MainWindow::on_actionRun_triggered()
{
    Globals.bDebugMask&= Globals.bDebug ? ~DEBUG_RUN : DEBUG_RUN;
}

void MainWindow::on_actionState_triggered()
{
    Globals.bDebugMask&= Globals.bDebug ? ~DEBUG_STATE : DEBUG_STATE;
}

void MainWindow::on_actionReply_triggered()
{
    Globals.bDebugMask&= Globals.bDebug ? ~DEBUG_REPLY : DEBUG_REPLY;

}
static float random(float min, float max) {
    float r = ((double) rand() / (RAND_MAX)) * (max-min) + min;
    return r;
}

void MainWindow::on_pushButtonRandJts_clicked()
{
    simple_message::joint_traj_pt_request_message jmsg;
    for(size_t i=0; i< Globals.robots[Globals.index].maxjoints(); i++) {

        float max= Globals.robots[Globals.index].jointmaxvalues[i];
        float min = Globals.robots[Globals.index].jointminvalues[i];
        jmsg.set_pos(random(min, max ),i);

    }
    jmsg.set_seq_number(++seqnum);
    if(simple_message::swap_byte_order)
        jmsg.byte_swap();
    commandconnection->writeBytes((void *) &jmsg, sizeof(jmsg), true /*no throw*/);

}
void MainWindow::mycurrentRobotIndexChanged(int index)
{
    if(index < 0)
        return;
    if(index > Globals.robots.size())
    {
        QMessageBox::information(NULL, QObject::tr("Error"),
                              QObject::tr("Bad Index value???"),
                              QMessageBox::Ok, 0);
        return;
    }
    if(index != Globals.index)
    {
        simple_message::swap_byte_order  = Globals.robots[index].byteswap;
        ui->actionByte_Swap->setChecked(simple_message::swap_byte_order);

        ui->lineEdit_ip->setText(Globals.robots[index].ip);
        ui->lineEditCmdPort->setText(QString::number(Globals.robots[index].cmdport));
        ui->lineEdit_StatusPort->setText(QString::number(Globals.robots[index].statusport));
        Globals.index =index;

        Globals.max_joints=  Globals.robots[Globals.index].jointnames.size();
        for(size_t i=0; i< 7;i++)
        {
            if(i< Globals.max_joints)
                jntedits[i]->show();
            else
                jntedits[i]->hide();
        }
        // robot controllers combo box
        ui->comboBox_controller->clear();
        for(size_t i=0; i<Globals.robots[index].controllers.size(); i++)
            ui->comboBox_controller->addItem(QString::fromStdString(Globals.robots[index].controllers[i]));

        // robot versions combo box
        ui->comboBox_version->clear();
        for(size_t i=0; i<Globals.robots[index].versions.size(); i++)
            ui->comboBox_version->addItem(QString::fromStdString(Globals.robots[index].versions[i]));

    }
}

void MainWindow::on_pushButtonStopJts_clicked()
{
    simple_message::joint_traj_pt_request_message jmsg;
    for(size_t i=0; i< Globals.robots[Globals.index].maxjoints(); i++)
        jmsg.set_pos(0.0,i);

    jmsg.set_seq_number(STOP_TRAJECTORY);
    if(simple_message::swap_byte_order)
        jmsg.byte_swap();
    commandconnection->writeBytes((void *) &jmsg, sizeof(jmsg), true /*no throw*/);

}
