import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4

Item {
    ChartView {
        id: swofChart
        title: qsTr("ОФП и КД (нефть-вода)")
        titleColor: "blue"
        titleFont { pixelSize: 14; bold: true }
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        Menu {
            id: menu
            Action {
                text: qsTr("Настройка")
                onTriggered: {
                    settingsCalled();
                }
            }
        }
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton|Qt.LeftButton
            onClicked: {
                if(mouse.button&Qt.RightButton){
                    menu.popup();
                }
            }
        }

        LineSeries {
            id: krwSWOF
            name: qsTr("KrW(SW)")
        }

        LineSeries {
            id: kroSWOF
            name: qsTr("KrO(SW)")
        }

        LineSeries {
            id: pcSWOF
            name: qsTr("Pc(SW)")
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
