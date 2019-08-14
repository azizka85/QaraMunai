import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QaraMunai.Model.Domain.Project 1.0
import QaraMunai.Model.DAO 1.0

ApplicationWindow {
    property bool dockTitleVisible: true

    id: mainWindow
    visible: true
    visibility: "Maximized"
    title: qsTr("Qara munai'")

    Ribbon {
        id: ribbon

        RibbonTab {
            title: qsTr("Файл")
            tabWidth: 60

            RibbonGroup {
                title: qsTr("Файл")
                width: 112

                Button {
                    id: eclipseButton
                    anchors { left: parent.left; /*top: parent.top;*/ margins: 6; verticalCenter: parent.verticalCenter }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-eclipse-32x32.png"; }

                    onClicked: importDATAOFD.open()
                }

                Button {
                    anchors { left: eclipseButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-exit-32x32.ico"; }

                    onClicked: closeProject()
                }
            }

            RibbonGroup {
                title: qsTr("Настройки")
                width: 112

                Button {
                    id: fullScreenButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: 44
                    height: 44

                    onClicked: mainWindow.visibility = mainWindow.visibility === Window.Maximized ? "FullScreen" : "Maximized"
                }

                Button {
                    anchors { left: fullScreenButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: 44
                    height: 44

                    onClicked: dockTitleVisible = !dockTitleVisible
                }
            }
        }

        RibbonTab {
            title: qsTr("Карта")
            tabWidth: 80

            RibbonGroup {
                title: qsTr("Карта")
                width: 62

                Button {
                    id: fieldButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: 44
                    height: 44

                    onClicked:
                        if(fieldDock.visible)
                            fieldDock.hide();
                        else
                            dockSpace.insertDock(fieldDock, wellscheduleDock);
                }
            }
            
            RibbonGroup {
                title: qsTr("Списки")
                width: 150

                Button {
                    id: welsScheduleButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked: {
                        wellschedule.prepare(projectData);
                        if(wellscheduleDock.visible)
                            wellscheduleDock.hide()
                        else
                            dockSpace.insertDock(wellscheduleDock, fieldDock)
                    }
                }

                Button {
                    id: welsListButton
                    anchors { left: welsScheduleButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked: {
                        wellsList.prepare(projectData);
                        if(wellsListDock.visible)
                            wellsListDock.hide()
                        else
                            dockSpace.insertDock(wellsListDock, fieldDock)
                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Функции насыщенности")
            tabWidth: 150

            RibbonGroup {
                title: qsTr("ОФП и КД (нефть вода)")
                width: 140

                Button {
                    id: swofButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked: if(swofChartDock.visible)
                                   swofChartDock.hide()
                                else
                                   dockSpace.insertDock(swofChartDock, swofTableDock, Qt.Vertical, 0.5, true)
                }

                Button {
                    anchors { left: swofButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                    onClicked: if(swofTableDock.visible)
                                   swofTableDock.hide();
                                else
                                    dockSpace.insertDock(swofTableDock, swofChartDock, Qt.Vertical, 0.5);
                }
            }

            RibbonGroup {
                title: qsTr("ОФП и КД (газ-нефть)")
                width: 140

                Button {
                    id: sgofButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked: if(sgofChartDock.visible)
                                    sgofChartDock.hide();
                                else
                                    dockSpace.insertDock(sgofChartDock, sgofTableDock, Qt.Vertical, 0.5, true);
                }

                Button {
                    anchors { left: sgofButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                    onClicked: if(sgofTableDock.visible)
                                    sgofTableDock.hide();
                                else
                                    dockSpace.insertDock(sgofTableDock, sgofChartDock, Qt.Vertical, 0.5);
                }
            }

            RibbonGroup {
                title: qsTr("Регионы")
                width: 62

                ComboBox {
                    id: sfRegionList
                    anchors { left: parent.left; right: parent.right; verticalCenter: parent.verticalCenter; margins: 5 }
                    font.pixelSize: 14

                    onCurrentIndexChanged: {

                        var swofList = projectData.swof.getList(sfRegionList.currentIndex);
                        var sgofList = projectData.sgof.getList(sfRegionList.currentIndex);

                        swofChart.prepare(swofList);
                        swofTable.prepare(swofList);

                        sgofChart.prepare(sgofList);
                        sgofTable.prepare(sgofList);

                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Свойства пластовой жидкости")
            tabWidth: 200
            RibbonGroup {
                title: qsTr("PVT нефти")
                width: 140
                Button {
                    id: pvtoButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked:  if(pvtoChartDock.visible)
                                    pvtoChartDock.hide();
                                else
                                    dockSpace.insertDock(pvtoChartDock, pvtoTableDock, Qt.Vertical, 0.5, true)
                }

                Button {
                    anchors { left: pvtoButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                    onClicked:  if(pvtoTableDock.visible)
                                    pvtoTableDock.hide();
                                else
                                    dockSpace.insertDock(pvtoTableDock, pvtoChartDock, Qt.Vertical, 0.5)
                }
            }

            RibbonGroup {
                title: qsTr("PVT газа")
                width: 140
                Button {
                    id: pvtgButton
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked:  if(pvtgChartDock.visible)
                                    pvtgChartDock.hide();
                                else
                                    dockSpace.insertDock(pvtgChartDock, pvtgTableDock, Qt.Vertical, 0.5, true)
                }

                Button {
                    anchors { left: pvtgButton.right; verticalCenter: parent.verticalCenter; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                    onClicked:  if(pvtgTableDock.visible)
                                    pvtgTableDock.hide();
                                else
                                    dockSpace.insertDock(pvtgTableDock, pvtgChartDock, Qt.Vertical, 0.5)
                }
            }

            RibbonGroup {
                title: qsTr("Регионы")
                width: 62

                ComboBox {
                    id: pvtRegionList
                    anchors { left: parent.left; right: parent.right; verticalCenter: parent.verticalCenter; margins: 5 }
                    font.pixelSize: 14

                    onCurrentIndexChanged: {

                        var pvtoList = projectData.pvto.getList(pvtRegionList.currentIndex);
                        var pvtgList = projectData.pvtg.getList(pvtRegionList.currentIndex);

                        pvtoChart.prepare(pvtoList);
                        pvtoTable.prepare(pvtoList);

                        pvtgChart.prepare(pvtgList);
                        pvtgTable.prepare(pvtgList);

                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Расчётные данные")
            tabWidth: 130
        }

        RibbonTab {
            title: qsTr("Консоль")
            tabWidth: 100
        }
    }

    ProjectData {
        id: projectData
    }

    EclipseFileReader {
        id: eclipseReader
    }

    AsyncFileReader {
        id: projectReader
        onLoadComplete: {

            mainWindow.title = projectData.title;

            sfRegionList.model = createNumberArray(projectData.tabDIMS.ntSFUN);
            pvtRegionList.model = createNumberArray(projectData.tabDIMS.ntPVT);

            loaderDialog.close();
        }
    }

    FileDialog {
        id: importDATAOFD
        title: qsTr("Открыть Eclipse файл")
        folder: Qt.resolvedUrl("./")
        nameFilters: "DATA files(*.DATA)|*.DATA"

        onAccepted: {
            closeProject();
            loaderDialog.open();
            projectReader.load(eclipseReader, projectData, importDATAOFD.fileUrl.toString().replace("file:///", ""))
        }
    }

    Popup {
        id: loaderDialog
        width: 150
        height: 150
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Text {
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
            text: qsTr("Идет загрузка данных")
        }

        AnimatedImage {
            anchors.centerIn: parent
            source: "qrc:/mobile/images/icon-waiting.gif"
        }

        Text {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 16
            text: qsTr("Подождите...")
        }
    }

    DockSpace {
        id: dockSpace
        anchors { left: parent.left; right: parent.right; top: ribbon.bottom; bottom: parent.bottom }

        DockControl {
            id: fieldDock
            dockTitle: qsTr("Поле")
            titleVisible: dockTitleVisible

            FieldView { id: field; anchors.fill: parent; }
        }
    }

    DockControl {
        id: swofChartDock
        visible: false
        dockTitle: qsTr("Графики - Функции насыщенности - нефть-вода")
        titleVisible: dockTitleVisible

        SWOFChartView { id: swofChart; anchors.fill: parent; }
    }

    DockControl {
        id: swofTableDock
        visible: false
        dockTitle: qsTr("Таблица - Функции насыщенности - нефть-вода")
        titleVisible: dockTitleVisible

        SWOFTableView { id: swofTable; anchors.fill: parent; }
    }

    DockControl {
        id: sgofChartDock
        visible: false
        dockTitle: qsTr("Графики - Функции насыщенности - газ-нефть")
        titleVisible: dockTitleVisible

        SGOFChartView { id: sgofChart; anchors.fill: parent; }
    }

    DockControl {
        id: sgofTableDock
        visible: false
        dockTitle: qsTr("Таблица - Функции насыщенности - газ-нефть")
        titleVisible: dockTitleVisible

        SGOFTableView { id: sgofTable; anchors.fill: parent; }
    }

    DockControl {
        id: pvtoChartDock
        visible: false
        dockTitle: qsTr("Графики - Свойства пластовой жидкости - нефть")
        titleVisible: dockTitleVisible

        PVTOChartView { id: pvtoChart; anchors.fill: parent; }
    }

    DockControl {
        id: pvtoTableDock
        visible: false
        dockTitle: qsTr("Таблица - Свойства пластовой жидкости - нефть")
        titleVisible: dockTitleVisible

        PVTOTableView { id: pvtoTable; anchors.fill: parent; }
    }

    DockControl {
        id: pvtgChartDock
        visible: false
        dockTitle: qsTr("Графики - Свойства пластовой жидкости - газ")
        titleVisible: dockTitleVisible

        PVTGChartView { id: pvtgChart; anchors.fill: parent; }
    }

    DockControl {
        id: pvtgTableDock
        visible: false
        dockTitle: qsTr("Таблица - Свойства пластовой жидкости - газ")
        titleVisible: dockTitleVisible

        PVTGTableView { id: pvtgTable; anchors.fill: parent; }
    }

    DockControl {
        id: wellscheduleDock
        visible: false
        dockTitle: qsTr("Расписание скважин")
        titleVisible: dockTitleVisible

        WellScheduleView { id: wellschedule; anchors.fill: parent; }
    }

    DockControl {
        id: wellsListDock
        visible: false
        dockTitle: qsTr("Список скважин")
        titleVisible: dockTitleVisible

        WellScheduleView { id: wellsList; anchors.fill: parent; }
    }


    function createNumberArray(length)
    {
        var items = [];
        for(var i = 0; i < length; i++) items[i] = i+1;
        return items;
    }

    function closeProject()
    {
        mainWindow.title =  qsTr("Qara munai'");

        swofChart.closeProject();
        swofTable.closeProject();

        sgofChart.closeProject();
        sgofTable.closeProject();

        pvtoChart.closeProject();
        pvtoTable.closeProject();

        wellschedule.closeProject();

        sfRegionList.model = [];
        pvtRegionList.model = [];

        projectData.initVariables();
    }
}
