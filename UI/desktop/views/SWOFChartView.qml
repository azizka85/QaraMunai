import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 2.1 as C1
import QtQuick.Controls 1.4 as C2
import QtQuick.Controls 2.13 as C3
import QtQuick.Controls 2.5 as C4
import QtQuick.Layouts 1.13
import QtQuick.Dialogs 1.3

Item {

    C3.SplitView {
        id: splitView
        orientation: Qt.Vertical
        anchors.fill: parent

        handle: Rectangle {
            implicitWidth: 4
            implicitHeight: 4
            color: 'gainsboro'
            border { color: 'black'; width: 1 }
        }

        ChartView {
            id: swofChart
            C3.SplitView.preferredHeight: parent.parent.height / 2
            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                hoverEnabled: true
                propagateComposedEvents: true
                preventStealing: false
                onClicked: {
                    if(mouse.button & Qt.RightButton)
                        settingsMenu.popup()
                }
            }
            legend.alignment: Qt.AlignTop
            margins { left: 0; right: 0; bottom: 0; top: 0 }

            Rectangle{
                width: 60
                height: 10
                color: "white"
                anchors { top: swofChart.top; right:swofChart.right; topMargin: 23; rightMargin: swofChart.width/2-87 }
            }

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
        C2.TableView {
            id: swofList
            C2.TableViewColumn {
                role: "sw"
                title: "Sw"
                width: swofList.width/4
                resizable: false

            }

            C2.TableViewColumn {
                role: "krw"
                title: "Krw"
                width: swofList.width/4
                resizable: false
            }

            C2.TableViewColumn {
                role: "kro"
                title: "Krow"
                width: swofList.width/4
                resizable: false
            }

            C2.TableViewColumn {
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

    C2.Menu {
        id: settingsMenu
        C2.MenuItem {
            text: "Настройка графиков"
           onTriggered:
                settingsView.show()
        }

        C2.MenuItem {
            id: captureMenuItem
            text: "Сделать снимок"
            onTriggered: {
                captureFileDialog.open();

            }

            FileDialog {
                id: captureFileDialog
                title: "Выберите расположение изображения"
                folder: shortcuts.pictures
                nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
                selectExisting: false
                defaultSuffix: 'png'
                onAccepted: {
                    console.log(Qt.resolvedUrl(fileUrl));
                    var path = fileUrl.toString();
                    // remove prefixed "file:///"
                    path = path.replace(/^(file:\/{3})/,"");
                    // unescape html codes like '%23' for '#'
                    var cleanPath = decodeURIComponent(path);
                    console.log(cleanPath)
                    swofChart.grabToImage(function(resultik){console.log(resultik.saveToFile(cleanPath))});
                }
            }
        }

        C2.MenuItem {
            id: asss
            text: (swofList.visible)?"Скрыть таблицу":"Показать таблицу"
            onTriggered:  {
                if(swofList.visible)
                {
                    swofList.visible=false
                    swofChart.anchors.fill=parent.parent
                }
                else {
                    swofList.visible=true
                }
            }
        }

        SettingsView {
            id: settingsView
            visible: false
            model: [krwSWOF, kroSWOF, pcSWOF]
        }
    }

    //    states: [
    //        State {
    //            name: "tableClosed"
    //            PropertyChanges {
    //                target: swofList
    //                height: 0
    //            }
    //        }]
    //    transitions: [
    //        Transition {
    //            from: "fromState"
    //            to: "toState"

    //            NumberAnimation {
    //                properties: swofList.height
    //                easing.type: Easing.InOutQuad
    //            }
    //        }
    //    ]
}
