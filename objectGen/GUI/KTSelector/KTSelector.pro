#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T15:02:59
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += -I ../../../AutoGen -I ../../include
TARGET = KTSelector
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    ../../src/usarSimInf.cpp \
    ../../src/ulapi.cpp \
    ../../src/recurseLocation.cpp \
    ../../src/partsTrayModel.cpp \
    ../../src/partModel.cpp \
    ../../src/kitTrayModel.cpp \
    ../../src/genericModel.cpp

HEADERS  += dialog.h 

FORMS    += dialog.ui

OTHER_FILES +=

unix|win32: LIBS += -L ../../../AutoGen -lsqlKit -lmysqlcppconn 
