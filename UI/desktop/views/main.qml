import QtQuick 2.13
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QaraMunai.Model.Domain.Project 1.0
import QaraMunai.Model.DAO 1.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.13

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
        ribbonHeight: 94
        RibbonTab {
            title: qsTr("Файл")
            tabWidth: 60
            RibbonGroup {
                title: qsTr("Файл")
                width:  106

                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: eclipseButton
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-eclipse-32x32.png"; }
                        onClicked: importDATAOFD.open()
                    }

                    MyButton {
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-exit-32x32.ico"; }
                        onClicked: closeProject()
                    }
                }

            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("Настройки")
                width:  106
                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: fullScreenButton
                        onClicked: mainWindow.visibility = mainWindow.visibility === Window.Maximized ? "FullScreen" : "Maximized"
                    }

                    MyButton {
                        onClicked: dockTitleVisible = !dockTitleVisible
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }
        }

        RibbonTab {
            title: qsTr("Карта")
            tabWidth: 80

            RibbonGroup {
                title: qsTr("Карта")

                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: fieldButton
                        checkable: true
                        onClicked: {
                            if(fieldDock.visible)
                                fieldDock.hide();
                            else
                                dockSpace.insertFirst(fieldDock);
                        }
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("Списки")
                width:  106

                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: wellScheduleButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }
                        onClicked: {
                            if(wellScheduleDock.visible)
                                wellScheduleDock.hide();
                            else
                                dockSpace.insertDock(wellScheduleDock, wellsListDock, Qt.Horizontal, 0.2, false);
                        }
                    }

                    MyButton {
                        id: wellsListButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }
                        onClicked: {
                            if(wellsListDock.visible)
                                wellsListDock.hide();
                            else
                                dockSpace.insertDock(wellsListDock, wellScheduleDock, Qt.Horizontal, 0.2, true);
                        }
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

        }

        RibbonTab {
            title: qsTr("Функции насыщенности")
            tabWidth: 200

            RibbonGroup {
                title: qsTr("вода-Нефть-газ")
                width:  106

                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6 }

                    MyButton {
                        id: swofButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_linechart_oil_water.png"; }
                        onClicked: {
                            if(swofChartDock.visible)
                                swofChartDock.hide()
                            else
                                dockSpace.insertFirst(swofChartDock);
                        }
                    }
                    MyButton {
                        id: sgofButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_linechart_gas_oil.png"; }
                        onClicked: {
                            if(sgofChartDock.visible)
                                sgofChartDock.hide();
                            else
                                dockSpace.insertFirst(sgofChartDock);
                        }
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("Регионы")
                width: 62

                ComboBox {
                    id: sfRegionList
                    anchors { left: parent.left; right: parent.right; verticalCenter: parent.verticalCenter; margins: 5 }
                    font.pixelSize: 14
                    flat: true
                    onCurrentIndexChanged: {

                        var swofList = projectData.swof.getList(sfRegionList.currentIndex);
                        var sgofList = projectData.sgof.getList(sfRegionList.currentIndex);

                        swofChart.prepare(swofList);
                        sgofChart.prepare(sgofList);
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }
        }

        RibbonTab {
            title: qsTr("Свойства пластовой жидкости")
            tabWidth: 200

            RibbonGroup {
                title: qsTr("PVT (нефти-газа-воды)")
                width:  156

                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6

                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: pvtoButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_linechart_oil.png"; }
                        onClicked: {
                            if(pvtoChartDock.visible)
                                pvtoChartDock.hide();
                            else
                                dockSpace.insertFirst(pvtoChartDock);
                        }
                    }

                    MyButton {
                        id: pvtgButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_linechart_gas.png"; }
                        onClicked: {
                            if(pvtgChartDock.visible)
                                pvtgChartDock.hide();
                            else
                                dockSpace.insertDock(pvtgChartDock);
                        }
                    }

                    MyButton {
                        id: pvtwButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_linechart_water.png"; }
                        onClicked: {
                            if(pvtwDock.visible)
                                pvtwDock.hide();
                            else
                                dockSpace.insertFirst(pvtwDock);
                        }

                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("Регионы")
                width: 106
                MyComboBox {
                    id: pvtRegionList
                    anchors { left: parent.left; right: parent.right; verticalCenter: parent.verticalCenter; margins: 5 }
                    width: 100
                    font { pixelSize: 11 }
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

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }
        }

        RibbonTab {
            title: qsTr("Расчётные данные")
            tabWidth:  106

            RibbonGroup {
                title: qsTr("Функции расчета")
                width: 156
                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: runButton
                        checkable: true
                        onClicked: if(checked){
                                       testMdodel.next();
                                   }

                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_start_button.png"; }
                    }

                    MyButton {
                        id: pauseButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_pause_button.png"; }
                    }

                    MyButton {
                        id: stopButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/icon_stop_button.png"; }
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("")
                width: 206
                Row {
                    spacing: 6
                    leftPadding: 6
                    rightPadding: 6
                    anchors { verticalCenter: parent.verticalCenter; margins: 6; }

                    MyButton {
                        id: watercutButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/wc_eor.png" }
                        onClicked: if(waterCutDock.visible)
                                       waterCutDock.hide();
                                   else
                                       dockSpace.insertDock(waterCutDock, pvtgChartDock, Qt.Horizontal, 0.55);

                    }
                    MyButton {
                        id: flowRateButto
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/flow_rate.png" }
                        onClicked: if(flowRateDock.visible)
                                       flowRateDock.hide();
                                   else
                                       dockSpace.insertDock(flowRateDock, waterCutDock, Qt.Horizontal, 0.55);
                    }
                    MyButton {
                        id: volumeRateButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/volume_rate.png" }
                        onClicked: if(volumeRateDock.visible)
                                       volumeRateDock.hide();
                                   else
                                       dockSpace.insertDock(volumeRateDock, flowRateDock, Qt.Horizontal, 0.55);
                    }
                    MyButton {
                        id: wellPressureButton
                        checkable: true
                        icon { width: 32; height: 32; source: "qrc:/desktop/images/pavr.png" }
                        onClicked: if(wellPressureDock.visible)
                                       wellPressureDock.hide();
                                   else
                                       dockSpace.insertDock(wellPressureDock, volumeRateDock, Qt.Horizontal, 0.55);
                    }
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }

            RibbonGroup {
                title: qsTr("Результаты расчета")
                width: 500

                Slider {
                    id: slider
                    anchors { bottom: buttonsRow.top; right: parent.right; left: parent.left; bottomMargin: 6; rightMargin: 6; leftMargin: 6;  }
                    stepSize: 1;
                    from: 0
                    to: 100
                }

                Row {
                    property MyButton movePreviousButton: movePreviousButton
                    property MyButton moveNextButton: moveNextButton

                    id: buttonsRow
                    anchors { bottom: parent.bottom; bottomMargin: 6; left: parent.left; leftMargin: 6 }
                    spacing: 0

                    MyButton {
                        id: moveFirstButton
                        width: icon.width
                        height: icon.height
                        icon { width: 24; height: 24; source: "qrc:/desktop/images/move_first.png" }
                        onClicked: {
                            slider.value = slider.from;
                            movePreviousButton.checked = false;
                            moveNextButton.checked = false;
                        }

                    }
                    MyButton {
                        id: movePreviousButton
                        width: icon.width
                        height: icon.height
                        icon { width: 24; height: 24; source: "qrc:/desktop/images/move_previous.png" }
                        checkable: true

                        onCheckedChanged: {
                            if(checked) {
                                moveNextButton.checked = false;
                            }
                        }
                    }
                    MyButton {
                        id: moveNextButton
                        width: icon.width
                        height: icon.height
                        icon { width: 24; height: 24; source: "qrc:/desktop/images/move_next.png" }
                        checkable: true
                        onCheckedChanged:{
                            if(checked){
                                movePreviousButton.checked = false;
                            }
                        }
                    }
                    MyButton {
                        id: moveLastButton
                        width: icon.width
                        height: icon.height
                        icon { width: 24; height: 24; source: "qrc:/desktop/images/move_last.png" }
                        onClicked: {
                            slider.value = slider.to;
                            movePreviousButton.checked = false;
                            moveNextButton.checked = false;
                        }
                    }
                }

                SpinBox {
                    id: index
                    anchors {   left: buttonsRow.right; top: slider.bottom;
                        leftMargin: 6; rightMargin: 6; topMargin: 6  }
                    width: 100
                    from: slider.from
                    to: slider.to
                    value: slider.value
                    onValueChanged: slider.value = value
                }
            }

            RibbonSplitter { anchors { top: parent.top; bottom: parent.bottom; topMargin: 6; bottomMargin: 6 } }
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

        DockControl {
            id: swofChartDock
            dockTitle: qsTr("ОФП и КД (нефть-вода)")
            titleVisible: dockTitleVisible
            SWOFChartView { id: swofChart; anchors.fill: parent;}
        }

        DockControl {
            id: sgofChartDock
            dockTitle: qsTr("ОФП и КД (газ-нефть)")
            titleVisible: dockTitleVisible
            SGOFChartView { id: sgofChart; anchors.fill: parent}
        }

        DockControl {
            id: pvtoChartDock
            dockTitle: qsTr("PVT нефти")
            titleVisible: dockTitleVisible
            PVTOChartView { id: pvtoChart; anchors.fill: parent;}
        }

        DockControl {
            id: pvtgChartDock
            dockTitle: qsTr("PVT газа")
            titleVisible: dockTitleVisible
            PVTGChartView { id: pvtgChart; anchors.fill: parent;}
        }

        DockControl {
            id: pvtwDock
            PVTWView { id: pvtwTable;anchors.fill: parent;}
        }

        DockControl {
            id: waterCutDock
            titleVisible: false
            WaterCutView { id: waterCut; anchors.fill: parent;}
        }
        DockControl {
            id: flowRateDock
            titleVisible: false
            FlowRateView { id: flowRate; anchors.fill: parent;}
        }
        DockControl {
            id: volumeRateDock
            titleVisible: false
            VolumeRateView { id: volumeRate; anchors.fill: parent;}
        }
        DockControl {
            id: wellPressureDock
            titleVisible: false
            WellPressureView { id: wellPressure; anchors.fill: parent;}
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

    function createNumberArray(length)
    {
        var items = [];
        for(var i = 0; i < length; ++i) items[i] = i+1;
        return items;
    }

    function closeProject()
    {
        mainWindow.title =  qsTr("Qara munai'");

        swofChart.closeProject();
        //swofTable.closeProject();

        sgofChart.closeProject();
        //sgofTable.closeProject();

        pvtoChart.closeProject();

        //pvtwTable.closeProject();

        wellSchedule.closeProject();
        wellsList.closeProject();

        sfRegionList.model = [];
        pvtRegionList.model = [];

        projectData.initVariables();
    }

}
