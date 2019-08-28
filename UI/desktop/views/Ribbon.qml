import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12

Rectangle {
    default property alias contents: ribbonContent.children

    property real ribbonHeight: 120

    id: ribbon
    width: parent.width
    height: ribbonHeight
    color: 'white'
    border.color: 'transparent'

    TabBar {
        id: ribbonBar
        anchors { top: parent.top; left: parent.left }
        background: Rectangle {
            color: 'white'
            width: ribbon.width
//            border { color: 'black'; width: 2 }
        }
        height: 25
        contentHeight: 25
        Repeater {
            model: contents

            TabButton {
                text: modelData.title
                width: modelData.tabWidth
                down: false
                onDoubleClicked: switchRibbonVisible()
                background: Rectangle {

                    color: parent.checked ? '#f3f3f3' : 'white'
                }
            }
        }
    }

    MyButton {
        width: icon.width
        height: icon.height
        anchors { right: parent.right; top: parent.top; margins: 3 }
        icon { width: 16; height: 16; source: ribbonContent.visible ? "qrc:/desktop/images/arrow-up-16x16.png" : "qrc:/desktop/images/arrow-down-16x16.png" }

        onClicked: switchRibbonVisible()
    }

    StackLayout {
        id: ribbonContent
        anchors { left: parent.left; right: parent.right; top: ribbonBar.bottom; }
        currentIndex: ribbonBar.currentIndex
        height: ribbon.height - ribbonBar.height
        anchors.topMargin: 0
    }

    function switchRibbonVisible()
    {
        ribbonContent.visible = !ribbonContent.visible;
        ribbon.height = ribbonContent.visible ? ribbonHeight : ribbonBar.height;
    }
}
