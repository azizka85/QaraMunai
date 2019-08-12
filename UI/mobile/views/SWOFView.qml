import QtQuick 2.0
import QtQuick.Controls 2.4
import QtCharts 2.3

Item {
    property Menu swofRightMenu: null
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

            model: [qsTr("ОФП (нефть-вода)"), qsTr("Таблица (нефть-вода)"), qsTr("Настройки")]

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
            id: swofView

            ChartView {
                id: swofChart
                title: qsTr("ОФП и КД (нефть-вода)")
                titleColor: "blue"
                titleFont { pixelSize: 14; bold: true }
                anchors.fill: parent

                legend {
                    visible: true
                    alignment: Qt.AlignBottom
                }

                LineSeries {
                    id: krwSWOF
                    name: qsTr("KrW(SW)")
                }

                LineSeries {
                    id: kroSWOF
                    name: qsTr("KrO(SW)")
                }

                LineSeries {
                    id: pcSWOF
                    name: qsTr("Pc(SW)")
                }
            }
        }

        Item {
            id: swofTable

            ListView {
                id: swofList
                anchors { fill: parent; margins: 4 }
                delegate: itemDelegate
                spacing: 4
            }

            Component {
                id: itemDelegate

                Rectangle {
                    anchors { left: parent.left; right: parent.right; margins: 4 }
                    height: swofColumn.implicitHeight + 12
                    border.width: 1
                    border.color: "lightsteelblue"
                    radius: 12

                    Column {
                        id: swofColumn
                        anchors { fill: parent; margins: 6 }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'SW: '}
                            Text { font.pixelSize: 14; text: modelData.sw }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'KrW: ' }
                            Text { font.pixelSize: 14; text: modelData.krw }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'KrO: ' }
                            Text { font.pixelSize: 14; text: modelData.kro }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'Pc: ' }
                            Text { font.pixelSize: 14; text: modelData.pc }
                        }
                    }
                }
            }
        }

        Item {
            id: swofSettings
        }
    }

    function loadProject(regs)
    {        
        if(regs !== null && regs.length > 0)
        {
            regions = regs;
            regionList.model = regions;
            regionList.currentIndex = 0;
            swofRightMenu = rightMenu;
        }
        else
        {
            regions = null;
            regionList.model = [];
            swofRightMenu = null;
        }
    }

    function closeProject()
    {
        swofList.model = [];

        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
    }

    function prepare(projectData)
    {
        var list = projectData.swof.getList(regionList.currentIndex);

        swofList.model = list;

        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
        }
    }
}
