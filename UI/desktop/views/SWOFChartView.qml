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
            axisX: ValueAxis{
                min: 0
                max: 1
                tickCount: 6
                labelFormat: "%.1f"
                titleText: "Насыщенность воды, д.ед."
            }
            axisY: ValueAxis{
                min: 0
                max: 1
                tickCount: 6
                 labelFormat: "%.1f"
                titleText: "Отн. фазовые проницаемости, д.ед. "
            }
            style: "SolidLine"
        }

        LineSeries {
            id: kroSWOF
            name: qsTr("Krow")
            style: "SolidLine"
        }

        LineSeries {
            id: pcSWOF
            name: qsTr("Pcow")
            axisYRight:  ValueAxis{
                tickCount: 6
                gridVisible: false
                 labelFormat: "%.1f"
                titleText: "Капиллярное давление, Psia"
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
