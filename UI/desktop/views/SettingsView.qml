import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window{
    visible: false
    width: 500
    height: 150
    title: qsTr("Настройка графиков")
    TableView {
        id: settings
        anchors.fill: parent
        model:largeModel
        itemDelegate: {
            return editableDelegate;
        }
        TableViewColumn {
            role: "name"
            title: "Название"
            width: 60
        }

        TableViewColumn {
            role: "show"
            title: "Отображение"
            width: 80
        }

        TableViewColumn {
            role: "linecolor"
            title: "Цвет \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "linethck"
            title: "Толщина \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "linedash"
            title: "Тип \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "markercolor"
            title: "Цвет \nмаркера"
            width: 60
        }

        TableViewColumn {
            role: "markerthck"
            title: "Толщина \nмаркера"
            width: 60
        }

        TableViewColumn {
            role: "markerdash"
            title: "Тип \nмаркера"
            width: 60
        }
        Item {

            Text {
                width: parent.width
                anchors.margins: 4
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                elide: styleData.elideMode
                text: styleData.value !== undefined ? styleData.value : ""
                color: styleData.textColor
                visible: !styleData.selected
            }
            Loader {
                id: loaderEditor
                anchors.fill: parent
                anchors.margins: 4
                Connections {
                    target: loaderEditor.item
                    onAccepted: {
                        if (typeof styleData.value === 'number')
                            largeModel.setProperty(styleData.row, styleData.role, Number(parseFloat(loaderEditor.item.text).toFixed(0)))
                        else
                            largeModel.setProperty(styleData.row, styleData.role, loaderEditor.item.text)
                    }
                }
                sourceComponent: styleData.selected ? editor : null
                Component {
                    id: editor
                    TextInput {
                        id: textinput
                        color: styleData.textColor
                        text: styleData.value
                        MouseArea {
                            id: mouseArea
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: textinput.forceActiveFocus()
                        }
                    }
                }
            }
        }
    }
    Item {
        anchors.fill: parent

        Component {
            id: editableDelegate
            Item {

                Text {
                    width: parent.width
                    anchors.margins: 4
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    elide: styleData.elideMode
                    text: styleData.value !== undefined ? styleData.value : ""
                    color: styleData.textColor
                    visible: !styleData.selected
                }
                Loader {
                    id: loaderEditor
                    anchors.fill: parent
                    anchors.margins: 4
                    Connections {
                        target: loaderEditor.item
                        onEditingFinished : {
                            if (typeof styleData.value === 'number')
                                largeModel.setProperty(styleData.row, styleData.role, Number(parseFloat(loaderEditor.item.text).toFixed(0)))
                            else
                                largeModel.setProperty(styleData.row, styleData.role, loaderEditor.item.text)
                        }
                    }
                    sourceComponent: styleData.selected ? editor : null
                    Component {
                        id: editor
                        TextInput {
                            id: textinput
                            color: styleData.textColor
                            text: styleData.value
                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: textinput.forceActiveFocus()
                            }
                        }
                    }
                }
            }
        }
    }
    ListModel {
        id: largeModel
    }
    function prepare(chart){
        for (var i=0 ; i< chart.count; ++i)
            largeModel.append({"name": chart.series(i).name
                              ,"show": true
                              ,"linecolor": "red"
                              ,"linethck": 2
                              ,"markerthck":2
                              ,"markercolor": "blue"
                              ,"linedash":"dot"
                              ,"markerdash": "circle"});
    }
}
