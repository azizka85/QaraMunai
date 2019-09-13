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
            id: pvtgChart
            margins { left: 0; right: 0; bottom: 0; top: 0 }
            height: parent.parent.height / 2
            legend.alignment: Qt.AlignTop

            LineSeries {
                property alias markerSize: bgPVTG2.markerSize
                property alias markerColor: bgPVTG2.color

                id: bgPVTG
                name: qsTr("Bg")
                color:"mediumseagreen"
                axisX: axisX
                axisY: axisY
                width: 2
                style: "SolidLine"
            }
            LineSeries {
                id: mgPVTG
                name: qsTr("Mg")
                color: "mediumpurple"
                axisX: axisX
                axisYRight: axisY2
                width: 2
                style: "SolidLine"
            }

            ScatterSeries{
                id:bgPVTG2
                markerSize: 8
                visible: bgPVTG.visible
                color: "mediumseagreen"
                axisX: axisX
                axisY: axisY
                markerShape: ScatterSeries.MarkerShapeCircle
            }
            ScatterSeries{
                id:mgPVTG2
                markerSize: 8
                visible: mgPVTG.visible
                color: "mediumpurple"
                axisX: axisX
                axisYRight: axisY2
                markerShape: ScatterSeries.MarkerShapeCircle
            }

            ValueAxis{
                id: axisX
                titleText:qsTr("Давление, Psia")
                color: "Black"

                min: 0
                max: 4000
                tickCount: 6
                labelFormat: "%.0f"


                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            ValueAxis{
                id:axisY
                titleText:qsTr("Объем. коэф. газа (RB/MSCF)")
                color: "Black"

                min: 0
                max: 179
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
                titleText: qsTr("Вязк. газа (ср.)")
                color: "Black"

                min: 0
                max: 0.02
                tickCount: 6
                labelFormat: "%.3f"

                gridVisible: false
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
            id: pvtgList
            Layout.fillHeight: false
            TableViewColumn {
                role: "pg"
                title: "P"
                width: pvtgList.width/3
            }
            TableViewColumn {
                role: "bg"
                title: "Bg"
                width: pvtgList.width/3
            }
            TableViewColumn {
                role: "mg"
                title: "Mg"
                width: pvtgList.width/3
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
            text: pvtgList.visible?"Скрыть таблицу":"Показать таблицу"
            onTriggered:  {
                pvtgList.visible = !pvtgList.visible;
                pvtgChart.anchors.fill = pvtgList.visible ? parent.parent:null;
            }
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [bgPVTG, mgPVTG]
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
            pvtgChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i< pvtgChart.count; i++)
            pvtgChart.series(i).clear();
        pvtgList.model = [];
    }

    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.length; i++)
        {
            bgPVTG.append(list[i].pg, list[i].bg);
            bgPVTG2.append(list[i].pg, list[i].bg);
            mgPVTG.append(list[i].pg, list[i].mg);
            mgPVTG2.append(list[i].pg, list[i].mg);
        }
        pvtgList.model = list;
    }
}
