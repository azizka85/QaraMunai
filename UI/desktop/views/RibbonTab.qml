import QtQuick 2.0

Item {
    default property alias contents: groups.children
    property alias color: content.color
    property alias spacing: groups.spacing

    property int tabWidth: 70
    property string title: "Title"

    id: ribbonTab

    Rectangle {
        id: content
        anchors.fill: parent
//        border { width: 2; color: "black" }
        color: '#f3f3f3'
        Row {
            id: groups
            anchors.fill: parent
        }
        Rectangle {
            color: "#d2d2d2"
            anchors { top: parent.bottom; left: parent.left; right: parent.right }
            height: 1
        }
    }
}
