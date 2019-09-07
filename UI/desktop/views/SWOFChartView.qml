import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 2.1 as C1
import QtQuick.Controls 1.4 as C2
import QtQuick.Layouts 1.13
import QtQuick.Dialogs 1.3

Item {

       C2.SplitView {
        orientation: Qt.Vertical
        anchors.fill: parent
        resizing: true
        handleDelegate: Rectangle {
            implicitWidth: 4
            implicitHeight: 4
            color: SplitHandle.pressed ? "#81e889"
                                       : (SplitHandle.hovered ? Qt.lighter("#c2f4c6", 1.1) : "#c2f4c6")
        }
        ChartView {
            id: swofChart
            anchors  { top: parent.top }
            Layout.minimumHeight: parent.height/2
            Layout.maximumHeight: 600
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
            anchors { bottom: parent.bottom }
            height: 400
            Layout.maximumHeight: 500
            Layout.fillHeight: false

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

    C1.Menu {
        id: settingsMenu
       C1.MenuItem {
            text: "Настройка графиков"
            onClicked:{
                settingsView.show()
            }
        }

        // Дұрыстау керек
        C1.MenuItem {
            id: captureMenuItem
            text: "Сделать снимок"
            property variant asad : ["gh"]
            onTriggered: {
                swofChart.grabToImage(function(result){ asad.push(result);console.log(asad[1]); captureFileDialog.open(); });
            }
        }

        C1.MenuItem {
            id: asss
            text: (swofList.visible)?"Скрыть таблицу":"Показать таблицу"
            onClicked: {
                if(swofList.visible===true)
                  {
                    swofList.visible=false
                    swofChart.height=parent.height
            }
            else{
                   swofList.visible=true
                }
            }
        }
        C1.Menu{
            title: "Масштаб"
            C1.MenuItem{
                text: "1:1"
                onClicked: {
                   swofChart.Layout.minimumHeight=swofChart.maximumHeight/2;
                    swofList.height=swofChart.maximumHeight-swofChart.height
                }
            }
            C1.MenuItem{
                text: "3:2"
                onClicked: {
                    swofChart.height=(parent.height*3)/5;
                    swofList.height=parent.height-swofChart.height
                }
            }
            C1.MenuItem{
                text: "5:3"
                onClicked: {
                    swofChart.height=(parent.height*5)/8;
                    swofList.height=parent.height-swofChart.height
                }
            }
            C1.MenuItem{
                text: "4:3"
                onClicked: {
                    swofChart.height=(parent.height*4)/7;
                    swofList.height=parent.height-swofChart.height
                }
            }
            C1.MenuItem{
                text: "5:4"
                onClicked: {
                    swofChart.height=(parent.height*5)/9;
                    swofList.height=parent.height-swofChart.height
                }
            }
            C1.MenuItem{
                text: "7:5"
                onClicked: {
                    swofChart.height=(parent.height*7)/12;
                    swofList.height=parent.height-swofChart.height
                }
            }
            C1.MenuItem{
                text: "16:9"
                onClicked: {
                    swofChart.height=(parent.height*16)/25;
                    swofList.height=parent.height-swofChart.height
                }
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
