import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4 as C2
import QaraMunai.Drawers 1.0

C1.SplitView {
    property real ratio: 0.8
    property bool settingsVisible: false

    id: fieldSplit
    anchors.fill: parent
    orientation: Qt.Horizontal

    Item {
        id: field
        width: parent.width
        height: parent.height

        FieldSceneDrawer {
            id: drawer
            width: parent.width
            height: parent.height

            onSelectedValueChanged: console.log(drawer.selectedValue)

            MouseArea {
                property vector2d localPosition

                anchors.fill: parent

                onPressed: {
                    if(mouse.buttons === Qt.LeftButton) {
                        drawer.mousePosition = Qt.vector2d(mouse.x, mouse.y);
                        localPosition = drawer.mousePosition;
                    }

                    mouse.accepted = true;
                }

                onPositionChanged: {
                    if(mouse.buttons !== Qt.LeftButton) return;

                    var position = Qt.vector2d(mouse.x, mouse.y);

                    drawer.mouseDisplacement = Qt.vector2d(position.x - localPosition.x, localPosition.y - position.y);

                    localPosition = position;

                    mouse.accepted = true;
                }

                onWheel: {
                    if(wheel.angleDelta.y > 0)
                        drawer.zLocation += 0.25;
                    else if(wheel.angleDelta.y < 0)
                        drawer.zLocation -= 0.25;

                    wheel.accepted = true;
                }
            }
        }

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

        C2.ScrollView {
            anchors { top: parent.top; bottom: parent.bottom; left:  parent.left; right: parent.right; margins: 10 }
            clip: true

            Column {
                spacing: 6

                Text {
                    id: fieldsLabel
                    font.pixelSize: 12
                    text: "Список полей"
                }

                Row {
                    id: initGroupRow
                    spacing: 6

                    Text {
                        text: initFieldsList.visible ? "-" : "+"
                        color: "blue"

                        MouseArea {
                            anchors.fill: parent

                            onClicked: initFieldsList.visible = !initFieldsList.visible
                        }
                    }

                    Text {
                        text: "Начальные данные"
                        color: initGroupArea.containsMouse ? "orange" : "blue"
                        font.bold: true

                        MouseArea {
                            id: initGroupArea
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: initFieldsList.visible = !initFieldsList.visible
                        }
                    }
                }

                Column {
                    id: initFieldsList
                    spacing: 6

                    Repeater {
                        id: initFieldsRepeater

                        delegate: Text {
                            leftPadding: 12
                            text: modelData.title
                            color: initFieldArea.containsMouse ? "red" : "blue"

                            MouseArea {
                                id: initFieldArea
                                anchors.fill: parent
                                hoverEnabled: true
                            }
                        }
                    }
                }

                Row {
                    id: calcGroupRow
                    spacing: 6

                    Text {
                        text: calcFieldsList.visible ? "-" : "+"
                        color: "green"

                        MouseArea {
                            anchors.fill: parent

                            onClicked: calcFieldsList.visible = !calcFieldsList.visible
                        }
                    }

                    Text {
                        text: "Рассчитаные данные"
                        color: calcGroupArea.containsMouse ? "orange" : "green"
                        font.bold: true

                        MouseArea {
                            id: calcGroupArea
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: calcFieldsList.visible = !calcFieldsList.visible
                        }
                    }
                }

                Column {
                    id: calcFieldsList
                    spacing: 6

                    Repeater {
                        id: calcFieldsRepeater

                        delegate: Text {
                            leftPadding: 12
                            text: modelData.title
                            color: calcFieldArea.containsMouse ? "red" : "green"

                            MouseArea {
                                id: calcFieldArea
                                anchors.fill: parent
                                hoverEnabled: true
                            }
                        }
                    }
                }
            }
        }
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

    function closeProject()
    {
        initFieldsRepeater.model = [];
        calcFieldsRepeater.model = [];
    }

    function prepare(projectData)
    {
        var fields = drawer.getFields();

        initFieldsRepeater.model = fields;

        var calcFields = drawer.getCalcFields();

        var data = [];

        calcFields.forEach(function(ind) {
            data.push(fields[ind]);
        });

        calcFieldsRepeater.model = data;
    }
}
