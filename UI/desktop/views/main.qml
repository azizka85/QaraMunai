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
    width: 640
    height: 480
    title: qsTr("Qara munai'")

    Ribbon {
        id: ribbon

        RibbonTab {
            title: qsTr("Файл")
            tabWidth: 60

            RibbonGroup {
                title: qsTr("Файл")
                width: 112

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: eclipseButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-eclipse-32x32.png"; }

                        onClicked: importDATAOFD.open()
                    }

                    Button {
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-exit-32x32.ico"; }

                        onClicked: closeProject()
                    }
                }
            }

            RibbonGroup {
                title: qsTr("Настройки")
                width: 112

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: fullScreenButton
                        width: 44
                        height: 44

                        onClicked: mainWindow.visibility = mainWindow.visibility === Window.Maximized ? "FullScreen" : "Maximized"
                    }

                    Button {
                        width: 44
                        height: 44

                        onClicked: dockTitleVisible = !dockTitleVisible
                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Карта")
            tabWidth: 80

            RibbonGroup {
                title: qsTr("Карта")

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: fieldButton
                        width: 44
                        height: 44                        

                        onClicked: {
                            if(fieldDock.visible)
                                fieldDock.hide();
                            else
                                dockSpace.insertFirst(fieldDock);
                        }
                    }
                }
            }

            RibbonGroup {
                title: qsTr("Списки")
                width: 112

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: wellScheduleButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                        onClicked: {
                            if(wellScheduleDock.visible)
                                wellScheduleDock.hide();
                            else
                                dockSpace.insertDock(wellScheduleDock, wellsListDock, Qt.Horizontal, 0.8, true);
                        }
                    }

                    Button {
                        id: wellsListButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                        onClicked: {
                            if(wellsListDock.visible)
                                wellsListDock.hide();
                            else
                                dockSpace.insertDock(wellsListDock, wellScheduleDock, Qt.Horizontal, 0.8, false);
                        }
                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Функции насыщенности")
            tabWidth: 150

            RibbonGroup {
                title: qsTr("ОФП и КД (нефть вода)")
                width: 170

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: swofButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                        onClicked: {
                            if(swofChartDock.visible)
                                swofChartDock.hide()
                             else
                                dockSpace.insertDock(swofChartDock, swofTableDock, Qt.Vertical, 0.5, true);
                        }
                    }

                    Button {
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                        onClicked: {
                            if(swofTableDock.visible)
                                swofTableDock.hide();
                            else
                                dockSpace.insertDock(swofTableDock, swofChartDock, Qt.Vertical, 0.5);
                        }
                    }

                    Button {
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/settings_icon_32x32.png"; }

                        onClicked: swofSettingsForm.show();
                    }
                }
            }

            RibbonGroup {
                title: qsTr("ОФП и КД (газ-нефть)")
                width: 170

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: sgofButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                        onClicked: {
                            if(sgofChartDock.visible)
                                sgofChartDock.hide();
                            else
                                dockSpace.insertDock(sgofChartDock, sgofTableDock, Qt.Vertical, 0.5, true);
                        }
                    }

                    Button {
                        id: sgofTableButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                        onClicked: {
                            if(sgofTableDock.visible)
                                sgofTableDock.hide();
                            else
                                dockSpace.insertDock(sgofTableDock, sgofChartDock, Qt.Vertical, 0.5);
                        }
                    }

                    Button {
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/settings_icon_32x32.png"; }

                        onClicked: {
                            sgofSettingsForm.prepare(sgofChart);
                            sgofSettingsForm.show();
                        }
                    }
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

                        swofSettingsForm.prepare(swofChart);
                        sgofSettingsForm.prepare(sgofList);
                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Свойства пластовой жидкости")
            tabWidth: 200

            RibbonGroup {
                title: qsTr("PVT нефти")
                width: 170

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: pvtoButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                        onClicked: {
                            if(pvtoChartDock.visible)
                                pvtoChartDock.hide();
                            else
                                dockSpace.insertDock(pvtoChartDock, pvtoTableDock, Qt.Vertical, 0.5, true);
                        }
                    }

                    Button {
                        id: pvtoTableButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                        onClicked: {
                            if(pvtoTableDock.visible)
                                pvtoTableDock.hide();
                            else
                                dockSpace.insertDock(pvtoTableDock, pvtoChartDock, Qt.Vertical, 0.5);
                        }
                    }

                    Button {
                        checkable: true
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/settings_icon_32x32.png"; }

                        onClicked: settingsForm.show();
                    }
                }
            }

            RibbonGroup {
                title: qsTr("PVT газа")
                width: 170

                Row {
                    spacing: 6
                    leftPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    Button {
                        id: pvtgButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                        onClicked: {
                            if(pvtgChartDock.visible)
                                pvtgChartDock.hide();
                            else
                                dockSpace.insertDock(pvtgChartDock, pvtgTableDock, Qt.Vertical, 0.5, true);
                        }
                    }

                    Button {
                        id: pvtgTableButton
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                        onClicked: {
                            if(pvtgTableDock.visible)
                                pvtgTableDock.hide();
                            else
                                dockSpace.insertDock(pvtgTableDock, pvtgChartDock, Qt.Vertical, 0.5);
                        }
                    }

                    Button {
                        checkable: true
                        width: icon.width + 12
                        height: icon.height + 12
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/settings_icon_32x32.png"; }

                        onClicked: settingsForm.show();
                    }
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

            wellSchedule.prepare(projectData);
            wellsList.prepare(projectData);

            loaderDialog.text = "Идет обработка данных";
        }

        onDataProcessed: {

            field.prepare(projectData);

            loaderDialog.close();
        }
    }

    FileDialog {
        id: importDATAOFD
        title: qsTr("Открыть Eclipse файл")
        folder: Qt.resolvedUrl("./")
        nameFilters: qsTr("DATA files(*.DATA)|*.DATA")

        onAccepted: {
            closeProject();

            loaderDialog.open();
            loaderDialog.text = "Идет загрузка данных";

            projectReader.load(eclipseReader, projectData, importDATAOFD.fileUrl.toString().replace("file:///", ""));
        }
    }

    Popup {
        property alias text: loaderText.text

        id: loaderDialog
        width: 150
        height: 150
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Text {
            id: loaderText
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12            
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

            FieldView { id: field; anchors.fill: parent; projectData: projectData }
        }

        DockControl {
            id: swofChartDock
            dockTitle: qsTr("Графики - Функции насыщенности - нефть-вода")
            titleVisible: dockTitleVisible

            SWOFChartView { id: swofChart; anchors.fill: parent; }
        }

        DockControl {
            id: swofTableDock
            dockTitle: qsTr("Таблица - Функции насыщенности - нефть-вода")
            titleVisible: dockTitleVisible

            SWOFTableView { id: swofTable; anchors.fill: parent; }
        }

        DockControl {
            id: sgofChartDock
            dockTitle: qsTr("Графики - Функции насыщенности - газ-нефть")
            titleVisible: dockTitleVisible

            SGOFChartView { id: sgofChart; anchors.fill: parent; }
        }

        DockControl {
            id: sgofTableDock
            dockTitle: qsTr("Таблица - Функции насыщенности - газ-нефть")
            titleVisible: dockTitleVisible

            SGOFTableView { id: sgofTable; anchors.fill: parent; }
        }

        DockControl {
            id: pvtoChartDock
            dockTitle: qsTr("Графики - Свойства пластовой жидкости - нефть")
            titleVisible: dockTitleVisible

            PVTOChartView { id: pvtoChart; anchors.fill: parent; }
        }

        DockControl {
            id: pvtoTableDock
            dockTitle: qsTr("Таблица - Свойства пластовой жидкости - нефть")
            titleVisible: dockTitleVisible

            PVTOTableView { id: pvtoTable; anchors.fill: parent; }
        }

        DockControl {
            id: pvtgChartDock
            dockTitle: qsTr("Графики - Свойства пластовой жидкости - газ")
            titleVisible: dockTitleVisible

            PVTGChartView { id: pvtgChart; anchors.fill: parent; }
        }

        DockControl {
            id: pvtgTableDock
            dockTitle: qsTr("Таблица - Свойства пластовой жидкости - газ")
            titleVisible: dockTitleVisible

            PVTGTableView { id: pvtgTable; anchors.fill: parent; }
        }

        DockControl {
            id: wellScheduleDock
            dockTitle: qsTr("Расписание скважин")
            titleVisible: dockTitleVisible

            WellScheduleView { id: wellSchedule; anchors.fill: parent; }
        }

        DockControl {
            id: wellsListDock
            dockTitle: qsTr("Список скважин")
            titleVisible: dockTitleVisible

            WellsListView { id: wellsList; anchors.fill: parent; }
        }
    }

    SettingsView {
        id: sgofSettingsForm
        visible: false
    }

    SettingsView {
        id: swofSettingsForm
        visible: false
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

        pvtgChart.closeProject();
        pvtgTable.closeProject();

        wellSchedule.closeProject();
        wellsList.closeProject();

        field.closeProject();

        sfRegionList.model = [];
        pvtRegionList.model = [];

        projectData.initVariables();       
    }        
}
