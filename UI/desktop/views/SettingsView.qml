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
    property alias model: settings.model

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
            delegate: Rectangle {
                anchors.fill: parent
                color: 'transparent'
                CheckBox {
                    anchors.horizontalCenter: parent.horizontalCenter
                    checked: modelData.visible
                    onCheckedStateChanged: modelData.visible = checked
                }
            }
        }

        TableViewColumn {
            role: "color"
            title: "Цвет \nлинии"
            resizable: false
            width: 60
            delegate: Rectangle {
                id: rect
                radius: 3
                anchors.fill: parent
                color: modelData.color
                onColorChanged: modelData.color = color

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("ModelData color = " + modelData.color);
                        colorDialog.open();
                    }
                }

                ColorDialog {
                    id: colorDialog
                    color: rect.color
                    title: "Please choose a color"
                    onCurrentColorChanged: {
                        modelData.color = currentColor
                    }
                    onAccepted: {
                        modelData.color = color
                    }
                    Component.onCompleted: visible = false
                }
            }
}

        TableViewColumn {
            role: "width"
            title: "Толщина \nлинии"
            resizable: false
            width: 60
            delegate: TextInput {
                anchors.fill: parent
                text: modelData.width
                onTextChanged: if(acceptableInput) modelData.width = text
                validator: IntValidator{bottom: 1; top: 10}
                horizontalAlignment: Text.AlignHCenter
            }
        }

        TableViewColumn {
            role: "linedash"
            title: "Тип линии"
            resizable: false
            width: 115
            delegate: ComboBox {
                currentIndex: modelData.style
                anchors.fill: parent
                height: currentText.height
                model: PenStyles {}
                onCurrentTextChanged: modelData.style = currentIndex
            }

        }
    }

    function closeProject()
    {
        settings.model = [];
    }
}
