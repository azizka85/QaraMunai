import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtgChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: pgPVTG
            name: qsTr("PG(RV)")
            visible: false
            axisX: ValueAxis{
                titleText:qsTr("Давление, Psia")
                color: "Black"

                min: 0
                max: 4000
                tickCount: 6
                labelFormat: "%.0f"


                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }

            axisY: ValueAxis{
                titleText:qsTr("Объем. коэф. газа (RB/MSCF)")
                color: "Black"

                min: 0
                max: 179
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
            id: bgPVTG
            name: qsTr("Bg")
            style: "SolidLine"
        }

        LineSeries {
            id: mgPVTG
            name: qsTr("Mg")
            axisYRight:  ValueAxis{
                titleText: qsTr("Вязк. газа (ср.)")
                color: "Black"

                min: 0
                max: 0.02
                tickCount: 6
                labelFormat: "%.3f"

                gridVisible: false
            }
            style: "SolidLine"
        }
    }

    function closeProject()
    {
        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();
    }

    function prepare(list)
    {
        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();

        for(var i = 0; i < list.length; i++)
        {
            pgPVTG.append(list[i].rv, list[i].pg);
            bgPVTG.append(list[i].rv, list[i].bg);
            mgPVTG.append(list[i].rv, list[i].mg);
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
