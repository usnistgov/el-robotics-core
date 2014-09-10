INCLUDEPATH += -I ../../../AutoGen -I ../../include -I ../../../objectGen/include


HEADERS += \
    ../../include/usarTruth.hh \
    ../../include/ulapi.hh \
    ../../include/parseUtils.h \
    ../../include/gui.h \
    ../../include/partModel.h \
    ../../include/genericModel.h \
    ../../include/recurseLocation.h


SOURCES += \
    ../../src/usarTruth.cpp \
    ../../src/updateDB.cpp \
    ../../src/parseUtils.cpp \
    ../../src/ulapi.cpp \
    ../../../objectGen/src/partModel.cpp \
    ../../../objectGen/src/genericModel.cpp \
    ../../../objectGen/src/recurseLocation.cpp
LIBS += -L ../../../AutoGen -lsqlKit -lmysqlcppconn

