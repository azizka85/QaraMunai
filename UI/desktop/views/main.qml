import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QaraMunai.Model.Domain.Project 1.0
import QaraMunai.Model.DAO 1.0

ApplicationWindow {
    property Item content: home

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
                    anchors { left: parent.left; top: parent.top; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-eclipse-32x32.png"; }

                    onClicked: importDATAOFD.open()
                }

                Button {
                    anchors { left: eclipseButton.right; top: parent.top; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-exit-32x32.ico"; }

                    onClicked: closeProject()
                }
            }

            RibbonGroup {
                title: qsTr("Полный экран")

                Button {
                    anchors { left: parent.left; top: parent.top; margins: 6 }
                    width: 44
                    height: 44

                    onClicked: mainWindow.visibility = mainWindow.visibility === Window.Maximized ? "FullScreen" : "Maximized"
                }
            }
        }

        RibbonTab {
            title: qsTr("Карта")
            tabWidth: 80
        }

        RibbonTab {
            title: qsTr("Функции насыщенности")
            tabWidth: 150

            RibbonGroup {
                title: qsTr("ОФП и КД (нефть вода)")
                width: 140

                Button {
                    id: swofButton
                    anchors { left: parent.left; top: parent.top; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-linechart-32x32.png"; }

                    onClicked: {
                        content.visible = false;
                        swofChart.visible = true;
                        content = swofChart;
                    }
                }

                Button {
                    anchors { left: swofButton.right; top: parent.top; margins: 6 }
                    width: icon.width + 12
                    height: icon.height + 12
                    icon { width: 32; height: 32; source: "qrc:/desktop/images/icon-tablegrid-32x32.png"; }

                    onClicked: {
                        content.visible = false;
                        swofTable.visible = true;
                        content = swofTable;
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

                        var list = projectData.swof.getList(sfRegionList.currentIndex);

                        swofChart.prepare(list);
                        swofTable.prepare(list);
                    }
                }
            }
        }

        RibbonTab {
            title: qsTr("Свойства пластовой жидкости")
            tabWidth: 200
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

    Item {
        id: home;
        anchors { left: parent.left; right: parent.right; top: ribbon.bottom; bottom: parent.bottom }
        visible: true;

        Text {
            anchors.centerIn: parent
            text: qsTr("Qara munai'")
            font.pixelSize: 20
            color: "green"
        }
    }

    SWOFChartView { id: swofChart; anchors { left: parent.left; right: parent.right; top: ribbon.bottom; bottom: parent.bottom } visible: false; }

    SWOFTableView { id: swofTable; anchors { left: parent.left; right: parent.right; top: ribbon.bottom; bottom: parent.bottom } visible: false; }

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

        sfRegionList.model = [];

        content.visible = false;
        home.visible = true;
        content = home;

        projectData.initVariables();
    }
}
