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
        RowLayout {

            ExclusiveGroup { id: tabPositionGroup }
            RadioButton {
                text: "Начальный"
                Layout.preferredWidth: (grop.width-60)/2
                Layout.minimumWidth: text.width
                checked: true
                exclusiveGroup: tabPositionGroup
            }

            RadioButton {
                anchors { left: parent.parent.left }
                text: "Расчитанный"
                Layout.preferredWidth: (grop.width-60)/2
                Layout.minimumWidth: text.width
                checked: false
                exclusiveGroup: tabPositionGroup
            }
        }
    }
}
