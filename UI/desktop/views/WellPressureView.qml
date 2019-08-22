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
            id: wellPressureSeries
            name: qsTr("Ср. пластовое давление")
        }
        Repeater {
            LineSeries {
            }
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
