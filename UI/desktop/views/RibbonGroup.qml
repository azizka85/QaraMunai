import QtQuick 2.0

Item {
    default property alias contents: content.children
    property int contentMargins: 3
    property string title: "Title"

    id: ribbonGroup
    width: 106
    height: parent.height

    Rectangle {
        id: group
        anchors { fill: parent; margins: contentMargins }
        Rectangle {
            id: content
            anchors { left: parent.left; right: parent.right; top: parent.top; bottom: footerPanel.top }
//            border { width: 1; color: "lightgray" }
            color: '#f3f3f3'
        }

        Rectangle {
            id: footerPanel
            anchors { left: parent.left; right: parent.right; bottom: parent.bottom }
//            border { width: 1; color: "lightgray" }
            height: 20
            color: '#f3f3f3'

            Text {
                anchors.centerIn: parent
                font { pixelSize: 11 }
                text: title
            }
        }
    }
}
