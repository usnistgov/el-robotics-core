#include "dialog.h"
#include "ui_dialog.h"
#include "qdir.h"

#include "database/DAO.h"
#include <string>
#include <stdlib.h>
#include <stdio.h> // printf
#include "database/DAO.h"
#include "database/KitTray.h"
#include "database/Part.h"
#include "database/PartsTray.h"
#include "recurseLocation.h"
#include "kitTrayModel.h"
#include "partModel.h"
#include "partsTrayModel.h"
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

void Dialog::generateScene(){
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
        KitTrayModel kitTrayModel;
        PartModel partModel;
        PartsTrayModel partsTrayModel;
        std::string USARModel;
        std::map<std::string, std::vector<std::string> > results;
        DAO* dao = new DAO("Part");
        std::vector<std::string> attributes;
        int permanent = 0;

        attributes.push_back("_NAME");

        // get the name of all of the partstrays
        results = dao->getAll(attributes, "PartsTray");
        for(unsigned int i=0; i<results["_NAME"].size();i++)
        {
            myPart = results["_NAME"][i];
            //      testPart  = new Part(myPart);
            partsTray->get(myPart);
            partsTrayModel.setPartsTray(partsTray);
            USARModel = partsTrayModel.getModel();


            /*   printf( "partsTrayid for %s is %d with serial %s and model \"%s\"\n",
                    myPart.c_str(), partsTray->getPartsTrayID(),
                    partsTray->gethasPartsTray_SerialNumber().c_str(),
                    USARModel.c_str());
            */
            recurseLocation.clear();
            recurseLocation.recurse(partsTray);
            recurseLocation.computeGlobalLoc();
            usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
                                 permanent );
        }

        // get the name of all of the kitTrays
        results = dao->getAll(attributes, "KitTray");

        myPart = ui->comboKittray->currentText().toStdString();
        kitTray->get(myPart);
        kitTrayModel.setKitTray(kitTray);
        USARModel = kitTrayModel.getModel();
        recurseLocation.clear();
        recurseLocation.recurse(kitTray);
        recurseLocation.computeGlobalLoc();
        usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
                             permanent);


        // get the name of all of the parts
        results = dao->getAll(attributes, "Part");
        for(unsigned int i=0; i<results["_NAME"].size();i++)
        {
            myPart = results["_NAME"][i];
            testPart->get(myPart);
            partModel.setPart(testPart);
            USARModel = partModel.getModel();
            recurseLocation.clear();
            recurseLocation.recurse(testPart);
            recurseLocation.computeGlobalLoc();
            usarsim.placeObject( USARModel, myPart, recurseLocation.getGlobalLoc(),
                                 permanent);
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
