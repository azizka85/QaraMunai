import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtCharts 2.3
import QtQuick.Dialogs 1.0

Window {
    property alias model: settings.model

    visible: false
    width: 613
    height: 110
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
                validator: IntValidator{ bottom: 1; top: 10 }
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

        TableViewColumn {
            role: "markerColor"
            title: "Цвет \nмаркера"
            resizable: false
            width: 60
            delegate: Rectangle {
                id: rect2
                radius: 3
                anchors.fill: parent
                color: modelData.markerColor
                onColorChanged: modelData.markerColor = color

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("ModelData color = " + modelData.color);
                        colorDialog2.open();
                    }
                }

                ColorDialog {
                    id: colorDialog2
                    color: rect2.color
                    title: "Please choose a color"
                    onCurrentColorChanged: {
                        modelData.markerColor = currentColor
                    }
                    onAccepted: {
                        modelData.markerColor = color
                    }
                    Component.onCompleted: visible = false
                }
            }
        }

        TableViewColumn {
            role: "markerSize"
            title: "Толщина \nмаркера"
            resizable: false
            width: 60
            delegate: TextInput {
                anchors.fill: parent
                text: modelData.markerSize
                onTextChanged: if(acceptableInput) modelData.markerSize = text
                validator: IntValidator { bottom: 1; top: 10 }
                horizontalAlignment: Text.AlignHCenter
            }
        }

        TableViewColumn {
            role: "markerShape"
            title: "Тип линии"
            resizable: false
            width: 115
            delegate: ComboBox {
                currentIndex: modelData.markerShape
                anchors.fill: parent
                height: currentText.height
                model: MarkerShape {}
                onCurrentTextChanged: modelData.markerShape = currentIndex
            }
        }
    }

    function closeProject()
    {
        settings.model = [];
    }
}
