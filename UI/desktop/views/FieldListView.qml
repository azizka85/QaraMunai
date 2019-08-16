import QtQuick 2.0
import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    Text {
        id: kartaText
        text: qsTr("Карты")
        anchors { left: parent.left; top: parent.top; leftMargin: 20; topMargin: 20 }
    }

    GroupBox {
        id: grop
        title: qsTr("Карты")
        anchors { top: kartaText.bottom; right: parent.right; left: parent.left; rightMargin: 20; leftMargin: 20; topMargin: 20}
        Row {

            ExclusiveGroup { id: tabPositionGroup }
            RadioButton {
                text: "Начальный"
                width: (grop.width-60)/2
                checked: true
                exclusiveGroup: tabPositionGroup
            }

            RadioButton {
                text: "Расчитанный"
                width: (grop.width-60)/2
                checked: false
                exclusiveGroup: tabPositionGroup
            }
        }
    }

    ListView {
        id: listView
        anchors { top: grop.bottom; right: parent.right; left: parent.left; topMargin: 20; rightMargin: 20; leftMargin: 20 }
        height: 100
        delegate: Text {
            text: name
        }

    }
}
