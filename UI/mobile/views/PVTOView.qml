import QtQuick 2.0
import QtQuick.Controls 2.4
import QtCharts 2.3

Item {
    property Menu pvtoRightMenu: null
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

            model: [qsTr("PVT нефти"), qsTr("Таблица (PVT нефти)"), qsTr("Настройки")]

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
            id: pvtoView

            ChartView {
                id: pvtoChart
                title: qsTr("PVT нефти")
                titleColor: "blue"
                titleFont { pixelSize: 14; bold: true }
                anchors.fill: parent

                legend {
                    visible: true
                    alignment: Qt.AlignBottom
                }

                LineSeries {
                    id: poPVTO
                    name: qsTr("PO")
                }

                LineSeries {
                    id: boPVTO
                    name: qsTr("BO")
                }

                LineSeries {
                    id: moPVTO
                    name: qsTr("MO")
                }
            }
        }

        Item {
            id: pvtoTable

            ListView {
                id: pvtoList
                anchors { fill: parent; margins: 4 }
                delegate: itemDelegate
                spacing: 4
            }

            Component {
                id: itemDelegate

                Rectangle {
                    anchors { left: parent.left; right: parent.right; margins: 4 }
                    height: pvtoColumn.implicitHeight + 12
                    border.width: 1
                    border.color: "lightsteelblue"
                    radius: 12

                    Column {
                        id: pvtoColumn
                        anchors { fill: parent; margins: 6 }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'RS: '}
                            Text { font.pixelSize: 14; text: modelData.rs }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'PO: ' }
                            Text { font.pixelSize: 14; text: modelData.po }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'BO: ' }
                            Text { font.pixelSize: 14; text: modelData.bo }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'MO: ' }
                            Text { font.pixelSize: 14; text: modelData.mo }
                        }
                    }
                }
            }
        }

        Item {
            id: pvtoSettings
        }
    }

    function loadProject(regs)
    {
        if(regs !== null && regs.length > 0)
        {
            regions = regs;
            regionList.model = regions;
            regionList.currentIndex = 0;
            pvtoRightMenu = rightMenu;
        }
        else
        {
            regions = null;
            regionList.model = [];
            pvtoRightMenu = null;
        }
    }

    function closeProject()
    {
        pvtoList.model = [];

        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();
    }

    function prepare(projectData)
    {
        var list = projectData.pvto.getList(regionList.currentIndex);

        pvtoList.model = list;

        poPVTO.clear();
        boPVTO.clear();
        moPVTO.clear();

        for(var i = 0; i < list.length; i++)
        {
            poPVTO.append(list[i].sg, list[i].po);
            boPVTO.append(list[i].sg, list[i].bo);
            moPVTO.append(list[i].sg, list[i].mo);
        }
    }
}
