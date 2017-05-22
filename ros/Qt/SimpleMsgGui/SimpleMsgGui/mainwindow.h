#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPlainTextEdit>
#include <QActionGroup>

#include "tablevector.h"
//#include "rosthread.h"
#include "qtthreading.h"
#include "RobotDefinition.h"

namespace Ui {
class MainWindow;
}
enum MsgType { COMMAND=0, STATUS=1};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void close();
    void closeEvent(QCloseEvent *event);
    void configure();
    QtStatusConnection * statusconnection;
    QtCommandConnection * commandconnection;
    Ui::MainWindow *ui;
    std::vector<QtSocketThreadBase *> threads;

public slots:
    void Message(QString str);
    void CmdMessage(QString str);
    void TypedMessage(int t, QString str);
    void set_joint_display();
    void mycurrentRobotIndexChanged(int index);
private slots:
    void on_pushButton_pingcomputer_clicked();

    void on_pushButton_pingMsg_clicked();

    void on_pushButton_connect_clicked();


    void on_pushButton_jointmsg_clicked();

    void on_actionRadians_triggered();

    void on_actionDegrees_triggered();

    void on_actionEndianness_triggered();

    void on_actionByte_Swap_triggered();

    void on_pushButton_connect_2_clicked();

    void on_actionHex_Dump_triggered();


    void on_actionQDebug_triggered();

    void on_actionNone_triggered();

    void on_actionAll_triggered();

    void on_actionFeedback_triggered();

    void on_actionRun_triggered();

    void on_actionState_triggered();

    void on_actionReply_triggered();

     void on_pushButtonRandJts_clicked();


     void on_pushButtonStopJts_clicked();

private:
    QActionGroup * alignmentGroup ;
    QTableWidget* tableWidget;
    QTableWidget* tableWidget_2;
    QStringList m_TableHeader;
    QMenu *exitMenu;
    QMenuBar *m_menuBar;
    QTableItems tableItems;
    QTableItems jnttableItems;
    QPlainTextEdit *plainTextEdit;
    double angle_multiplier;
    std::vector<QLineEdit *> jntedits;
};

#endif // MAINWINDOW_H
