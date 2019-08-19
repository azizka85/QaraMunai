import QtQuick 2.12
import QtCharts 2.3

Item {

    ChartView {
        id: pvtoChart
//        title: qsTr("PVT нефти")
//        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: poPVTO
            name: qsTr("PO(RS)")
        }

        LineSeries {
            id: boPVTO
            name: qsTr("BO(RS)")
        }

        LineSeries {
            id: moPVTO
            name: qsTr("MO(RS)")
        }
    }

    function closeProject()
    {
        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();
    }

    function prepare(list)
    {
        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();

        for(var i = 0; i < list.length; i++)
        {
            poPVTO.append(list[i].rs, list[i].po);
            boPVTO.append(list[i].rs, list[i].bo);
            moPVTO.append(list[i].rs, list[i].mo);
        }       
    }
}
