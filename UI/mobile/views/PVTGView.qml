import QtQuick 2.0
import QtQuick.Controls 2.4
import QtCharts 2.3

Item {
    property Menu pvtgRightMenu: null
    property var regions: null

    anchors.fill: parent

    Menu {
        id: rightMenu
        x: parent.width

        MenuItem {
            id: regionMenu

            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
            }

            Rectangle {
                anchors.fill: parent

                Text {
                    id: regionTitle
                    anchors { left: parent.left; verticalCenter: parent.verticalCenter; margins: 5 }
                    font.pixelSize: 14
                    text: qsTr("Регион: ")
                }

                ComboBox {
                    id: regionList
                    anchors { left: regionTitle.right; right: parent.right; verticalCenter: parent.verticalCenter; margins: 5 }
                    font.pixelSize: 14
                }
            }
        }

        MenuSeparator {
            id: menuSeparator1

            anchors {
                left: parent.left
                right: parent.right
                top: regionMenu.bottom
            }
        }

        ListView {
            id: switchViewMenu
            height: 144

            anchors {
                left: parent.left
                right: parent.right
                top: menuSeparator1.bottom
            }

            model: [qsTr("PVT газа"), qsTr("Таблица (PVT газа)"), qsTr("Настройки")]

            delegate: RadioDelegate {
                width: parent.width
                text: modelData
                checked: index == content.currentIndex
                onClicked: content.currentIndex = index
            }
        }
    }

    SwipeView {
        id: content
        anchors.fill: parent
        currentIndex: 0

        Item {
            id: pvtgView

            ChartView {
                id: pvtgChart
                title: qsTr("PVT газа")
                titleColor: "blue"
                titleFont { pixelSize: 14; bold: true }
                anchors.fill: parent

                legend {
                    visible: true
                    alignment: Qt.AlignBottom
                }

                LineSeries {
                    id: pgPVTG
                    name: qsTr("PG")
                }

                LineSeries {
                    id: bgPVTG
                    name: qsTr("BG")
                }

                LineSeries {
                    id: mgPVTG
                    name: qsTr("MG")
                }
            }
        }

        Item {
            id: pvtgTable

            ListView {
                id: pvtgList
                anchors { fill: parent; margins: 4 }
                delegate: itemDelegate
                spacing: 4
            }

            Component {
                id: itemDelegate

                Rectangle {
                    anchors { left: parent.left; right: parent.right; margins: 4 }
                    height: pvtgColumn.implicitHeight + 12
                    border.width: 1
                    border.color: "lightsteelblue"
                    radius: 12

                    Column {
                        id: pvtgColumn
                        anchors { fill: parent; margins: 6 }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'RV: '}
                            Text { font.pixelSize: 14; text: modelData.rv }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'PG: ' }
                            Text { font.pixelSize: 14; text: modelData.pg }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'BG: ' }
                            Text { font.pixelSize: 14; text: modelData.bg }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'MG: ' }
                            Text { font.pixelSize: 14; text: modelData.mg }
                        }
                    }
                }
            }
        }

        Item {
            id: pvtgSettings
        }
    }

    function loadProject(regs)
    {
        if(regs !== null && regs.length > 0)
        {
            regions = regs;
            regionList.model = regions;
            regionList.currentIndex = 0;
            pvtgRightMenu = rightMenu;
        }
        else
        {
            regions = null;
            regionList.model = [];
            pvtgRightMenu = null;
        }
    }

    function closeProject()
    {
        pvtgList.model = [];

        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();
    }

    function prepare(projectData)
    {
        var list = projectData.pvtg.getList(regionList.currentIndex);

        pvtgList.model = list;

        pgPVTG.clear();
        bgPVTG.clear();
        mgPVTG.clear();

        for(var i = 0; i < list.length; i++)
        {
            pgPVTG.append(list[i].sg, list[i].pg);
            bgPVTG.append(list[i].sg, list[i].bg);
            mgPVTG.append(list[i].sg, list[i].mg);
        }
    }
}
