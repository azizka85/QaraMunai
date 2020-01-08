import QtQuick 2.12
import QtQuick.Controls 1.4

Item {

    Button {
        id: addGroupButton
        height: 30
        width: (parent.width - 30)/2
        anchors { left: parent.left; margins: 10; top: parent.top }
        text: "+Группа"
    }

    Button {
        id: addWellButton
        height: 30
        width: (parent.width - 30)/2
        anchors { right: parent.right; margins: 10; top: parent.top }
        text: "+Скважина"
    }

    ScrollView {
        anchors { top: addGroupButton.bottom; bottom: parent.bottom; left:  parent.left; right: parent.right; margins: 10 }
        clip: true

        Column {
            spacing: 6

            Repeater {
                id: groupsList

                delegate: Column {
                    spacing: 6

                    Row {
                        id: groupRow
                        spacing: 6

                        Text {
                            visible: modelData.nodes.length > 0
                            text: nodesList.visible ? "-" : "+"

                            MouseArea {
                                anchors.fill: parent

                                onClicked: nodesList.visible = !nodesList.visible
                            }
                        }

                        Text {
                            text: modelData.group
                            color: groupArea.containsMouse ? "orange" : "black"

                            MouseArea {
                                id: groupArea
                                anchors.fill: parent
                                hoverEnabled: true

                                onClicked: nodesList.visible = !nodesList.visible
                            }
                        }

                    }

                    Column {
                        id: nodesList
                        spacing: 6

                        Repeater {
                            model: modelData.nodes

                            delegate: Text {
                                leftPadding: 12
                                text: modelData.wellName
                                color: nodeArea.containsMouse ? "red" : "black"

                                MouseArea {
                                    id: nodeArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    function closeProject()
    {
        groupsList.model = [];
    }

    function prepare(projectData)
    {
        var groups = projectData.welspecs.getData();

        var treeModel = [];

        for(var group in groups)
        {
            treeModel.push({ group: group, nodes: groups[group] });
        }

        groupsList.model = treeModel;
    }
}
