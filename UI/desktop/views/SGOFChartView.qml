import QtQuick 2.12
import QtCharts 2.3

Item {

    ChartView {
        id: sgofChart
        title: qsTr("ОФП и КД (газ-нефть)")
        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: krgSGOF
            name: qsTr("KrG(SG)")
        }

        LineSeries {
            id: kroSGOF
            name: qsTr("KrO(SG)")
        }

        LineSeries {
            id: pcSGOF
            name: qsTr("Pc(SG)")
        }
    }

    function closeProject()
    {
        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();
    }

    function prepare(list)
    {
        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();

        for(var i = 0; i < list.length; i++)
        {
            krgSGOF.append(list[i].sg, list[i].krg);
            kroSGOF.append(list[i].sg, list[i].kro);
            pcSGOF.append(list[i].sg, list[i].pc);
        }
    }

    function getSeries()
    {
        return [krgSGOF, kroSGOF, pcSGOF];
    }
}
