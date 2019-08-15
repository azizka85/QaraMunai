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
        title: qsTr("Карты")
        anchors { left: parent.left; top:  kartaText.bottom; leftMargin: 20; topMargin: 20}
        Row {
            spacing: 20
            ExclusiveGroup { id: tabPositionGroup }
            RadioButton {
                text: "Начальный"
                checked: true
                exclusiveGroup: tabPositionGroup
            }

            RadioButton {
                text: "Расчитанный"
                checked: false
                exclusiveGroup: tabPositionGroup
            }
        }
    }
}
