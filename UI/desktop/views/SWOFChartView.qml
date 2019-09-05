import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.13
import QtQuick.Dialogs 1.3

Item {

    SplitView {
        orientation: Qt.Vertical
        anchors.fill: parent
        handleDelegate: Rectangle {
                implicitWidth: 4
                implicitHeight: 4
                color: SplitHandle.pressed ? "#81e889"
                    : (SplitHandle.hovered ? Qt.lighter("#c2f4c6", 1.1) : "#c2f4c6")
            }
        ChartView {
            id: swofChart
            anchors  { top: parent.top }
            Layout.minimumHeight: parent.height - swofList.height

            legend.alignment: Qt.AlignTop

            margins { left: 0; right: 0; bottom: 0; top: 0 }


            LineSeries {
                property alias markerSize: krwSWOF2.markerSize
                property alias markerColor: krwSWOF2.color
                property alias markerShape: krwSWOF2.markerShape

                id: krwSWOF
                name: qsTr("Krw")
                color: "mediumseagreen"
                axisX: axisX
                axisY: axisY
                width: 2
                style: "SolidLine"
            }
            LineSeries {
                property alias markerSize: kroSWOF2.markerSize
                property alias markerColor: kroSWOF2.color
                property alias markerShape: kroSWOF2.markerShape

                id: kroSWOF
                name: qsTr("Krow")
                color: "mediumpurple"
                axisX: axisX
                axisY: axisY
                axisYRight: axisY2
                width: 2
                style: "SolidLine"
            }
            LineSeries {
                property alias markerSize: pcSWOF2.markerSize
                property alias markerColor: pcSWOF2.color
                property alias markerShape: pcSWOF2.markerShape

                id: pcSWOF
                name: qsTr("Pcow")
                color: "orange"
                axisX: axisX
                axisYRight: axisY2
                width: 2
                style: "SolidLine"
            }
            ScatterSeries{
                id:krwSWOF2
                markerSize: 8
                visible: krwSWOF.visible
                color: "mediumseagreen"
                axisX: axisX
                axisY: axisY
                markerShape: ScatterSeries.MarkerShapeRectangle
            }
            ScatterSeries{
                id:kroSWOF2
                markerSize: 8
                visible: kroSWOF.visible
                color: "mediumpurple"
                axisX: axisX
                axisY: axisY
                markerShape: ScatterSeries.MarkerShapeCircle
            }
            ScatterSeries{
                id:pcSWOF2
                markerSize: 8
                visible: pcSWOF.visible
                color: "red"
                axisX: axisX
                axisYRight: axisY2
                markerShape: ScatterSeries.MarkerShapeCircle
            }

            ValueAxis{
                id: axisX
                titleText:qsTr("Насыщенность воды, д.ед.")
                color: "Black"

                min: 0
                max: 1
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            ValueAxis{
                id: axisY
                titleText:qsTr("Отн. фазовые проницаемости, д.ед.")
                color: "Black"

                min: 0
                max: 1
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            ValueAxis{
                id: axisY2
                titleText: qsTr("Капиллярное давление, Psia")
                color: "Black"

                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }
        }
        TableView {
            id: swofList
            anchors { bottom: parent.bottom }

            height: 400
            Layout.maximumHeight: 500
            Layout.fillHeight: false

            TableViewColumn {
                role: "sw"
                title: "Sw"
                width: swofList.width/4
                resizable: false
            }

            TableViewColumn {
                role: "krw"
                title: "Krw"
                width: swofList.width/4
                resizable: false
            }

            TableViewColumn {
                role: "kro"
                title: "Krow"
                width: swofList.width/4
                resizable: false
            }

            TableViewColumn {
                role: "pc"
                title: "Pcow"
                width: swofList.width/4
                resizable: false
            }
        }
    }

    function closeProject()
    {
        krwSWOF.clear();
        krwSWOF2.clear();
        kroSWOF.clear();
        kroSWOF2.clear();
        pcSWOF.clear();
        pcSWOF2.clear();

        swofList.model = [];
    }

    function prepare(list)
    {
        krwSWOF.clear();
        krwSWOF2.clear();
        kroSWOF.clear();
        kroSWOF2.clear();
        pcSWOF.clear();
        pcSWOF2.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            krwSWOF2.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            kroSWOF2.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
            pcSWOF2.append(list[i].sw, list[i].pc);
        }

        swofList.model = list;
    }

    Menu {
        id: settingsMenu
        MenuItem {
            text: "Настройка графиков"
            onTriggered: {
                settingsView.show()
            }
        }

        // Дұрыстау керек
        MenuItem {
            id: captureMenuItem
            text: "Сделать снимок"
            property variant asad : ["gh"]
            onTriggered: {
                swofChart.grabToImage(function(result){ asad.push(result);console.log(asad[1]); captureFileDialog.open(); });
            }
        }
    }
    FileDialog {
        id: captureFileDialog
        title: "Выберите расположение изображения"
        folder: shortcuts.pictures
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        selectExisting: false
        defaultSuffix: 'png'
        onAccepted: {
            close();
            captureMenuItem.asad[1].saveToFile(captureFileDialog.fileUrl);
        }
    }


    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton|Qt.RightButton
        onClicked: {
            if(mouse.button & Qt.RightButton)
                settingsMenu.popup()
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [krwSWOF, kroSWOF, pcSWOF]
    }
}
