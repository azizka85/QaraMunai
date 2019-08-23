import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: swofChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: krwSWOF
            name: qsTr("Krw")
            color: "mediumseagreen"
            width: 2
            axisX: ValueAxis{
                titleText:qsTr("Насыщенность воды, д.ед.")
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
                titleText:qsTr("Отн. фазовые проницаемости, д.ед.")
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
        }

        LineSeries {
            id: kroSWOF
            name: qsTr("Krow")
            color: "mediumpurple"
            width: 2
            style: "SolidLine"
        }

        LineSeries {
            id: pcSWOF
            name: qsTr("Pcow")
            color: "orange"
            width: 2
            axisYRight:  ValueAxis{
                titleText: qsTr("Капиллярное давление, Psia")
                color: "Black"

                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }
            style: "SolidLine"
        }
    }

    function closeProject()
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
    }

    function prepare(list)
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
        }
    }

    function getSeries()
    {
        return [krwSWOF, kroSWOF, pcSWOF];
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
