import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: flowRateChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: oilRateSeries
            name: qsTr("Дебит нефти")
        }

        LineSeries {
            id: waterRateSeries
            name: qsTr("Дебит воды")
        }

        LineSeries {
            id: gasRateSeries
            name: qsTr("Дебит газа")
        }

        LineSeries {
            id: waterInjRateSeries
            name: qsTr("Расход воды")
        }

        LineSeries {
            id: gasInjRateSeries
            name: qsTr("Расход газа")
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
