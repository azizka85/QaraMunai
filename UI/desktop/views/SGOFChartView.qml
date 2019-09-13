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
        id: sgofChart
        margins { left: 0; right: 0; bottom: 0; top: 0 }
        legend.alignment: Qt.AlignTop
        Layout.preferredHeight: parent.parent.height / 2

        LineSeries {
            property alias markerSize: krgSGOF2.markerSize
            property alias markerColor: krgSGOF2.color
            property alias markerShape: krgSGOF2.markerShape

            id: krgSGOF
            name: qsTr("Krg")
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            property alias markerSize: kroSGOF2.markerSize
            property alias markerColor: kroSGOF2.color
            property alias markerShape: kroSGOF2.markerShape

            id: kroSGOF
            name: qsTr("Krog")
            color: "mediumpurple"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            property alias markerSize: pcSGOF2.markerSize
            property alias markerColor: pcSGOF2.color
            property alias markerShape: pcSGOF2.markerShape

            id: pcSGOF
            name: qsTr("Pcog")
            color: "orange"
            axisX: axisX
            axisYRight: axisY2
            width: 2
            style: "SolidLine"
        }

        ScatterSeries{
            id: krgSGOF2
            markerSize: 8
            visible: krgSGOF.visible
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            markerShape: ScatterSeries.MarkerShapeRectangle
        }
        ScatterSeries{
            id:kroSGOF2
            markerSize: 8
            visible: kroSGOF.visible
            color: "mediumpurple"
            axisX: axisX
            axisY: axisY
            markerShape: ScatterSeries.MarkerShapeCircle
        }
        ScatterSeries{
            id:pcSGOF2
            markerSize: 8
            visible: pcSGOF.visible
            color: "red"
            axisX: axisX
            axisYRight: axisY2
            markerShape: ScatterSeries.MarkerShapeCircle
        }

        ValueAxis{
            id: axisX
            titleText: qsTr("Насыщенность газа, д.ед.")
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
            titleText:qsTr("Отн. фазовые проницаемости, д.ед. ")
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
            titleText:qsTr("Капиллярное давление, Psia")
            color: "Black"

            min: 0
            max: 4
            tickCount: 6
            labelFormat: "%.1f"

            gridVisible: false
        }

        Rectangle{
            width: 60
            height: 10
            color: "white"
            anchors { top: sgofChart.top; right:sgofChart.right; topMargin: 23; rightMargin: sgofChart.width/2-85 }
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
            id: sgofList

            TableViewColumn {
                role: "sg"
                title: "Sg"
                width: sgofList.width/4
                resizable: false
            }
            TableViewColumn {
                role: "krg"
                title: "Krg"
                width: sgofList.width/4
                resizable: false
            }
            TableViewColumn {
                role: "kro"
                title: "Krog"
                width: sgofList.width/4
                resizable: false
            }
            TableViewColumn {
                role: "pc"
                title: "Pcog"
                width: sgofList.width/4
                resizable: false
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
            text: (sgofList.visible)?"Скрыть таблицу":"Показать таблицу"
            onTriggered:  {
                sgofList.visible = !sgofList.visible;
                sgofChart.anchors.fill = sgofList.visible ? parent.parent:null;
            }
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [krgSGOF, kroSGOF, pcSGOF]
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
            sgofChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i< sgofChart.count; i++)
            sgofChart.series(i).clear();
        sgofList.model = [];
    }
    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.length; i++)
        {
            krgSGOF.append(list[i].sg, list[i].krg);
            krgSGOF2.append(list[i].sg, list[i].krg);
            kroSGOF.append(list[i].sg, list[i].kro);
            kroSGOF2.append(list[i].sg, list[i].kro);
            pcSGOF.append(list[i].sg, list[i].pc);
            pcSGOF2.append(list[i].sg, list[i].pc);
        }
        sgofList.model = list;
    }
}
