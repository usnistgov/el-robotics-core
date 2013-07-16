#include "mainwindow.h"
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

/*
  The main loop for the canonical controller thread.
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
/*
  Initialize the controller pointers for the canonical control thread
*/
void
RosCanonicalThread::setupController(Controller *control, RosInf* rosControl)
{
  running = true;
  initialized = false;
  ctrl = control;
  this->rosControl = rosControl;
}
/*
  Flag the thread to exit the dequeueing loop
*/
void RosCanonicalThread::stopThread()
{
  running = false;
}
/*
  Constructor for main canonical GUI window
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

MainWindow::~MainWindow()
{
  delete ui;
}
/*
  Stop canonical thread and clean up controllers
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
/*
  Update the list of independently controlled effectors in the list on the left side of the window
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
/*
  Set the goal state of the selected effector in the list to "open"
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
/*
  Set the goal state of the selected effector in the list to "closed"
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
/*
  Load in a ROS parameter, initialize the ROS controller, and start the dequeueing thread
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
/*
  send the canonical command in the command line to the controller
*/
void MainWindow::sendCanonicalCommand()
{
  //ROS node may not be started yet, start it now
  if(!nodeStarted)
    initRosNode();

  /*rather than rewriting the command parser to interpret strings, we:
  1. Write the command to a temporary file
  2. Read and parse the file
  3. Remove the temporary file
  */
  
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
  updateCurrentCommandText();
  
}
/*
  Set up the list of independent effectors
*/
void MainWindow::setupRosUI()
{    
  refreshEffectors();
  
  ui->openButton->setEnabled(true);
  ui->closeButton->setEnabled(true);
  ui->refreshButton->setEnabled(true);
}
/*
  Bring up a file dialog to open a CRCL file to parse and run
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
    updateCurrentCommandText();
  }
   
}
/*
  Set the command line text (used by the drop-down box to fill in common CRCL commands)
*/
void MainWindow::fillCommandLine(const QString &text)
{
  ui->commandLine->setText(text);
}
