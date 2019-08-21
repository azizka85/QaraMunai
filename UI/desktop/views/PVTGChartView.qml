import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {

    ChartView {
        id: pvtgChart
        title: qsTr("PVT газа")
        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: pgPVTG
            name: qsTr("PG(RV)")
        }

        LineSeries {
            id: bgPVTG
            name: qsTr("BG(RV)")
        }

        LineSeries {
            id: mgPVTG
            name: qsTr("MG(RV)")
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
