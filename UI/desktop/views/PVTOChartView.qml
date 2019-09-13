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
            id: pvtoChart
            margins { left: 0; right: 0; bottom: 0; top: 0 }
            height: parent.parent.height / 2
            legend.alignment: Qt.AlignTop

            LineSeries {
                property alias markerSize: rsPVTO2.markerSize
                property alias markerColor: rsPVTO2.color
                property alias markerShape: rsPVTO2.markerShape

                id: rsPVTO
                name: qsTr("Rso")
                color:"mediumseagreen"
                axisX: axisX
                axisYRight: axisY2
                width: 2
                style: "SolidLine"
            }
            LineSeries {
                property alias markerSize: boPVTO2.markerSize
                property alias markerColor: boPVTO2.color
                property alias markerShape: boPVTO2.markerShape

                id: boPVTO
                name: qsTr("Bo")
                color:"mediumpurple"
                axisX: axisX
                axisY: axisY
                width: 2
                style: "SolidLine"
            }
            LineSeries {
                property alias markerSize: moPVTO2.markerSize
                property alias markerColor: moPVTO2.color
                property alias markerShape: moPVTO2.markerShape

                id: moPVTO
                name: qsTr("Mo")
                color: "orange"
                axisX: axisX
                axisY: axisY
                width: 2
                style: "SolidLine"
            }

            ScatterSeries{
                id:rsPVTO2
                markerSize: 8
                visible: rsPVTO.visible
                axisX: axisX
                axisYRight: axisY2
                color: "mediumseagreen"
                markerShape: ScatterSeries.MarkerShapeRectangle
            }
            ScatterSeries{
                id:boPVTO2
                markerSize: 8
                visible: boPVTO.visible
                color: "mediumpurple"
                axisX: axisX
                axisY: axisY
                markerShape: ScatterSeries.MarkerShapeCircle
            }
            ScatterSeries{
                id:moPVTO2
                markerSize: 8
                visible: moPVTO.visible
                color: "red"
                axisX: axisX
                axisY: axisY
                markerShape: ScatterSeries.MarkerShapeCircle
            }

            ValueAxis {
                id: axisX
                titleText:qsTr("Давление, Psia")
                color: "Black"

                min: 0
                max: 5000
                tickCount: 6
                labelFormat: "%.0f"


                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            ValueAxis {
                id: axisY
                titleText:qsTr("Объем. коэф. нефти (RB/STB), Вязкость нефти (cp.)")
                color: "Black"

                min: 0
                max: 1.25
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            ValueAxis {
                id: axisY2
                titleText: qsTr("Растворимость газа (MSCF/STB)")
                color: "Black"

                min: 0
                max: 1.6
                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }

            Rectangle{
                width: 50
                height: 10
                color: "white"
                anchors { top: pvtoChart.top; right:pvtoChart.right; topMargin: 23; rightMargin: pvtoChart.width/2-72 }
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
            id: pvtoList
            Layout.fillHeight: false

            TableViewColumn {
                role: "rs"
                title: "Rso"
                width: pvtoList.width/4
            }
            TableViewColumn {
                role: "po"
                title: "P"
                width: pvtoList.width/4
            }
            TableViewColumn {
                role: "bo"
                title: "Bo"
                width: pvtoList.width/4
            }
            TableViewColumn {
                role: "mo"
                title: "Mo"
                width: pvtoList.width/4
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
            text: pvtoList.visible?"Скрыть таблицу":"Показать таблицу"
            onTriggered:  {
                pvtoList.visible = !pvtoList.visible;
                pvtoChart.anchors.fill = pvtoList.visible ? parent.parent:null;
            }
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [rsPVTO, boPVTO, moPVTO]
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
            pvtoChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i< pvtoChart.count; i++)
            pvtoChart.series(i).clear();
        pvtoList.model = [];
    }
    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.length; i++)
        {
            rsPVTO.append(list[i].po, list[i].rs);
            rsPVTO2.append(list[i].po,list[i].rs);
            boPVTO.append(list[i].po, list[i].bo);
            boPVTO2.append(list[i].po,list[i].bo);
            moPVTO.append(list[i].po, list[i].mo);
            moPVTO2.append(list[i].po, list[i].mo);
        }
        pvtoList.model = list;
    }
}
