import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {
    property alias settingsView: settingsView

    ChartView {
        id: pvtgChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }
        margins.top: 0
        margins.bottom: 0
        margins.left: 0
        margins.right: 0

        LineSeries {
            property alias markerSize: pgPVTG2.markerSize
            property alias markerColor: pgPVTG2.color

            id: pgPVTG
            name: qsTr("PG")
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
            visible: false
        }
        LineSeries {
            property alias markerSize: bgPVTG2.markerSize
            property alias markerColor: bgPVTG2.color

            id: bgPVTG
            name: qsTr("Bg")
            color:"mediumpurple"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            id: mgPVTG
            name: qsTr("Mg")
            color: "orange"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
    }

    ScatterSeries{
        id:pgPVTG2
        markerSize: 8
        visible: pgPVTG.visible
        color: "mediumseagreen"
        markerShape: ScatterSeries.MarkerShapeCircle
    }
    ScatterSeries{
        id:bgPVTG2
        markerSize: 8
        visible: bgPVTG.visible
        color: "mediumpurple"
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

    function closeProject()
    {
        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();
        pgPVTG2.clear();
        bgPVTG2.clear();
    }

    function prepare(list)
    {
        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();
        pgPVTG2.clear();
        bgPVTG2.clear();

        for(var i = 0; i < list.length; i++)
        {
            pgPVTG.append(list[i].rv, list[i].pg);
            bgPVTG.append(list[i].rv, list[i].bg);
            mgPVTG.append(list[i].rv, list[i].mg);
            pgPVTG2.append(list[i].rv, list[i].pg);
            bgPVTG2.append(list[i].rv, list[i].bg);
        }
    }

    Menu{
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {
                settingsView.show()
            }
        }
    }

    MouseArea{
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
        model: [pgPVTG, bgPVTG, mgPVTG]
    }
}
