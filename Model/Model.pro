#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T10:48:25
#
#-------------------------------------------------

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

QT      += core
QT      -= gui

TARGET = Model
TEMPLATE = lib

DEFINES += MODEL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += sources \
                sources/DAO \
                sources/Domain/Grid \
                sources/Domain/Project \
                sources/Domain/Stratum \
                sources/Utils \
                sources/Helpers \
                sources/Helpers\Eclipse

SOURCES += \
    sources/DAO/asyncfilereader.cpp \
    sources/DAO/eclipsefilereader.cpp \
    sources/Domain/Grid/box1d.cpp \
    sources/Domain/Grid/box2d.cpp \
    sources/Domain/Grid/box3d.cpp \
    sources/Domain/Project/defaultvalues.cpp \
    sources/Domain/Project/projectdata.cpp \
    sources/Domain/Stratum/adddata.cpp \
    sources/Domain/Stratum/aquancondata.cpp \
    sources/Domain/Stratum/aqufetpdata.cpp \
    sources/Domain/Stratum/compdatdata.cpp \
    sources/Domain/Stratum/copydata.cpp \
    sources/Domain/Stratum/densitydata.cpp \
    sources/Domain/Stratum/dimpesdata.cpp \
    sources/Domain/Stratum/enkrvddata.cpp \
    sources/Domain/Stratum/enpcvddata.cpp \
    sources/Domain/Stratum/enspcvddata.cpp \
    sources/Domain/Stratum/equalsdata.cpp \
    sources/Domain/Stratum/equildata.cpp \
    sources/Domain/Stratum/gravitydata.cpp \
    sources/Domain/Stratum/multiplydata.cpp \
    sources/Domain/Stratum/oilvisctdata.cpp \
    sources/Domain/Stratum/pbvddata.cpp \
    sources/Domain/Stratum/pmaxdata.cpp \
    sources/Domain/Stratum/ppcwmaxdata.cpp \
    sources/Domain/Stratum/prvddata.cpp \
    sources/Domain/Stratum/pvcdodata.cpp \
    sources/Domain/Stratum/pvcodata.cpp \
    sources/Domain/Stratum/pvdgdata.cpp \
    sources/Domain/Stratum/pvdodata.cpp \
    sources/Domain/Stratum/pvtgdata.cpp \
    sources/Domain/Stratum/pvtodata.cpp \
    sources/Domain/Stratum/pvtwdata.cpp \
    sources/Domain/Stratum/rockdata.cpp \
    sources/Domain/Stratum/rsconstdata.cpp \
    sources/Domain/Stratum/rsvddata.cpp \
    sources/Domain/Stratum/sgfndata.cpp \
    sources/Domain/Stratum/sgofdata.cpp \
    sources/Domain/Stratum/sgwfndata.cpp \
    sources/Domain/Stratum/slgofdata.cpp \
    sources/Domain/Stratum/sof2data.cpp \
    sources/Domain/Stratum/sof32ddata.cpp \
    sources/Domain/Stratum/sof32dkrodata.cpp \
    sources/Domain/Stratum/sof3data.cpp \
    sources/Domain/Stratum/somgasdata.cpp \
    sources/Domain/Stratum/somwatdata.cpp \
    sources/Domain/Stratum/specheatdata.cpp \
    sources/Domain/Stratum/specrockdata.cpp \
    sources/Domain/Stratum/stratumdata.cpp \
    sources/Domain/Stratum/swfndata.cpp \
    sources/Domain/Stratum/swofdata.cpp \
    sources/Domain/Stratum/viscrefdata.cpp \
    sources/Domain/Stratum/watvisctdata.cpp \
    sources/Domain/Stratum/wconhistdata.cpp \
    sources/Domain/Stratum/wconinjedata.cpp \
    sources/Domain/Stratum/wconinjhdata.cpp \
    sources/Domain/Stratum/wconproddata.cpp \
    sources/Domain/Stratum/welspecsdata.cpp \
    sources/Domain/Stratum/weltargdata.cpp \
    sources/Helpers/Eclipse/readfilehelper.cpp \
    sources/Helpers/unithelper.cpp \
    sources/Utils/linearmatrix2d.cpp \
    sources/Utils/linearmatrix3d.cpp \
    sources/Utils/linearvector.cpp \
    sources/Utils/subarray.cpp \
    sources/Domain/Project/endscaleentity.cpp \
    sources/Domain/Project/eqldimsentity.cpp \
    sources/Domain/Project/rockoptsentity.cpp \
    sources/Domain/Project/tabdimsentity.cpp \
    sources/Domain/Stratum/endscaledata.cpp \
    sources/Domain/Stratum/eqldimsdata.cpp \
    sources/Domain/Stratum/rockoptsdata.cpp \
    sources/Domain/Stratum/tabdimsdata.cpp \
    sources/Domain/Project/swofentity.cpp

HEADERS += \
    sources/DAO/asyncfilereader.h \
    sources/DAO/eclipsefilereader.h \
    sources/DAO/idatafilereader.h \
    sources/DAO/idatafilewriter.h \
    sources/Domain/Grid/box1d.h \
    sources/Domain/Grid/box2d.h \
    sources/Domain/Grid/box3d.h \
    sources/Domain/Project/defaultvalues.h \
    sources/Domain/Project/projectdata.h \
    sources/Domain/Stratum/adddata.h \
    sources/Domain/Stratum/aquancondata.h \
    sources/Domain/Stratum/aqufetpdata.h \
    sources/Domain/Stratum/compdatdata.h \
    sources/Domain/Stratum/copydata.h \
    sources/Domain/Stratum/densitydata.h \
    sources/Domain/Stratum/dimpesdata.h \
    sources/Domain/Stratum/enkrvddata.h \
    sources/Domain/Stratum/enpcvddata.h \
    sources/Domain/Stratum/enspcvddata.h \
    sources/Domain/Stratum/equalsdata.h \
    sources/Domain/Stratum/equildata.h \
    sources/Domain/Stratum/gravitydata.h \
    sources/Domain/Stratum/multiplydata.h \
    sources/Domain/Stratum/oilvisctdata.h \
    sources/Domain/Stratum/pbvddata.h \
    sources/Domain/Stratum/pmaxdata.h \
    sources/Domain/Stratum/ppcwmaxdata.h \
    sources/Domain/Stratum/prvddata.h \
    sources/Domain/Stratum/pvcdodata.h \
    sources/Domain/Stratum/pvcodata.h \
    sources/Domain/Stratum/pvdgdata.h \
    sources/Domain/Stratum/pvdodata.h \
    sources/Domain/Stratum/pvtgdata.h \
    sources/Domain/Stratum/pvtodata.h \
    sources/Domain/Stratum/pvtwdata.h \
    sources/Domain/Stratum/rockdata.h \
    sources/Domain/Stratum/rsconstdata.h \
    sources/Domain/Stratum/rsvddata.h \
    sources/Domain/Stratum/sgfndata.h \
    sources/Domain/Stratum/sgofdata.h \
    sources/Domain/Stratum/sgwfndata.h \
    sources/Domain/Stratum/slgofdata.h \
    sources/Domain/Stratum/sof2data.h \
    sources/Domain/Stratum/sof32ddata.h \
    sources/Domain/Stratum/sof32dkrodata.h \
    sources/Domain/Stratum/sof3data.h \
    sources/Domain/Stratum/somgasdata.h \
    sources/Domain/Stratum/somwatdata.h \
    sources/Domain/Stratum/specheatdata.h \
    sources/Domain/Stratum/specrockdata.h \
    sources/Domain/Stratum/stratumdata.h \
    sources/Domain/Stratum/swfndata.h \
    sources/Domain/Stratum/swofdata.h \
    sources/Domain/Stratum/viscrefdata.h \
    sources/Domain/Stratum/watvisctdata.h \
    sources/Domain/Stratum/wconhistdata.h \
    sources/Domain/Stratum/wconinjedata.h \
    sources/Domain/Stratum/wconinjhdata.h \
    sources/Domain/Stratum/wconproddata.h \
    sources/Domain/Stratum/welspecsdata.h \
    sources/Domain/Stratum/weltargdata.h \
    sources/Helpers/Eclipse/readfilehelper.h \
    sources/Helpers/unithelper.h \
    sources/Utils/linearmatrix2d.h \
    sources/Utils/linearmatrix3d.h \
    sources/Utils/linearvector.h \
    sources/Utils/subarray.h \
    sources/model_global.h \
    sources/Domain/Project/endscaleentity.h \
    sources/Domain/Project/eqldimsentity.h \
    sources/Domain/Project/rockoptsentity.h \
    sources/Domain/Project/tabdimsentity.h \
    sources/Domain/Stratum/endscaledata.h \
    sources/Domain/Stratum/eqldimsdata.h \
    sources/Domain/Stratum/rockoptsdata.h \
    sources/Domain/Stratum/tabdimsdata.h \
    sources/Domain/Project/swofentity.h
