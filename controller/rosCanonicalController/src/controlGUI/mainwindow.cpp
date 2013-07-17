#include "controlGUI/mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <QString>
#include <QPushButton>
#include <QScrollBar>
#include <QFileDialog>
#include <QListWidgetItem>
#include <ctime>

/**
  @brief The main loop for the canonical controller thread
  
  See similar implementation in canonicalController.cpp for details
*/
void RosCanonicalThread::run()
{
  int errReturn = 0;
  while(ros::ok() && running)
  {
  	  while(errReturn == 0)
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
  	  if(errReturn == 0) //processed at least one message succesfully
  	  {
  	  	if(!initialized)
  	  	{
  	  	  Q_EMIT rosInit();
  	  	}
  	  	initialized = true;
  	  }
  	  else if(errReturn == -1)
  	  {
  	    //no command to process
  	  }
  	  else if(errReturn == 1)
  	  {
  	  	printf("Error in command queue.\n");
  	  	ros::shutdown();
  	  	return;
  	  }
	  ros::spinOnce();
  }
}
/**
  @brief Initializes the controller pointers for the canonical control thread
  @param control Pointer to the canonical controller
  @param rosControl Pointer to the ROS interface
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
  @brief Flags the thread to exit the dequeueing loop
*/
void RosCanonicalThread::stopThread()
{
  running = false;
}
/**
  @brief Constructor
  @param parent Handle to the parent widget, if any
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
  
}
/**
  @brief Destructor
*/
MainWindow::~MainWindow()
{
  delete ui;
}
/**
  @brief Stops canonical thread and clean up controllers
  @param event The window close event.
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
  @brief Updates the list of independently controlled effectors in the list on the left side of the window.
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
  @brief Sets the goal state of the selected effector in the list to "open".
  
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
  @brief Sets the goal state of the selected effector in the list to "closed"
  
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
  @brief Loads in a ROS parameter, initialize the ROS controller, and start the dequeueing thread
*/
void MainWindow::initRosNode()
{    
    //ROS configuration
    std::string globalFrame;
    ros::init(ros::VP_string(), "canonicalControllerGui");
    ros::start();
    ros::NodeHandle nh;
    if(!nh.getParam("usarsim/globalFrame", globalFrame))
    {
      ROS_INFO("No global frame parameter specified, using default /odom");
      globalFrame = "/odom";
    }
    
    rosControl = new RosInf();
    ctrl = new Controller();
    rosControl->setGlobalFrame(globalFrame);
    
    rosThread.setupController(ctrl, rosControl);
    rosThread.start();
    
    nodeStarted = true;
}
/**
  @brief Sends the canonical command in the command line to the controller
  
  Rather than rewriting the command parser to interpret strings, this method is implemented by:
  1. Writing the command to a temporary file
  2. Reading and parsing the file
  3. Removing the temporary file
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
  
}
/**
  @brief Set up the list of independent effectors
*/
void MainWindow::setupRosUI()
{    
  refreshEffectors();
  
  ui->openButton->setEnabled(true);
  ui->closeButton->setEnabled(true);
  ui->refreshButton->setEnabled(true);
}
/**
  @brief Bring up a file dialog to open a CRCL file to parse and run
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
  @brief Set the command line text (used by the drop-down box to fill in common CRCL commands)
  @param text The text to set the command line to
*/
void MainWindow::fillCommandLine(const QString &text)
{
  ui->commandLine->setText(text);
}
