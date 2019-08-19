import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: panel
    width: 96
    height: 24
    border { color: "black"; width: 1 }
    radius: 8
    clip: true
    color: "lightgray"
    Rectangle {
        id: clipper
        width: panel.width / 4 + clipped.radius
        height: panel.height + clipped.radius
        color: "transparent"
        clip: true
        anchors { left: panel.left; top: panel.top; leftMargin: -clipped.radius }
        Rectangle {
            id: clipped
            width: panel.width / 4 + radius
            height: panel.height + radius
            radius: 8
            color: "red"
            anchors { left: parent.left }
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
    }
    Rectangle {
        visible: false
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

