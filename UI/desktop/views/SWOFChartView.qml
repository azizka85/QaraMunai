import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.13
import QtQuick.Dialogs 1.3

Item {
    SplitView {
        id: splitView
        orientation: Qt.Vertical
        anchors.fill: parent
        handleDelegate: Rectangle {
            implicitWidth: 4
            implicitHeight: 4
            color: 'gainsboro'
            border { color: 'black'; width: 1 }
        }

        ChartView {
            id: swofChart
            margins { left: 0; right: 0; bottom: 0; top: 0 }
            height: parent.parent.height / 2
            legend.alignment: Qt.AlignTop

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

            Rectangle{
                width: 60
                height: 10
                color: "white"
                anchors { top: swofChart.top; right:swofChart.right; topMargin: 23; rightMargin: swofChart.width/2-87 }
            }

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                hoverEnabled: true
                propagateComposedEvents: true
                preventStealing: false
                onClicked: {
                    if(mouse.button & Qt.RightButton) settingsMenu.popup()
                }
            }
        }

        TableView {
            id: swofList
            Layout.fillHeight: false
            TableViewColumn {
                role: "sw"             
                title: "Sw"
                width: swofList.width/4
            }
            TableViewColumn {
                role: "krw"
                title: Text {
                    text: qsTr("Krw")
                    color: "mediumseagreen"
                }
                width: swofList.width/4
            }
            TableViewColumn {
                role: "kro"
                title: "Krow"
                width: swofList.width/4
            }
            TableViewColumn {
                role: "pc"
                title: "Pcow"
                width: swofList.width/4
            }
        }
    }

    Menu {
        id: settingsMenu

        MenuItem {
            text: "Настройка графиков"
            onTriggered: settingsView.show();
        }
        MenuItem {
            text: "Сделать снимок"
            onTriggered: captureFileDialog.open();
        }
        MenuItem {
            text: swofList.visible?"Скрыть таблицу":"Показать таблицу"
            onTriggered:  {
                swofList.visible = !swofList.visible;
                swofChart.anchors.fill =parent.parent
            }
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [krwSWOF, kroSWOF, pcSWOF]
    }

    FileDialog {
        id: captureFileDialog
        title: "Сохранить как"
        folder: shortcuts.pictures
        nameFilters: [ "PNG файл (*.png)", "Все файлы (*)" ]
        selectExisting: false
        defaultSuffix: 'png'
        onAccepted: {
            var path = fileUrl.toString();
            // remove prefixed "file:///"
            path = path.replace(/^(file:\/{3})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            swofChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i< swofChart.count; i++)
            swofChart.series(i).clear();
        swofList.model = [];
    }
    function prepare(list)
    {
        closeProject();
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
}
