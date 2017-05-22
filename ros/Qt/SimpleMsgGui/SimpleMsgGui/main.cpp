#include "mainwindow.h"
#include <stdlib.h>

#include <QApplication>
#include <QSettings>
#include <QMessageBox>
#include <QCloseEvent>

#include "NIST/Globals.h"
#include "simple_message_defs.h"

CGlobals Globals;
MainWindow * mainwin;
int simple_message::swap_byte_order=false;

std::vector<std::string> ParseQVariant(QVariant & value)
{
    std::vector<std::string> values;
    if (value.type() == QVariant::StringList) {
        QStringList list(value.toStringList());
        foreach( QString str, list) {
            values.push_back(str.toStdString());
        }
    } else {
        values.push_back( value.toString().toStdString());
    }
    qDebug("ParseQ %s\n", Globals.VectorDump<std::string>(values).c_str());
    return values;
}
std::vector<float> ParseQVariantNumbers(QVariant & value)
{
    std::vector<float> values;
    if (value.type() == QVariant::StringList) {
        QStringList list(value.toStringList());
        foreach( QString str, list) {
            values.push_back(str.toFloat());
        }
    } else {
        values.push_back( value.toFloat());
    }
    qDebug("ParseQ %s\n", Globals.VectorDump<float>(values).c_str());
    return values;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mainwin=&w;
    //w.demo->PingHost("grandfloria");

#if 0
    ros::init(argc, &argv[0], ROSPACKAGENAME);

    // Check if master running if not abort with dialog
    if(! ros::master::check())
    {
        //QMessageBox msgBox;
        //msgBox.setText("ROS Master Not Running - Aborting.");
        //msgBox.exec();
        QMessageBox::critical(NULL, QObject::tr("ROS GUI"),
                              QObject::tr("ROS Master Not Running - Aborting"),
                              QMessageBox::Ok, 0);
        QApplication::quit(); // think this only set GUI thread  flag
        //        QCloseEvent event;
        //        w.closeEvent(&event);
        return 0;

    }
    // Check the environment variables are set.
    char* masterURI=NULL;
    masterURI = getenv("ROS_MASTER_URI");
    if (masterURI==NULL)
    {
        QMessageBox::critical(NULL, QObject::tr("ROS GUI"),
                              QObject::tr("Need to set ROS environment, Maybe try source devel/setup.bash - Aborting"),
                              QMessageBox::Ok, 0);

        QApplication::quit(); // think this only set GUI thread  flag
        return 0;
    }
    QObject::connect(&w.rosThread, SIGNAL(finished()), &a, SLOT(quit()));
    w.configure();
#endif

    std::string path(argv[0]);
    Globals.ExeDirectory = path.substr(0, path.find_last_of('/') + 1);
    Globals._appproperties["ExeDirectory"] = Globals.ExeDirectory;
    qDebug( "Exe = %s\n ", Globals.ExeDirectory.c_str()  );
    qDebug( "argv[0] = %s\n ", argv[0] );

    // Parse ini file named config.ini must be in same directory as exe
    QString iniPath=QString::fromUtf8((Globals.ExeDirectory  + "config.ini").c_str());
    QSettings settings( iniPath, QSettings::IniFormat );

    // Get the names of potential robots
    QVariant value  =  settings.value( "system/robots" );
    std::vector<std::string> robots = ParseQVariant(value);

    // Parse config information from ini file for each robot
    for(size_t i=0; i<robots.size(); i++)
    {
        Globals.robots.push_back(RobotDef());
        Globals.robots[i].name=robots[i];
        // Read joint names
        QVariant jointnames =  settings.value( (robots[i] + "/joints").c_str());
        Globals.robots[i].jointnames= ParseQVariant(jointnames);

        // joint maximum positions
        QVariant jointmaxvalues =  settings.value( (robots[i] + "/jointmaxs").c_str());
        Globals.robots[i].jointmaxvalues= ParseQVariantNumbers(jointmaxvalues);

        // joint minimum positions
        QVariant jointminvalues =  settings.value( (robots[i] + "/jointmins").c_str());
        Globals.robots[i].jointminvalues = ParseQVariantNumbers(jointminvalues);

        // Read controller names
        QVariant controllernames =  settings.value( (robots[i] + "/controllers").c_str());
        Globals.robots[i].controllers = ParseQVariant(controllernames);
        QVariant controller =  settings.value( (robots[i] + "/controller").c_str());
        Globals.robots[i].controller = controller.toString().toStdString();

        // Read version names
        QVariant versionnames =  settings.value( (robots[i] + "/versions").c_str());
        Globals.robots[i].versions= ParseQVariant(versionnames);
        QVariant version =  settings.value( (robots[i] + "/version").c_str());
        Globals.robots[i].version= version.toString().toStdString();

        // Communication ip, ports and endianess - assuming we are little endian
        Globals.robots[i].cmdport=settings.value((robots[i] + "/cmdport").c_str()).toInt();
        Globals.robots[i].statusport=settings.value((robots[i] + "/statport").c_str()).toInt();
        Globals.robots[i].ip=settings.value((robots[i] + "/ip").c_str()).toString();
        Globals.robots[i].byteswap=settings.value((robots[i] + "/byteswap").c_str()).toInt();

    }
    // Pick up selection index from selected robot or assign zero?
    value  =  settings.value( "system/robot" );
    Globals.robot = value.toString().toStdString();

    w.configure();
    w.show();
//    w.rosThread.start();
    return a.exec();
}
