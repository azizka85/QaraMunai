import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3



Item {
        anchors.fill: parent

        ComboBox {
            id: dateComboBox
            anchors { left: tabview.left; top: parent.top; topMargin: 30 }
            width: (parent.width - 80) / 2.5
            height: 30
        }

        Row {
            spacing: 20
            anchors { verticalCenter: dateComboBox.verticalCenter; right: parent.right; rightMargin: 10; left: dateComboBox.right; leftMargin: 20}
            Button {
                text: "Экспорт"
                id: exportButton
                height: dateComboBox.height
                width: Math.max(text.width, (parent.width - 40) / 3);
            }

            Button {
                text:  "Применить"
                id: applyButton
                height: dateComboBox.height
                width:  (parent.width - 40) / 3;
            }

            Button {
                text:  "Отменить"
                id: cancelButton
                height: dateComboBox.height
                width:  (parent.width - 40) / 3;
            }
        }


        TabView {
            id: tabview
            anchors { top: dateComboBox.bottom; bottom: parent.bottom; left: parent.left; right: parent.right;
                topMargin: 10; bottomMargin: 10; leftMargin: 10; rightMargin: 10}
            width: dateComboBox.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            Tab {
                id: wellSpecsTab
                title: "WELLSPECS"}
            Tab {
                id: compdatTab
                title: "COMPDAT" }
            Tab {
                id: wconprodTab
                title: "WCONPROD" }
            Tab {
                id: wconinjeTab
                title: "WCONINJE" }

            style: TabViewStyle {
                frameOverlap: 1
                tab: Rectangle {
                    color: styleData.selected ? "steelblue" :"lightsteelblue"
                    border.color:  "steelblue"
                    implicitWidth: Math.max(text.width + 8, dateComboBox.width / 4)
                    implicitHeight: 20
                    radius: 4
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: styleData.selected ? "white" : "black"
                    }
                }
                frame: Rectangle { color: "steelblue" }
            }
        }

    TableView {
        parent: wellSpecsTab
        id: wellSpecsTable
        anchors.fill:  parent
        TableViewColumn {

            role: "wellName"
            title: "WellName"
            width: 100
        }

        TableViewColumn {
            role: "wellGroup"
            title: "WellGroup"
            width: 100
        }

        TableViewColumn {
            role: "i"
            title: "I"
            width: 100
        }

        TableViewColumn {
            role: "j"
            title: "J"
            width: 100
        }
    }

    TableView {
        parent: compdatTab
        id: compdatTable
        anchors.fill:  parent
        width: parent.width

        TableViewColumn {
            role: "wellName"
            title: "WellName"
            width: 100
        }

        TableViewColumn {
            role: "k1"
            title: "K2"
            width: 100
        }

        TableViewColumn {
            role: "k2"
            title: "K2"
            width: 100
        }

        TableViewColumn {
            role: "wellStatus"
            title: "WellStatus"
            width: 100
        }

        TableViewColumn {
            role: "tranFactor"
            title: "TranFactor"
            width: 100
        }

        TableViewColumn {
            role: "diameter"
            title: "Diameter"
            width: 100
        }

        TableViewColumn {
            role: "kh"
            title: "Kh"
            width: 100
        }

        TableViewColumn {
            role: "skinFactor"
            title: "SkinFactor"
            width: 100
        }
    }

    TableView {
        anchors.fill:  parent
        parent: wconprodTab
        id: wconprodTable
        width: parent.width

        TableViewColumn {
            role: "wellName"
            title: "WellName"
            width: 100
        }

        TableViewColumn {
            role: "wellStatus"
            title: "WellStatus"
            width: 100
        }

        TableViewColumn {
            role: "wellControl"
            title: "Control"
            width: 100
        }

        TableViewColumn {
            role: "orat"
            title: "ORAT"
            width: 100
        }


        TableViewColumn {
            role: "wrat"
            title: "WRAT"
            width: 100
        }

        TableViewColumn {
            role: "grat"
            title: "GRAT"
            width: 100
        }

        TableViewColumn {
            role: "lrat"
            title: "LRAT"
            width: 100
        }

        TableViewColumn {
            role: "resv"
            title: "RESV"
            width: 100
        }

        TableViewColumn {
            role: "bhp"
            title: "BHP"
            width: 100
        }
    }

    TableView {
        anchors.fill:  parent
        parent: wconinjeTab
        id: wconinjeTable
        width: parent.width

        TableViewColumn {
            role: "wellName"
            title: "WellName"
            width: 100
        }

        TableViewColumn {
            role: "wellStatus"
            title: "WellStatus"
            width: 100
        }

        TableViewColumn {
            role: "wellControl"
            title: "Control"
            width: 100
        }

        TableViewColumn {
            role: "injFluid"
            title: "InjFluid"
            width: 100
        }


        TableViewColumn {
            role: "rate"
            title: "RATE"
            width: 100
        }

        TableViewColumn {
            role: "resv"
            title: "RESV"
            width: 100
        }

        TableViewColumn {
            role: "bhp"
            title: "BHP"
            width: 100
        }
    }

    function closeProject()
    {
        wellSpecsTab.children[0].model = [];
        compdatTab.children[0].model = [];
        wconprodTab.children[0].model = [];
        wconinjeTab.children[0].model = [];
    }

    function prepare(projectData)
    {
        dateComboBox.model = projectData.datelist;
        wellSpecsTab.children[0].model = projectData.welspecs.getList();
        compdatTab.children[0].model = projectData.compdat.getList();
        wconprodTab.children[0].model = projectData.wconprod.getList();
        wconinjeTab.children[0].model = projectData.wconinje.getList();

    }
}
