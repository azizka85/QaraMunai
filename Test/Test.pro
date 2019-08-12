include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT += core testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += sources \
                ../Model/sources \
                ../Model/sources/DAO \
                ../Model/sources/Domain/Grid \
                ../Model/sources/Domain/Project \
                ../Model/sources/Domain/Stratum \
                ../Model/sources/Utils \
                ../Model/sources/Helpers \
                ../Model/sources/Helpers/Eclipse

SOURCES +=  \
    sources/main.cpp \
    sources/testeclipsefilereader.cpp \
    sources/testutils.cpp

HEADERS += \
    sources/test.h \
    sources/testeclipsefilereader.h \
    sources/testutils.h

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lModel
