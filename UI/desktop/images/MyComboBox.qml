import QtQuick 2.12
import QtQuick.Controls 2.12

ComboBox {
    id: control
    width: 80
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

    contentItem: Text {
        text: "Регион №" + control.displayText
        verticalAlignment: Text.AlignVCenter
        anchors { centerIn: parent; rightMargin: 4 }
        font: control.font
    }

    background: Rectangle {
        width: control.width
        implicitHeight: control.height + 8
        color: hovered || popup.visible ? '#bbbbbb' : 'transparent'
        MouseArea {
            id: ma
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                popup.visible = !popup.visible
                if(popup.visible){
                    opacityAnimation.start();
                }
            }

        }

        states: [State {
                name: "hovered"
                when: ma.containsMouse
            } ]
    }

    popup: Popup {
        id: popup
        y: control.height - 1
        width: control.width
        implicitHeight: contentItem.implicitHeight
        padding: 1
        NumberAnimation on opacity {
            id: opacityAnimation
            from: 0
            to: 100
            duration: 50
            running: popup.visible
        }
        NumberAnimation on height {
            id: heightAnimation
            from: 0
            to: list.implicitHeight + 2
            duration: 50
            running:  popup.visible
        }
        contentItem: ListView {
            id: list
            clip: true
            implicitHeight: contentHeight
            model: control.delegateModel
            currentIndex: control.highlightedIndex
            ScrollIndicator.vertical: ScrollIndicator { }
        }
        background: Rectangle {
            border.color: "lightgray"
            radius: 2
        }
    }

}
