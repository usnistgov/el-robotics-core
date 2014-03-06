#include "dialog.h"
#include "ui_dialog.h"
#include "qdir.h"

#include "database/DAO.h"
#include <string>
#include <stdlib.h>
#include <stdio.h> // printf
#include "DAO.h"
#include "Kit.h"
#include "KitTray.h"
#include "Part.h"
#include "PartsTray.h"
#include "WorkTable.h"
#include "recurseLocation.h"
#include "usarSimInf.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  inputFile = "";
  ui->setupUi(this);
  std::map<std::string, std::vector<std::string> > results;
  std::vector<std::string> attributes;
  attributes.push_back("_NAME");
  DAO* dao = new DAO("KitTray");
  results = dao->getAll(attributes, "KitTray");
  for(unsigned int i=0; i<results["_NAME"].size();i++){
    ui->comboKittray->addItem(QString::fromStdString(results["_NAME"][i]));
  }
  displayed=false;
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::setInputFile(char *fileName)
{
  inputFile = fileName;
}

/* define flags for population */
#define POPULATE_PART_TRAY  0x1
#define POPULATE_KIT_TRAY   0x2
#define POPULATE_PARTS      0x4
#define POPULATE_WORK_TABLE 0x8
void Dialog::generateScene(){
  unsigned int populateFlags = 0x07;
  if(!displayed){
    displayed=true;
    QString CurrentDir = QDir::currentPath();
    //CurrentDir=CurrentDir.left(CurrentDir.length()-1)  ;
    //   CurrentDir= CurrentDir.left(CurrentDir.lastIndexOf("/"));
    if( inputFile == "" )
      CurrentDir=CurrentDir+"/robot.sh";
    else
      CurrentDir=CurrentDir+"/"+inputFile;
    system((char*)CurrentDir.toStdString().c_str());
    UsarSimInf usarsim(1,ui->textHostname->text().toStdString());
    std::string myPart = "part_b_1";
    KitTray *kitTray = new KitTray(myPart);
    Part *testPart = new Part(myPart);;
    PartsTray *partsTray = new PartsTray(myPart);
    RecurseLocation recurseLocation;
    Kit *kit = new Kit(myPart);
    std::string USARModel;
    std::map<std::string, std::vector<std::string> > results;
    DAO* dao = new DAO("Part");
    std::vector<std::string> attributes;
    int permanent = 0;
    WorkTable *workTable = new WorkTable(myPart);
    int connectToUSARSim = 1;

    attributes.push_back("_NAME");

    // get the name of all of the worktables
    if(POPULATE_WORK_TABLE&populateFlags)
      {
	results = dao->getAll(attributes, "WorkTable");
	for(unsigned int i=0; (int) i<results["_NAME"].size();i++)
	  {
	    myPart = results["_NAME"][i];
	    workTable->get(myPart);
	    //	  USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(workTable));
	    USARModel = "USARPhysObj.gear";
	    recurseLocation.clear();
	    recurseLocation.recurse(workTable);
	    recurseLocation.computeGlobalLoc();
	    if( connectToUSARSim == 0 )
	      recurseLocation.printMe(1);
	    usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
				 permanent );
	  }
      }


    // get the name of all of the partstrays
    if(POPULATE_PART_TRAY&populateFlags)
      {
	results = dao->getAll(attributes, "PartsTray");
	for(unsigned int i=0; (int) i<results["_NAME"].size();i++)
	  {
	    myPart = results["_NAME"][i];
	    partsTray->get(myPart);
	    USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(partsTray));
	    /*
	      printf( "partsTrayid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), partsTray->getPartsTrayID(),
	      partsTray->gethasPartsTray_SerialNumber().c_str(),
	      USARModel.c_str());
	    */
	    recurseLocation.clear();
	    recurseLocation.recurse(partsTray);
	    recurseLocation.computeGlobalLoc();
	    if( connectToUSARSim == 0 )
	      recurseLocation.printMe(1);
	    usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
				 permanent );
	  }
      }
    // get the name of all of the kitTrays
    //  results = dao->getAll(attributes, "KitTray");
    // try for results of kits
    if(POPULATE_KIT_TRAY&populateFlags)
      {
	results = dao->getAll(attributes, "Kit");
	for(unsigned int i=0; (unsigned int) i<results["_NAME"].size();i++)
	  //      for(unsigned int i=0; i<1;i++)
	  {
	    myPart = results["_NAME"][i];
	    kit->get(myPart);
	    kitTray = kit->gethasKit_KitTray();
	    kitTray->get(kitTray->getname());
	    USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(kitTray));

	    /*
	      printf( "kitTrayid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), kitTray->getKitTrayID(),
	      kitTray->gethasKitTray_SerialNumber().c_str(),
	      USARModel.c_str());
	    */
	    recurseLocation.clear();
	    recurseLocation.recurse(kit);
	    recurseLocation.computeGlobalLoc();
	    if( connectToUSARSim == 0 )
	      recurseLocation.printMe(1);
	    usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
				 permanent);
	  }
      }
    // get the name of all of the parts
    if(POPULATE_PARTS&populateFlags)
      {
	results = dao->getAll(attributes, "Part");
	for(unsigned int i=0; i<results["_NAME"].size();i++)
	  {
	    myPart = results["_NAME"][i];
	    //      testPart  = new Part(myPart);
	    testPart->get(myPart);
	    USARModel = GenericModel::getModel(dynamic_cast<SolidObject*>(testPart));
	    /*
	      printf( "partid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), testPart->getPartID(),
	      testPart->gethasPart_SerialNumber().c_str(),
	      USARModel.c_str());
	    */
	    recurseLocation.clear();
	    recurseLocation.recurse(testPart);
	    recurseLocation.computeGlobalLoc();
	    if( connectToUSARSim == 0 )
	      recurseLocation.printMe(1);
	    usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
				 permanent);
	    //      delete testPart;
	    //      sleep(1);
	  }
      }
  }
}
void Dialog::accept (){
  generateScene();
}

void Dialog::reject (){
  system("killall roslaunch");
  QDialog::reject();
}
