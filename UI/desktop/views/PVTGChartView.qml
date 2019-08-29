import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {
    property alias settingsView: settingsView

    ChartView {
        id: pvtgChart
        anchors.fill: parent
        legend.alignment: Qt.AlignTop

        margins.top: 0
        margins.bottom: 0
        margins.left: 0
        margins.right: 0

        Rectangle{
            width: 50
            height: 10
            color: "white"
//              anchors{right: legend.right}
            x:swofChart.width/1.935
                y:swofChart.height*0.025
        }
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

    function closeProject()
    {
        bgPVTG.clear();
        bgPVTG2.clear();
        mgPVTG.clear();
        mgPVTG2.clear();
    }

    function prepare(list)
    {
        bgPVTG.clear();
        bgPVTG2.clear();
        mgPVTG.clear();
        mgPVTG2.clear();

        for(var i = 0; i < list.length; i++)
        {
            bgPVTG.append(list[i].pg, list[i].bg);
            bgPVTG2.append(list[i].pg, list[i].bg);
            mgPVTG.append(list[i].pg, list[i].mg);
            mgPVTG2.append(list[i].pg, list[i].mg);
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
        model: [bgPVTG, mgPVTG]
    }
}
