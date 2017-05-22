#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T13:20:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rcsgui
TEMPLATE = app
CONFIG += c++11

release: DESTDIR = release
debug:   DESTDIR = debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

unix{
INCLUDEPATH += /usr/include/eigen3
LIBS += -L/usr/lib  -lboost_thread -lboost_system -lboost_signals -lboost_filesystem -lboost_date_time
LIBS += -L/opt/ros/indigo/lib -lroscpp -lcpp_common -lroslib -lrosconsole -lrostime -ltf -ltf2
LIBS +=   -lxmlrpcpp -lroscpp_serialization
LIBS +=  -lrosconsole_bridge  -lrosconsole_log4cxx  -lrosconsole_backend_interface
LIBS += -lurdf -lurdfdom_sensor -lurdfdom_model_state -lurdfdom_model -lurdfdom_world
LIBS += -lactionlib -lsimple_message_dummy -lpthread
}
win32 {
#    INCLUDEPATH += "C:/Program Files/NIST/src/boost_1_54_0"
#    INCLUDEPATH += "C:/Program Files/NIST/src"
#    LIBS += -L"C:/Program Files/NIST/src/boost_1_54_0/stage/lib"
#    LIBS +=  "C:/Program Files/NIST/src/boost_1_54_0/stage/lib/libboost_date_time-mgw49-mt-d-1_54.a"
#     LIBS +=  "C:/Program Files/NIST/src/boost_1_54_0/stage/lib/libboost_filesystem-mgw49-mt-d-1_54.a"
#     LIBS +=  "C:/Program Files/NIST/src/boost_1_54_0/stage/lib/libboost_system-mgw49-mt-d-1_54.a"
#     LIBS +=   "C:/Program Files/NIST/src/boost_1_54_0/stage/lib/libboost_thread-mgw49-mt-d-1_54.a"
}

QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS += -fpermissive
QMAKE_CXXFLAGS +=-Wno-deprecated
QMAKE_CXXFLAGS +=-DROS=1
QMAKE_CXXFLAGS +=-DLINUXSOCKETS=1
QMAKE_CXXFLAGS +=-Wno-sign-compare
QMAKE_CXXFLAGS +=-std=c++11
QMAKE_CXXFLAGS +=-Wno-format-security

SOURCES += main.cpp\
        mainwindow.cpp \
    tablevector.cpp \
    qtthreading.cpp

HEADERS  += mainwindow.h \
    tablevector.h \
    NIST/Globals.h \
    simple_message_defs.h \
    qtthreading.h \
    RobotDefinition.h \
    NIST/hexdump.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    Notes.txt
