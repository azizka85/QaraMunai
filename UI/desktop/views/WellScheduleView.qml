import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4 as C2
import QtQuick.Layouts 1.3

Item {    
    anchors.fill: parent

    Item {
        property var projectData: null

        id: privateItem
        visible: false
    }

    C2.ComboBox {
        id: datesComboBox
        anchors { left: parent.left; top: parent.top; margins: 10; }
        width: (parent.width - 80) / 2.5
        height: 30

        onCurrentTextChanged: {
            var dateStr = datesComboBox.currentText;
            var date = Date.fromLocaleDateString(Qt.locale(), dateStr, "dd.MM.yyyy");

            wellSpecsTable.model = projectData.welspecs.getList(date);
            compdatTable.model = projectData.compdat.getList(date);
            wconprodTable.model = projectData.wconprod.getList(date);
            wconinjeTable.model = projectData.wconinje.getList(date);
        }
    }

    Row {
        spacing: 20
        anchors { verticalCenter: datesComboBox.verticalCenter; right: parent.right; left: datesComboBox.right; margins: 10; }

        C2.Button {
            text: qsTr("Экспорт")
            id: exportButton
            height: datesComboBox.height
            width: Math.max(text.width, (parent.width - 40) / 3);
        }

        C2.Button {
            text:  qsTr("Применить")
            id: applyButton
            height: datesComboBox.height
            width:  (parent.width - 40) / 3;
        }

        C2.Button {
            text:  qsTr("Отменить")
            id: cancelButton
            height: datesComboBox.height
            width:  (parent.width - 40) / 3;
        }
    }


    C2.TabBar {
        id: tabBar
        anchors { top: datesComboBox.bottom; left: parent.left; margins: 10 }

        C2.TabButton {
            id: wellSpecsTab
            text: qsTr("WELLSPECS")
            width: 100
        }

        C2.TabButton {
            id: compdatTab
            text: qsTr("COMPDAT")
            width: 100
        }

        C2.TabButton {
            id: wconprodTab
            text: qsTr("WCONPROD")
            width: 100
        }

        C2.TabButton {
            id: wconinjeTab
            text: qsTr("WCONINJE")
            width: 100
        }
    }

    StackLayout {
        id: tabContent
        anchors { top: tabBar.bottom; left: parent.left; right: parent.right; bottom: parent.bottom; leftMargin: 10; rightMargin: 10; }
        currentIndex: tabBar.currentIndex

        C1.TableView {
            id: wellSpecsTable
            width: parent.width
            height: parent.height

            C1.TableViewColumn {

                role: "wellName"
                title: "WellName"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellGroup"
                title: "WellGroup"
                width: 100
            }

            C1.TableViewColumn {
                role: "i"
                title: "I"
                width: 100
            }

            C1.TableViewColumn {
                role: "j"
                title: "J"
                width: 100
            }
        }

        C1.TableView {
            id: compdatTable
            width: parent.width
            height: parent.height

            C1.TableViewColumn {
                role: "wellName"
                title: "WellName"
                width: 100
            }

            C1.TableViewColumn {
                role: "k1"
                title: "K1"
                width: 100
            }

            C1.TableViewColumn {
                role: "k2"
                title: "K2"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellStatus"
                title: "WellStatus"
                width: 100
            }

            C1.TableViewColumn {
                role: "tranFactor"
                title: "TranFactor"
                width: 100
            }

            C1.TableViewColumn {
                role: "diameter"
                title: "Diameter"
                width: 100
            }

            C1.TableViewColumn {
                role: "kh"
                title: "Kh"
                width: 100
            }

            C1.TableViewColumn {
                role: "skinFactor"
                title: "SkinFactor"
                width: 100
            }
        }

        C1.TableView {
            id: wconprodTable
            width: parent.width
            height: parent.height

            C1.TableViewColumn {
                role: "wellName"
                title: "WellName"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellStatus"
                title: "WellStatus"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellControl"
                title: "Control"
                width: 100
            }

            C1.TableViewColumn {
                role: "orat"
                title: "ORAT"
                width: 100
            }


            C1.TableViewColumn {
                role: "wrat"
                title: "WRAT"
                width: 100
            }

            C1.TableViewColumn {
                role: "grat"
                title: "GRAT"
                width: 100
            }

            C1.TableViewColumn {
                role: "lrat"
                title: "LRAT"
                width: 100
            }

            C1.TableViewColumn {
                role: "resv"
                title: "RESV"
                width: 100
            }

            C1.TableViewColumn {
                role: "bhp"
                title: "BHP"
                width: 100
            }
        }

        C1.TableView {
            id: wconinjeTable
            width: parent.width
            height: parent.height

            C1.TableViewColumn {
                role: "wellName"
                title: "WellName"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellStatus"
                title: "WellStatus"
                width: 100
            }

            C1.TableViewColumn {
                role: "wellControl"
                title: "Control"
                width: 100
            }

            C1.TableViewColumn {
                role: "injFluid"
                title: "InjFluid"
                width: 100
            }


            C1.TableViewColumn {
                role: "rate"
                title: "RATE"
                width: 100
            }

            C1.TableViewColumn {
                role: "resv"
                title: "RESV"
                width: 100
            }

            C1.TableViewColumn {
                role: "bhp"
                title: "BHP"
                width: 100
            }
        }
    }

    function closeProject()
    {
        datesComboBox.model = [];
        wellSpecsTable.model = [];
        compdatTable.model = [];
        wconprodTable.model = [];
        wconinjeTable.model = [];
    }

    function prepare(projectData)
    {
        privateItem.projectData = projectData;

        datesComboBox.model = projectData.dates;
    }
}
