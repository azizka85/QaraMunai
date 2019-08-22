import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtoChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: poPVTO
            name: qsTr("Rso")
            axisX: ValueAxis{
                titleText:qsTr("Давление, Psia")
                color: "Black"

                min: 0
                max: 5000
                tickCount: 6
                labelFormat: "%.0f"


                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }

            axisY: ValueAxis{
                titleText:qsTr("Объем. коэф. нефти (RB/STB), Вязк. нефти(ср.)")
                color: "Black"

                min: 0
                max: 1.5
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            style: "SolidLine"
        }

        LineSeries {
            id: boPVTO
            name: qsTr("Bo")
            style: "SolidLine"

        }

        LineSeries {
            id: moPVTO
            name: qsTr("Mo")
            axisYRight:  ValueAxis{
                titleText: qsTr("Растворимость газа(MSCF/STB)")
                color: "Black"

                min: 0
                max: 2
                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }
            style: "SolidLine"
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
            poPVTO.append(list[i].po, list[i].po);
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
