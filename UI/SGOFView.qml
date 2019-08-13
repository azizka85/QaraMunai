import QtQuick 2.0
import QtQuick.Controls 2.4
import QtCharts 2.3

Item {
    property Menu sgofRightMenu: null
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

            model: [qsTr("ОФП (газ-вода)"), qsTr("Таблица (газ-вода)"), qsTr("Настройки")]

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
            id: sgofView

            ChartView {
                id: sgofChart
                title: qsTr("ОФП и КД (газ-вода)")
                titleColor: "blue"
                titleFont { pixelSize: 14; bold: true }
                anchors.fill: parent

                legend {
                    visible: true
                    alignment: Qt.AlignBottom
                }

                LineSeries {
                    id: krwSGOF
                    name: qsTr("KrG(SG)")
                }

                LineSeries {
                    id: kroSGOF
                    name: qsTr("KrO(SG)")
                }

                LineSeries {
                    id: pcSGOF
                    name: qsTr("Pc(SG)")
                }
            }
        }

        Item {
            id: sgofTable

            ListView {
                id: sgofList
                anchors { fill: parent; margins: 4 }
                delegate: itemDelegate
                spacing: 4
            }

            Component {
                id: itemDelegate

                Rectangle {
                    anchors { left: parent.left; right: parent.right; margins: 4 }
                    height: sgofColumn.implicitHeight + 12
                    border.width: 1
                    border.color: "lightsteelblue"
                    radius: 12

                    Column {
                        id: sgofColumn
                        anchors { fill: parent; margins: 6 }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'SG: '}
                            Text { font.pixelSize: 14; text: modelData.sg }
                        }

                        Row {
                            Text { font.pixelSize: 14; color: "blue"; width: 36; horizontalAlignment: Text.AlignLeft; text: 'KrG: ' }
                            Text { font.pixelSize: 14; text: modelData.krg }
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
            id: sgofSettings
        }
    }

    function loadProject(regs)
    {
        if(regs !== null && regs.length > 0)
        {
            regions = regs;
            regionList.model = regions;
            regionList.currentIndex = 0;
            sgofRightMenu = rightMenu;
        }
        else
        {
            regions = null;
            regionList.model = [];
            sgofRightMenu = null;
        }
    }

    function closeProject()
    {
        sgofList.model = [];

        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();
    }

    function prepare(projectData)
    {
        var list = projectData.sgof.getList(regionList.currentIndex);

        sgofList.model = list;

        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();

        for(var i = 0; i < list.length; i++)
        {
            krgSGOF.append(list[i].sg, list[i].krg);
            kroSGOF.append(list[i].sg, list[i].kro);
            pcSGOF.append(list[i].sg, list[i].pc);
        }
    }
}
