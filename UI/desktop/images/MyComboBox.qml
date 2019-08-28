import QtQuick 2.0
import QtQuick.Controls 2.5

ComboBox {
    id: control
//    width: 50
    delegate: ItemDelegate {
        contentItem:
            Text {
            text: modelData
            font: control.font
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
        }
        highlighted: control.highlightedIndex === index
    }
//    indicator:  Image {
//        width: height; height: control.height / 2;
//        source: "qrc:/desktop/images/arrow-down-16x16.png"
//        anchors { right: control.right; verticalCenter: control.verticalCenter; rightMargin: 2 }
//    }
    contentItem: Text {
        text: "Регион №" + control.displayText
        font: control.font

        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideMiddle
        horizontalAlignment: Text.AlignHCenter
        anchors.rightMargin: 4
    }

    background: Rectangle {
//        implicitWidth: control.width + 12
//        implicitHeight: control.height + 8
        color: control.visualFocus || hovered ? '#bbbbbb' : 'transparent'
//        border { width: 1; color: '#bbbbbb' }
        MouseArea {
            id: ma
            anchors.fill: parent
            hoverEnabled: true
        }
        states: [State {
            name: "hovered"
            when: ma.containsMouse
        }]
    }

}
