import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: volumeRateChart
        anchors.fill: parent

        margins { left: 0; right: 0; bottom: 0; top: 0 }

        legend.alignment: Qt.AlignTop


        LineSeries {
            id: wellPressureSeries
            name: qsTr("Ср. пластовое давление")

            axisX: axisX
            axisY: axisY
        }
        Repeater {
            LineSeries {
            }
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
            titleText:qsTr("Давление, psi")
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
        wellPressureSeries.clear();

    }

    function prepare(list)
    {
        closeProject();

        for(var i = 0; i < list.length; i++)
        {
            wellPressureSeries.append(list[i].sw, list[i].krw);
        }
    }
}
