import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

Item {
    default property alias contents: content.children

    property var dockWindow: null
    property Item dockSpace: null

    property bool titleVisible: true
    property string dockTitle: "Dock title"
    property real contentMargins: 1

    id: dockItem
    width: parent.width
    height: parent.height

    Rectangle {
        anchors { fill: parent; margins: contentMargins }

        Rectangle {
            id: headerPanel
            anchors { left: parent.left; right: parent.right; top: parent.top; }
            height: !dockWindow.visible && titleVisible ? 20 : 0
            visible: !dockWindow.visible && titleVisible
            color: "#D3D3D3"
            Text {
                anchors { left: parent.left; right: closeButton.left; top: parent.top; bottom: parent.bottom }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: dockTitle
                font.family: "Arial"
                clip: true

                MouseArea {
                    anchors.fill: parent
                    onDoubleClicked: unDock()
                }
            }

            MyButton {
                id: closeButton
                anchors { right: parent.right; verticalCenter: parent.verticalCenter; rightMargin: 5 }
                icon { width: 16; height: 16; source: "qrc:/desktop/images/icon_close_button.png"; }
                width: 20
                height: 20
                onClicked: hide()
            }
        }

        Rectangle {
            id: content
            anchors { left: parent.left; right: parent.right; top: headerPanel.bottom; bottom: parent.bottom }
            border { width: 1; color: "lightgray" }
        }
    }

    Component {
        id: dockComponent

        Window {
            title: dockTitle
            width: 300
            height: 200
            visible: false

            onVisibleChanged:
            {
                if(!visible) dockSpace.freeDock(dockItem);
            }
        }
    }

    Component.onCompleted: dockWindow = dockComponent.createObject(dockItem);

    function hide()
    {
        if(dockWindow.visible === true) dockWindow.visible = false;
        else if(dockSpace != null) dockSpace.hideDock(dockItem);
    }

    function unDock()
    {
        if(dockSpace != null)
        {
            dockSpace.unSplit(dockItem);

            dockItem.parent = dockWindow.contentItem;

            dockWindow.show();
        }
    }   
}
