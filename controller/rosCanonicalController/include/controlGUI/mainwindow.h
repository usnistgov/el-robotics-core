#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controlGUI/customcontrols.h"

#include <QMainWindow>
#include <QListWidget>
#include <QThread>
#include <QLabel>
#include <QSignalMapper>
#include <vector>
#include <string>
#include <urdf/model.h>
#include "rosInf.hh"
#include "controller.hh"
#include "commandParser.hh"
#include "canonicalMsg.hh"

namespace Ui {

class MainWindow;
}
/**
  \addtogroup controlGUI
  @{

  \class RosCanonicalThread mainwindow.h
  \brief Main thread class for the canonical controller dequeueing loop.
  
  This class is based on QThread, and replaces the ulapi implementation used in the command-line
  rosCanonicalController.
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
/**
  \class MainWindow mainwindow.h
  \brief The main Qt window class for the application
  
  This class has pointers to the canonical controller objects and can queue CRCL commands, as
  well as operate end effectors directly. It can also directly send joint goals to the move_arm controller using a slider interface.
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
    std::vector<std::string> jointNames;
    std::vector<boost::shared_ptr<JointSlider> > jointSliders;
    std::vector<boost::shared_ptr<QLabel> > labels;
    std::vector<boost::shared_ptr<JointEdit> > jointEdits;
    std::vector<double> jointValues;
    std::vector<double> realJtValues;
    urdf::Model robotModel;
    ros::Subscriber jointSub;
    
    void initRosNode();
    void buildJointSliders();
    void jointCallback(const sensor_msgs::JointStateConstPtr &ptr);
    
    void deleteWidgetVector(std::vector<QWidget*>::iterator begin, std::vector<QWidget*>::iterator end);

public Q_SLOTS:
    void closeSelectedEffector();
    void fillCommandLine(const QString &text);
    void openSelectedEffector();
    void openFile();
    void saveFile();
    void refreshEffectors();
    void sendCanonicalCommand();
    void setupRosUI();
    void updateJoint(int index, double value);
    void sendJointCommand();
    void syncJointValues();
};

/** @} */

#endif // MAINWINDOW_H
