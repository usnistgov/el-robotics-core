#include "controlGUI/mainwindow.h"
#include "ui_mainwindow.h"
#include "robotDescription.hh"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <QSlider>
#include <QString>
#include <QPushButton>
#include <QScrollBar>
#include <QFileDialog>
#include <QListWidgetItem>
#include <ctime>
#include <cmath>

#define DEFAULT_SLIDER_PRECISION 0.01

/**
  \brief The main loop for the canonical controller thread
  
  See similar implementation in canonicalController.cpp for details
*/
void RosCanonicalThread::run()
{
  StatusMsg errReturn;

  errReturn.setStatus(CmdComplete);
  while(ros::ok() && running)
  {
    while(errReturn.getStatus() == CmdComplete)
  	  {
  	  	errReturn = ctrl->dequeueMsgHigh(rosControl);
  	  }
  	  errReturn = ctrl->dequeueMsgLow(rosControl);
  	  while(!rosControl->checkCommandDone())
  	  {
  	    errReturn = ctrl->dequeueMsgHigh(rosControl);
  	    sleep(.1);
  	  	ros::spinOnce();
  	  }
  	  if(errReturn.getStatus() == CmdComplete) //processed at least one message succesfully
  	  {
  	  	if(!initialized)
  	  	{
  	  	  Q_EMIT rosInit();
  	  	}
  	  	initialized = true;
  	  }
  	  else if(errReturn.getStatus() == QueueEmpty)
  	  {
  	    //no command to process
  	  }
  	  else 
  	  {
	    printf("Error in command queue %s.\n", errReturn.getError());
  	  	ros::shutdown();
  	  	return;
  	  }
	  ros::spinOnce();
  }
}
/**
  \brief Initializes the controller pointers for the canonical control thread
  \param control Pointer to the canonical controller
  \param rosControl Pointer to the ROS interface
*/
void
RosCanonicalThread::setupController(Controller *control, RosInf* rosControl)
{
  running = true;
  initialized = false;
  ctrl = control;
  this->rosControl = rosControl;
}
/**
  \brief Flags the thread to exit the dequeueing loop
*/
void RosCanonicalThread::stopThread()
{
  running = false;
}
/**
  \brief Constructor
  \param parent Handle to the parent widget, if any
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  nodeStarted = false;
  
  rosControl = NULL;
  ctrl = NULL;
  
  //set up Qt signals/slots
  QObject::connect(ui->openButton, SIGNAL(clicked()), this, SLOT(openSelectedEffector()));
  QObject::connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(closeSelectedEffector()));
  QObject::connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendCanonicalCommand()));
  QObject::connect(ui->commandLine, SIGNAL(returnPressed()), this, SLOT(sendCanonicalCommand()));
  QObject::connect(ui->refreshButton, SIGNAL(clicked()), this, SLOT(refreshEffectors()));
  QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  QObject::connect(ui->loadFileButton, SIGNAL(clicked()), this, SLOT(openFile()));
  QObject::connect(&rosThread, SIGNAL(rosInit()), this, SLOT(setupRosUI()));
  QObject::connect(ui->commandChoices, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(fillCommandLine(const QString&)));
  QObject::connect(ui->actionSave_command_history, SIGNAL(triggered()), this, SLOT(saveFile()));
  
}
/**
  \brief Destructor
*/
MainWindow::~MainWindow()
{
  delete ui;
  
  if(rosControl != NULL) {
    delete rosControl;
    rosControl = NULL;
  }
  if(ctrl != NULL) {
    delete ctrl;
    ctrl = NULL;
  }
}
/**
  \brief Stops canonical thread and clean up controllers
  \param event The window close event.
*/
void MainWindow::closeEvent(QCloseEvent *event)
{
  if(rosControl != NULL)
    rosControl->shutDown();
  if(rosThread.isRunning())
  {
    rosThread.stopThread();
    rosThread.wait();
  }
}
/**
  \brief Updates the list of independently controlled effectors in the list on the left side of the window.
*/
void MainWindow::refreshEffectors()
{
  statusTopics.clear();
  rosControl->getEffectorStatusNames(statusTopics);
  
  ui->effectorList->clear();
  std::string cutoff = "/status";
  for(unsigned int i = 0;i<statusTopics.size();i++) {
    std::string name = statusTopics[i].substr(0, statusTopics[i].length() - cutoff.length());
    if(name[0] == '/')
      name = name.substr(1);
    ui->effectorList->addItem(QString(name.c_str()));
  }
}
/**
  \brief Sets the goal state of the selected effector in the list to "open".
  
  This method does not use CRCL to control the robot, but directly publishes to a ROS command topic.
*/
void MainWindow::openSelectedEffector()
{ 
  usarsim_inf::EffectorCommand command;
  command.state = usarsim_inf::EffectorCommand::OPEN;
  int row = ui->effectorList->currentRow();
  if(row != -1)
  {
    rosControl->setEffectorGoal(command, statusTopics[row]);
    rosControl->publishEffectors();
    ros::Duration(1.0).sleep();
    refreshEffectors();
  }
}
/**
  \brief Sets the goal state of the selected effector in the list to "closed"
  
  This method does not use CRCL to control the robot, but directly publishes to a ROS command topic.
*/
void MainWindow::closeSelectedEffector()
{
  usarsim_inf::EffectorCommand command;
  command.state = usarsim_inf::EffectorCommand::CLOSE;
  int row = ui->effectorList->currentRow();
  if(row != -1)
  {
    rosControl->setEffectorGoal(command, statusTopics[row]);
    rosControl->publishEffectors();
    ros::Duration(1.0).sleep();
    refreshEffectors();
  }
}
/**
  \brief Load in a ROS parameter, initialize the ROS controller, and start the dequeueing thread
*/
void MainWindow::initRosNode()
{    
  //ROS configuration
  std::string globalFrame;
  std::string robotDescription;
  
  ros::init(ros::VP_string(), "canonicalControllerGui");
  ros::start();
  ros::NodeHandle nh;
  if(!nh.getParam("usarsim/globalFrame", globalFrame))
  {
    ROS_INFO("No global frame parameter specified, using default /odom");
    globalFrame = "/odom";
  }
  if(nh.getParam("robot_description", robotDescription))
  {
    robotModel.initString(robotDescription);
  }
  jointSub = nh.subscribe("joint_states", 1, &MainWindow::jointCallback, this);

  rosControl = new RosInf();
  ctrl = new Controller();
  rosControl->setGlobalFrame(globalFrame);

  rosThread.setupController(ctrl, rosControl);
  rosThread.start();

  nodeStarted = true;
}
/**
  \brief Sends the canonical command in the command line to the controller
  
  Rather than rewriting the command parser to interpret strings, this method is implemented by:
  
  -# Writing the command to a temporary file
  -# Reading and parsing the file
  -# Removing the temporary file
  
*/
void MainWindow::sendCanonicalCommand()
{
  //ROS node may not be started yet, start it now
  if(!nodeStarted)
    initRosNode();
  
  //read the command from the command line
  QString command = ui->commandLine->text();
  
  std::stringstream sstr;
  sstr<<std::time(NULL);
  std::string filename = "tmp_canon" + sstr.str(); 
  FILE *fp = fopen(filename.c_str(), "w");
  if(fp != NULL)
  {
    fprintf(fp, "%s\n", command.toStdString().c_str());
    fclose(fp);
  }
  fp = fopen(filename.c_str(), "r");
  if(fp != NULL)
  {
    parser.readCommandFile(fp, ctrl);
    fclose(fp);
  }
  remove(filename.c_str());
  
  ui->commandHistory->addItem(command);
  //autoscroll to bottom of history
  ui->commandHistory->verticalScrollBar()->setValue(ui->commandHistory->verticalScrollBar()->maximum());
  ui->commandLine->setText("");
}
/**
  \brief Set up the list of independent effectors
*/
void MainWindow::setupRosUI()
{    
  refreshEffectors();
  buildJointSliders();
  
  ui->openButton->setEnabled(true);
  ui->closeButton->setEnabled(true);
  ui->refreshButton->setEnabled(true);
}
/**
  \brief Bring up a file dialog to open a CRCL file to parse and run
*/
void MainWindow::openFile()
{
  if(!nodeStarted)
    initRosNode();
    
  QString fileString = QFileDialog::getOpenFileName(this,
     tr("Open Canonical file"), "~", tr("All files (*)"));
  if(!fileString.isNull())
  {
    std::string filename = fileString.toStdString();
    FILE *fp;
    fp = fopen(filename.c_str(), "r");
    if(fp != NULL)
    {
      parser.readCommandFile(fp, ctrl);
      fclose(fp);
    }
    //update command history
    //read the file twice rather than interfere with parser internals
    fp = fopen(filename.c_str(), "r");
    //using TEXTSIZE defined in commandParser.hh
    char lineIn[TEXTSIZE];
    while(fgets(lineIn, TEXTSIZE, fp))
    {
      ui->commandHistory->addItem(QString(lineIn));
    }
    //autoscroll to bottom of history
    ui->commandHistory->verticalScrollBar()->setValue(ui->commandHistory->verticalScrollBar()->maximum());
  }
   
}
/**
  \brief Set the command line text (used by the drop-down box to fill in common CRCL commands)
  \param text The text to set the command line to
*/
void MainWindow::fillCommandLine(const QString &text)
{
  ui->commandLine->setText(text);
}
/**
	\brief Bring up a file dialog to save the command history into a CRCL file 
*/
void MainWindow::saveFile()
{
	//use current time as default filename
	std::stringstream sstr;
	sstr<<"uicmd"<<time(NULL)<<".txt";
	QString fileString = QFileDialog::getSaveFileName(this, tr("Save command history"), sstr.str().c_str(), tr("Text files (*.txt)"));
	if(!fileString.isNull())
	{
		std::string filename = fileString.toStdString();
		FILE *fp;
		fp = fopen(filename.c_str(), "w");
		if(fp != NULL)
		{
			for(unsigned int i = 0;i<ui->commandHistory->count();i++)
			{
				fprintf(fp, "%s\n", ui->commandHistory->item(i)->text().toStdString().c_str());
			}
			fclose(fp);
		}
	}
}
/**
  \brief Set up the slider controllers for the arm joints
  
  This method reads joint names in from the robot_description parameter, and sets up an array of linked sliders in a new tab of the GUI window. The sliders can be synced to the current real position of the arm joints.
*/
void MainWindow::buildJointSliders()
{
  ros::NodeHandle nh;
	XmlRpc::XmlRpcValue planningGroups;
	jointNames.clear();
	std::string baseLink, tipLink, actName;
  if(RobotDescription::getPlanningInfo(actName, tipLink, baseLink))
  {
    RobotDescription::getJointNames(tipLink, baseLink, jointNames);
    for(int i = 0;i<jointNames.size();i++)
    {
      //create sliders, labels, text boxes (using smart pointers)
      boost::shared_ptr<JointSlider> slider = boost::shared_ptr<JointSlider> (new JointSlider(DEFAULT_SLIDER_PRECISION, this));
      boost::shared_ptr<QLabel> label = boost::shared_ptr<QLabel>(new QLabel(QString(jointNames[i].c_str()), this));
      boost::shared_ptr<JointEdit> lineEdit = boost::shared_ptr<JointEdit>(new JointEdit(this));
      
      //so we know to delete the extra widgets at cleanup
      jointSliders.push_back(slider);
      labels.push_back(label);
      jointEdits.push_back(lineEdit);
      
      lineEdit->setMaximumWidth(50);
      ui->sliderLayout->addWidget(label.get(), i, 0);
      ui->sliderLayout->addWidget(slider.get(), i, 1);
      ui->sliderLayout->addWidget(lineEdit.get(), i, 2);
      
      //read joint limits from robot model and set sliders
      boost::shared_ptr<const urdf::Joint> jointPtr = robotModel.getJoint(jointNames[i]);
      slider->setMinimum((int) round (jointPtr->limits->lower / DEFAULT_SLIDER_PRECISION));
      slider->setMaximum((int) round (jointPtr->limits->upper / DEFAULT_SLIDER_PRECISION));
      slider->setValue (0); //assume we start at 0 (ok since sliders don't update in realtime)
      lineEdit->setLimits(jointPtr->limits->lower, jointPtr->limits->upper);
      
      lineEdit->jointIndex = i;
      slider->jointIndex = i;
      
      jointValues.push_back(0.0);
      lineEdit->setText("0.00");
      connect(slider.get(), SIGNAL(sliderMoved(int)), lineEdit.get(), SLOT(syncToSlider()));
      connect(lineEdit.get(), SIGNAL(editingFinished()), slider.get(), SLOT(syncToText()));
      connect(slider.get(), SIGNAL(updateJoint(int, double)), this, SLOT(updateJoint(int, double)));
      connect(lineEdit.get(), SIGNAL(updateJoint(int, double)), this, SLOT(updateJoint(int, double)));
    }
    ui->sendJointsButton->setEnabled(true);
    ui->syncButton->setEnabled(true);
    connect(ui->sendJointsButton, SIGNAL(clicked()), this, SLOT(sendJointCommand()));
    connect(ui->syncButton, SIGNAL(clicked()), this, SLOT(syncJointValues()));
	}
}
/**
  \brief Qt slot to update internal joint goal
*/
void MainWindow::updateJoint(int index, double value)
{
  jointValues[index] = value;
}
/**
  \brief Sends the joint goal to the ROS controller
*/
void MainWindow::sendJointCommand()
{
  rosControl->addArmJointGoal(jointValues);
}
/**
  \brief Callback for joint_state subscriber.
  
  The GUI listens to the joint_state topics in order to update slider positions to the current (real) robot positions.
*/
void MainWindow::jointCallback(const sensor_msgs::JointStateConstPtr &ptr)
{
  realJtValues.resize(jointValues.size());
  int jointsUpdated = 0;
  for(unsigned int i = 0;i<ptr->name.size();i++)
  {
    std::vector<std::string>::iterator it = std::find(jointNames.begin(), jointNames.end(), ptr->name[i]);
    if(it != jointNames.end())
    {
      int index = std::distance(jointNames.begin(), it);
      realJtValues[index] = ptr->position[i];
      if(++jointsUpdated >= realJtValues.size())
        break;
    }
  }
}
/**
  \brief Sets the joint sliders and text boxes to the real joint values
*/
void MainWindow::syncJointValues()
{
  for(unsigned int i = 0;i<realJtValues.size();i++)
  {
    jointValues[i] = realJtValues[i];
    jointSliders[i]->setJoint(realJtValues[i]);
    jointEdits[i]->setJoint(realJtValues[i]);
  }
}
