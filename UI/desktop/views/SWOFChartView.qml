import QtQuick 2.12
import QtCharts 2.3
import QtQuick 2.0
import QtQuick.Controls 1.4
Item {
    signal settingsCalled()
    ChartView {
        id: swofChart
        title: qsTr("ОФП и КД (нефть-вода)")
        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent


        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton|Qt.RightButton
            onClicked: {
                if(mouse.button & Qt.RightButton)
                    settingsMenu.popup()
            }
        }

        Menu{
            id: settingsMenu
            Action{
                text: qsTr("Настройка графиков")
                onTriggered: {
                    settingsCalled()
                }
            }
        }

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            id: krwSWOF
            name: qsTr("Krw")
        }

        LineSeries {
            id: kroSWOF
            name: qsTr("Krow")
        }

        LineSeries {
            id: pcSWOF
            name: qsTr("Pcow")
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
}
