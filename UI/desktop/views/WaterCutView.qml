import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
//    property alias model: watcutChart.model
    ChartView {
        id: watcutChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: kinSeries
            name: qsTr("SIN (KIN)")
            axisX: x
            axisY: y
        }

        LineSeries {
            id: waterCutSeries
            name: qsTr("COS (Обводненость)")
        }

        LineSeries {
            id: gofSeries
            name: qsTr("Exp (ГНФ)")
        }

        LineSeries {
            id: wgfSeries
            name: qsTr("x^2 (ВГФ)")
        }

        LineSeries {
            id: wofSeries
            name: qsTr("log(x) (ВНФ)")
        }

        ValueAxis {
            id: x
            min: 0;
            max: 100
        }
        ValueAxis {
            id: y
            min: 0
            max: 10
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
