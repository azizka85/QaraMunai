import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: flowRateChart
        anchors.fill: parent

        margins { left: 0; right: 0; bottom: 0; top: 0 }

        legend.alignment: Qt.AlignTop

        LineSeries {
            id: oilRateSeries
            name: qsTr("Дебит нефти")

            axisX: axisX
            axisY: axisY
        }

        LineSeries {
            id: waterRateSeries
            name: qsTr("Дебит воды")

            axisX: axisX
            axisY: axisY
        }

        LineSeries {
            id: gasRateSeries
            name: qsTr("Дебит газа")

            axisX: axisX
            axisYRight: axisY2
        }

        LineSeries {
            id: waterInjRateSeries
            name: qsTr("Расход воды")

            axisX: axisX
            axisY: axisY
        }

        LineSeries {
            id: gasInjRateSeries
            name: qsTr("Расход газа")

            axisX: axisX
            axisYRight: axisY2
        }

        ValueAxis{
            id: axisX
            titleText:qsTr("Время")
            color: "Black"

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
            titleText:qsTr("Дебиты воды и нефти, stb / day")
            color: "Black"

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
            titleText:qsTr("Дебиты газа, Mscf / day")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            minorTickCount: 4
            minorGridVisible: true
            minorGridLineColor: "gainsboro"

            gridVisible: true
            gridLineColor: "silver"
        }
    }


    function closeProject()
    {
        gasInjRateSeries.clear();
        waterInjRateSeries.clear();
        gasRateSeries.clear();
        waterRateSeries.clear();
        oilRateSeries.clear();
    }

    function prepare(list)
    {
        closeProject();

        for(var i = 0; i < list.length; i++)
        {
            oilRateSeries.append(list[i].sw, list[i].krw);
            waterRateSeries.append(list[i].sw, list[i].kro);
            gasRateSeries.append(list[i].sw, list[i].pc);
            waterInjRateSeries.append(list[i].sw, list[i].pc);
            gasInjRateSeries.append(list[i].sw, list[i].pc);

        }
    }
}
