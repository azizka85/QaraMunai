import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtoChart
        anchors.fill: parent
        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        ValueAxis {
            id: axisX
            titleText:qsTr("Растворимость газа (MSCF/STB)")
            color: "Black"

            min: 0
            max: 1.5
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
            titleText: qsTr("Вязкость нефти")
            color: "Black"

            min: 0
            max: 2
            tickCount: 6
            labelFormat: "%.1f"

            gridVisible: false
        }

        LineSeries {
            id: poPVTO
            name: qsTr("Po")
            color:"mediumseagreen"
            axisYRight: axisY2
            axisX: axisX
            style: "SolidLine"
        }

        LineSeries {
            id: boPVTO
            name: qsTr("Bo")
            color:"mediumpurple"
            axisY: axisY
            axisX: axisX
            style: "SolidLine"

        }

        LineSeries {
            id: moPVTO
            name: qsTr("Mo")
            color: "orange"
            axisY: axisY
            axisX: axisX
            style: "SolidLine"
        }

        ScatterSeries{
            id:poPVTO2
            markerSize: 8
            visible: poPVTO.visible
            color: "mediumseagreen"
            markerShape: ScatterSeries.MarkerShapeCircle
        }

        ScatterSeries{
            id:boPVTO2
            markerSize: 8
            visible: boPVTO.visible
            color: "mediumpurple"
            markerShape: ScatterSeries.MarkerShapeCircle
        }
    }

    function closeProject()
    {
        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();
        poPVTO2.clear();
        boPVTO2.clear();
    }

    function prepare(list)
    {
        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();
        poPVTO2.clear();
        boPVTO2.clear();

        for(var i = 0; i < list.length; i++)
        {
            poPVTO.append(list[i].rs, list[i].po);
            boPVTO.append(list[i].rs, list[i].bo);
            moPVTO.append(list[i].rs, list[i].mo);
            poPVTO2.append(list[i].rs,list[i].po);
            boPVTO2.append(list[i].rs,list[i].bo);
        }
    }

    Menu{
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {
                settingsForm.show()
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
}
