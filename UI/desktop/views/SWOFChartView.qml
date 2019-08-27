import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 2.1

Item {
    property alias settingsView: settingsView

    ChartView {
        id: swofChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            property alias markerSize: krwSWOF2.markerSize
            property alias markerColor: krwSWOF2.color

            id: krwSWOF
            name: qsTr("Krw")
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries{
            property alias markerSize: kroSWOF2.markerSize
            property alias markerColor: kroSWOF2.color

            id: kroSWOF
            name: qsTr("Krow")
            color: "mediumpurple"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
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
            markerShape: ScatterSeries.MarkerShapeRectangle
        }
        ScatterSeries{
            id:kroSWOF2
            markerSize: 8
            visible: kroSWOF.visible
            color: "mediumpurple"
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

    function closeProject()
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        krwSWOF2.clear();
        kroSWOF2.clear();
    }

    function prepare(list)
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        krwSWOF2.clear();
        kroSWOF2.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
            kroSWOF2.append(list[i].sw, list[i].kro);
            krwSWOF2.append(list[i].sw, list[i].krw);
        }
    }

    Menu {
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {
                settingsView.show()
            }
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

