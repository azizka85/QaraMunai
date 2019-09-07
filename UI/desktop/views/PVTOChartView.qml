import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtoChart
        anchors.fill: parent
        legend.alignment: Qt.AlignTop
        margins { left: 0; right: 0; bottom: 0; top: 0 }

        Rectangle{
            width: 50
            height: 10
            color: "white"
            anchors { top: pvtoChart.top; right:pvtoChart.right; topMargin: 23; rightMargin: pvtoChart.width/2-72 }
        }

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
    }

    function closeProject()
    {
        rsPVTO.clear();
        rsPVTO2.clear();
        boPVTO.clear();
        boPVTO2.clear();
        moPVTO.clear();
        moPVTO2.clear();
    }

    function prepare(list)
    {
        rsPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();
        rsPVTO2.clear();
        boPVTO2.clear();
        moPVTO2.clear();

        for(var i = 0; i < list.length; i++)
        {
            rsPVTO.append(list[i].po, list[i].rs);
            rsPVTO2.append(list[i].po,list[i].rs);
            boPVTO.append(list[i].po, list[i].bo);
            boPVTO2.append(list[i].po,list[i].bo);
            moPVTO.append(list[i].po, list[i].mo);
            moPVTO2.append(list[i].po, list[i].mo);
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
        model: [rsPVTO, boPVTO, moPVTO]
    }
}
