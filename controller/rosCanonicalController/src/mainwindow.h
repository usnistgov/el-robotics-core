#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QThread>
#include <vector>
#include <string>
#include "rosInf.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"

namespace Ui {

class MainWindow;
}
/*
  Main thread class for the canonical controller dequeueing loop, based on a QThread
*/
class RosCanonicalThread : public QThread
{

    Q_OBJECT

public:
  void run();
  void setupController(Controller* control, RosInf* rosControl);  
  void stopThread();
private:
  Controller *ctrl;
  bool initialized;
  RosInf *rosControl;
  bool running;
Q_SIGNALS:
  void rosInit();
};
/*
  The main Qt window class for the application
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *event);
  
private:
    Ui::MainWindow *ui;
    
    Controller *ctrl;
    bool nodeStarted;
    CommandParser parser;
    RosInf *rosControl;
    RosCanonicalThread rosThread;
    std::vector<std::string> statusTopics;
    
    void initRosNode();

public Q_SLOTS:
    void closeSelectedEffector();
    void fillCommandLine(const QString &text);
    void openSelectedEffector();
    void openFile();
    void refreshEffectors();
    void sendCanonicalCommand();
    void setupRosUI();
};

#endif // MAINWINDOW_H
