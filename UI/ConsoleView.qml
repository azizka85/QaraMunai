import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.13

Item {
    SplitView {
        orientation: Qt.Horizontal
        handleDelegate: Rectangle {
            implicitWidth: 4
            implicitHeight: 4
            color: 'gainsboro'
            border { color: 'black'; width: 1 }
        }
        anchors.fill: parent

        Rectangle {
            property string tex: 'This is CLI'

            id: cli
            color: 'white'
            width: parent.parent.width/2

            Text {
                text: qsTr(parent.tex)
            }
        }

        Rectangle {
            property string tex: 'This is Console'

            id: consoleRec
            color: 'black'
            Layout.fillWidth: false
            width: parent.parent.width/2

            Text {
                text: qsTr(parent.tex)
                color: 'white'
            }
        }
    }

}
