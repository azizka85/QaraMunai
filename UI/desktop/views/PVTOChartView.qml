import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtoChart
        title: qsTr("PVT нефти")
        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent



        legend {
            visible: true
            alignment: Qt.AlignBottom
        }
        ValueAxis{
            id: axisX
            min: 0
            max: 5000
            titleText: "Давление, Psia"
            tickCount: 6
        }

        ValueAxis{
            id: axisY2
            min: 0
            max: 2
            titleText: "Растворимость газа (MSCF/STB)"
            lineVisible: false
            tickCount: 6
        }
        ValueAxis{
            id: axisY
            min: 0
            max: 1.5
            lineVisible: false
            titleText: "Объем. коэф. нефти (RB/STB),Вязк. нефти (cp.)"
            tickCount: 6
        }

        LineSeries {
            axisX: axisX
            id: poPVTO
            name: qsTr("PO(RS)")
        }

        LineSeries {
            axisY: axisY
            id: boPVTO
            name: qsTr("BO(RS)")
        }

        LineSeries {
            axisYRight: axisY2
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

    Menu{
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {
                settingsForm.show()
            }
        }
    }

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton|Qt.RightButton
        onClicked: {
            if(mouse.button & Qt.RightButton)
                settingsMenu.popup()
        }
    }
}
