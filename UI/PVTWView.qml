import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.4

Item {
    visible: true
    width: 300
    height: 200
    GridLayout {
        columns: 2

        Text {
            id: label1
            text: qsTr("Опорное давление:")
        }

        TextField {
            id: input
            text: qsTr("1")
        }

        Text {
            id: label2
            text: qsTr("Объемный коэф.:")
        }

        TextField {
            id: mask
            text: qsTr("999999")
        }

        Text {
            id: label3
            text: qsTr("Сжимаемость:")
        }

        TextField {
            id: compressibility
            text: qsTr("999999")
        }
    }
}
