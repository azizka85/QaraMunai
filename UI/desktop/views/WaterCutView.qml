import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
//    property alias model: watcutChart.model
    ChartView {
        id: watcutChart
        anchors.fill: parent

        margins { left: 0; right: 0; bottom: 0; top: 0 }

        legend.alignment: Qt.AlignTop


        LineSeries {
            id: kinSeries
            name: qsTr("KIN")

            axisX: axisX
            axisY: axisY
        }

        LineSeries {
            id: waterCutSeries
            name: qsTr("Обводненость")

            axisX: axisX
            axisY: axisY
        }

        LineSeries {
            id: gofSeries
            name: qsTr("ГНФ")

            axisX: axisX
            axisYRight: axisY2
        }

        LineSeries {
            id: wgfSeries
            name: qsTr("ВГФ")

            axisX: axisX
            axisYRight: axisY2
        }

        LineSeries {
            id: wofSeries
            name: qsTr("ВНФ")

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
            titleText:qsTr("КИН, Обводненность, %")
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
            titleText:qsTr("ГНФ, ВГФ, ВНФ")
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
        wofSeries.clear();
        wgfSeries.clear();
        gofSeries.clear();
        kinSeries.clear();
        waterCutSeries.clear();
    }

    function prepare(list)
    {
        closeProject();

        for(var i = 0; i < list.count; i++)
        {   console.log(list.get(i).index + " --------------------------prepared")
            wofSeries.append(list.get(i).index, list.get(i).log);
            wgfSeries.append(list.get(i).index, list.get(i).xx);
            gofSeries.append(list.get(i).index, list.get(i).exp);
            kinSeries.append(list.get(i).index, list.get(i).sin);
            waterCutSeries.append(list.get(i).ndex, list.get(i).cos);
        }
    }
}
