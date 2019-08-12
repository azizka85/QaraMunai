import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.13



Item {
    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        ComboBox {
            id: dateComboBox
            height: 30
            width: 300
            //anchors.margins: 10
            x: 20
            y: 100
        }

        TabView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Tab {
                id: wellSpecsTab
                title: "Tab 1"
            }
            Tab {
                id: compdatTab
                title: "Tab 2" }
            Tab {
                id: wconprodTab
                title: "Tab 3" }
            Tab {
                id: wconinjeTab
                title: "Tab 3" }

            style: TabViewStyle {
                frameOverlap: 1
                tab: Rectangle {
                    color: styleData.selected ? "steelblue" :"lightsteelblue"
                    border.color:  "steelblue"
                    implicitWidth: Math.max(text.width + 4, 80)
                    implicitHeight: 20
                    radius: 2
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
    }

    TableView {
        parent: wellSpecsTab
        id: wellSpecsTable
        width: parent.width
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
        wellSpecsTab.children[0].model = projectData.welspecs.getList();
        compdatTab.children[0].model = projectData.compdat.getList();
        wconprodTab.children[0].model = projectData.wconprod.getList();
        wconinjeTab.children[0].model = projectData.wconinje.getList();

    }
}