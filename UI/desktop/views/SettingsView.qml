import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtCharts 2.3
import QtQuick.Dialogs 1.0

Window {
    visible: false
    width: 506
    height: 100
    title: qsTr("Настройка графиков")

    TableView {
        id: settings
        anchors.fill: parent

        TableViewColumn {
            role: "name"
            title: "Название"
            resizable: false
            width: 60
            delegate: TextInput {
                anchors.fill: parent
                text: modelData.name
                onTextChanged: modelData.name = text
            }
        }

        TableViewColumn {
            role: "visible"
            title: "Отображение"
            resizable: false
            width: 80
            delegate: CheckBox {
                anchors.fill: parent
                checked: modelData.visible
                onCheckedStateChanged: modelData.visible = checked
            }
        }

        TableViewColumn {
            role: "color"
            title: "Цвет \nлинии"
            resizable: false
            width: 60
            delegate: Rectangle{
                anchors.fill: parent
                color: modelData.color
                onColorChanged: modelData.color=color

                MouseArea{
                    anchors.fill: parent
                    onClicked: colorDialog.open()
                }
            }
        }

        TableViewColumn {
            role: "width"
            title: "Толщина \nлинии"
            resizable: false
            width: 60
        }

        TableViewColumn {
            role: "linedash"
            title: "Тип \nлинии"
            resizable: false
            width: 60
        }

        TableViewColumn {
            role: "markercolor"
            title: "Цвет \nмаркера"
            resizable: false
            width: 60
        }

        TableViewColumn {
            role: "markerthck"
            title: "Толщина \nмаркера"
            resizable: false
            width: 60
        }

        TableViewColumn {
            role: "markerdash"
            title: "Тип \nмаркера"
            resizable: true
            width: 60
        }
    }

    function prepare(series){
        settings.model = [];
        settings.model = series;
    }

    function closeProject()
    {
        settings.model = [];
    }



    ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        onAccepted: {
            console.log("You chose: " + colorDialog.color)
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false
    }
}
