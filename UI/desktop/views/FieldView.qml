import QtQuick 2.12
import QtQuick.Controls 1.4

SplitView {
    property real ratio: 0.8
    property bool settingsVisible: false

    id: fieldSplit
    anchors.fill: parent
    orientation: Qt.Horizontal

    Item {
        id: field
        width: parent.width
        height: parent.height

        Image {
            anchors { right: parent.right; top: parent.top; topMargin: 10; }
            source: settingsVisible ? "qrc:/desktop/images/icon-right-24x24.png" : "qrc:/desktop/images/icon-left-24x24.png"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    settingsVisible = !settingsVisible;
                    resizeItems();
                }
            }
        }
    }

    Rectangle {
        id: settings
        visible: settingsVisible
        border { width: 1; color: "lightgray" }
    }

    onResizingChanged: {
        if(!resizing) {
            ratio = Math.min(field.width/fieldSplit.width, field.height/fieldSplit.height);
            resizeItems();
        }
    }

    onWidthChanged: resizeItems()

    function resizeItems() {
        field.width = settingsVisible ? ratio >= 0 && ratio <= 1 ? ratio*fieldSplit.width : fieldSplit.width/2 : fieldSplit.width;
        settings.width = settingsVisible ? ratio >= 0 && ratio <= 1 ? (1-ratio)*fieldSplit.width : fieldSplit.width/2 : fieldSplit.width;
    }
}
