import QtQuick 2.0
import QtQuick.Controls 2.0
Rectangle {
    visible: true
    anchors.centerIn: parent
    id: root
    radius: 8
    width: 30
    height: 30
    color: "transparent"
    Rectangle {
        id: clipper
        width: 10
        height: 40
        color: 'transparent'
        clip: true

        Rectangle {
            id: clipped
            width: parent.width + radius
            height: parent.height + radius
            radius: root.radius
            color: 'red'
        }
    }


Rectangle {
    visible: false
    id: panel
    width: 96
    height: 24
    border { color: "black"; width: 1 }
    radius: 8
    clip: true
    color: "lightgray"

    Rectangle {
        id: moveFirstButton
        width: panel.width / 4
        anchors { left: panel.left; top: panel.top; bottom: panel.bottom}

        Image {
            source: "qrc:/desktop/images/move_first.png"
        }
        MouseArea {
            anchors.fill: parent.fill
            onPressed: {
                color = "red"
            }
        }
    }

    Rectangle {
        id: movePreviousButton
        width: panel.width / 4
        height: parent.height
        anchors { left: moveFirstButton.right; top: panel.top}

        Image {
            source: "qrc:/desktop/images/move_previous.png"
        }
        MouseArea {
            anchors.fill: parent
            onPressed: {
                color = "red"
            }
        }
    }

    Rectangle {
        id: toNextButton
        width: panel.width / 4
        height: parent.height
        anchors { left: movePreviousButton.right; top: panel.topr}

        Image {
            source: "qrc:/desktop/images/move_next.png"
        }
        MouseArea {
            anchors.fill: parent
            onPressed: {
                color = "red"
            }
        }
    }

    Rectangle {
        id: toLastButton
        width: panel.width / 4
        height: parent.height
        anchors { left: toNextButton.right; top: panel.top}

        Image {
            source: "qrc:/desktop/images/move_last.png"
        }
        MouseArea {
            anchors.fill: parent.fill
            onPressed: {
                color = "red"
            }
        }
    }
}
}
