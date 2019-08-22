import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: volumeRateChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: vOilProdSeries
            name: qsTr("Нак. объем доб. нефти")
        }

        LineSeries {
            id: vWaterProdSeries
            name: qsTr("Нак. объем доб. воды")
        }

        LineSeries {
            id: vWaterInjSeries
            name: qsTr("Нак. объем рас. воды")
        }

        LineSeries {
            id: vGasProdSeries
            name: qsTr("Нак. объем доб. газа")
        }

        LineSeries {
            id: vDistGasProdSeries
            name: qsTr("Нак. объем доб. раст. газа")
        }

        LineSeries {
            id: vGasInjSeries
            name: qsTr("Нак. объем рас. газа")
        }

        LineSeries {
            id: vRastGasInjSeries
            name: qsTr("Нак. объем рас. своб. газа")
        }
    }


    function closeProject()
    {
        vRastGasInjSeries.clear();
        vGasInjSeries.clear();
        vDistGasProdSeries.clear();
        vGasProdSeries.clear();
        vWaterInjSeries.clear();
        vWaterProdSeries.clear();
        vOilProdSeries.clear();

    }

    function prepare(list)
    {
        closeProject();

        for(var i = 0; i < list.length; i++)
        {
            vOilProdSeries.append(list[i].sw, list[i].krw);
            vWaterProdSeries.append(list[i].sw, list[i].kro);
            vWaterInjSeries.append(list[i].sw, list[i].pc);
            vGasProdSeries.append(list[i].sw, list[i].pc);
            vDistGasProdSeries.append(list[i].sw, list[i].pc);
            vGasInjSeries.append(list[i].sw, list[i].pc);
            vRastGasInjSeries.append(list[i].sw, list[i].pc);

        }
    }
}
