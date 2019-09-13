import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.4

Item {
    GroupBox{
        id: pvtwGroupBox
        title: "PVTW воды"

        GridLayout {
            columns: 2
            Text {
                id: label1
                text: qsTr("Опорное давление:")
            }

            TextField {

            }

            Text {
                id: label2
                text: qsTr("Объемный коэф.:")
            }

            TextField {

            }

            Text {
                id: label3
                text: qsTr("Сжимаемость:")
            }

            TextField {

            }

            Text {
                id: label4
                text: qsTr("Вязкость воды:")
            }

            TextField {

            }

            Text {
                id: label5
                text: qsTr("Вязк. сжимаемость:")
            }

            TextField {

            }
        }
    }

    GroupBox{
        id: porodaGroupBox
        title: "Порода"
        anchors.top: pvtwGroupBox.bottom
        GridLayout {
            columns: 2
            Text {
                id: label6
                text: qsTr("Опорное давление:")
            }

            TextField {

            }

            Text {
                id: label7
                text: qsTr("Сжимаемость:")
            }

            TextField {

            }
        }
    }

    GroupBox{
        title: "Плотности"
        anchors.top: porodaGroupBox.bottom
        GridLayout {
            columns: 2
            Text {
                id: label8
                text: qsTr("Плотность нефти:   ")
            }

            TextField {

            }

            Text {
                id: label9
                text: qsTr("Плотность воды:")
            }

            TextField {

            }
            Text {
                id: label10
                text: qsTr("Плотность газа:")
            }

            TextField {

            }
        }
    }
}
