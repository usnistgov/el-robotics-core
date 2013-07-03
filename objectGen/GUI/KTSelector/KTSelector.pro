#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T15:02:59
#
#-------------------------------------------------

QT       += core gui

INCPATH += -I ../../../AutoGen
TARGET = KTSelector
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    usarSimInf.cpp \
    ulapi.cpp \
    recurseLocation.cpp \
    partsTrayModel.cpp \
    partModel.cpp \
    kitTrayModel.cpp \
    genericModel.cpp

HEADERS  += dialog.h \
    usarSimInf.h \
    ulapi.hh \
    recurseLocation.h \
    partsTrayModel.h \
    partModel.h \
    kitTrayModel.h \
    genericModel.h

FORMS    += dialog.ui

OTHER_FILES +=

unix|win32: LIBS += -L ../../../AutoGen -lsqlKit -lmysqlcppconn 
