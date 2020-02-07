include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT += core
QT -= gui

TARGET = Solver
TEMPLATE = lib

DEFINES += SOLVER_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += sources \
                sources/Computation \
                ../Model/sources \
                ../Model/sources/DAO \
                ../Model/sources/Domain/Grid \
                ../Model/sources/Domain/Project \
                ../Model/sources/Domain/Stratum \
                ../Model/sources/Utils \
                ../Model/sources/Helpers \
                ../Model/sources/Helpers/Eclipse

SOURCES += \
    sources/Computation/blackoilcomputation.cpp

HEADERS += \
    sources/Computation/blackoilcomputation.h \
    sources/Computation/icomputation.h \
    sources/solver_global.h

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lModel
