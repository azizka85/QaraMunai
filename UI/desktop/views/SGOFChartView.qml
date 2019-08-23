import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1
Item {

    ChartView {
        id: sgofChart
        anchors.fill: parent

        legend {
            visible: true
            alignment:Qt.AlignBottom
        }

        LineSeries {
            id: krgSGOF
            name: qsTr("Krg")
            color: "mediumseagreen"
            width: 2
            axisX: ValueAxis{
                titleText: qsTr("Насыщенность газа, д.ед.")
                color: "Black"

                min: 0
                max: 1
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            axisY: ValueAxis{
                titleText:qsTr("Отн. фазовые проницаемости, д.ед. ")
                color: "Black"

                min: 0
                max: 1
                tickCount: 6
                labelFormat: "%.1f"

                minorTickCount: 4
                minorGridVisible: true
                minorGridLineColor: "gainsboro"

                gridVisible: true
                gridLineColor: "silver"
            }
            style: "SolidLine"
            capStyle:"FlatCap"
        }

        LineSeries {
            id: kroSGOF
            name: qsTr("Krog")
            color: "mediumpurple"
            width: 2
            style: "SolidLine"
            capStyle:"FlatCap"
        }

        LineSeries {
            id: pcSGOF
            name: qsTr("Pcog")
            color: "orange"
            width: 2
            axisYRight:  ValueAxis{
                titleText:qsTr("Капиллярное давление, Psia")
                color: "Black"

                min: 0
                max: 4
                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }
            style: "SolidLine"
            capStyle:"SquareCap"

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
