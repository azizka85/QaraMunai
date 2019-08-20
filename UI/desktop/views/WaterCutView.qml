import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: watcutChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: kinSeries
            name: qsTr("KIN")
        }

        LineSeries {
            id: waterCutSeries
            name: qsTr("Обводненость")
        }

        LineSeries {
            id: gofSeries
            name: qsTr("ГНФ")
        }

        LineSeries {
            id: wgfSeries
            name: qsTr("ВГФ")
        }

        LineSeries {
            id: wofSeries
            name: qsTr("ВНФ")
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

        for(var i = 0; i < list.length; i++)
        {
            wofSeries.append(list[i].sw, list[i].krw);
            wgfSeries.append(list[i].sw, list[i].kro);
            gofSeries.append(list[i].sw, list[i].pc);
            kinSeries.append(list[i].sw, list[i].pc);
            waterCutSeries.append(list[i].sw, list[i].pc);

        }
    }
}
