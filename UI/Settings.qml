import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

ApplicationWindow {
    property bool dockTitleVisible: true

    id: settingsWindow
    visible: true
    visibility: "Maximized"
    title: qsTr("Настройка графиков")

    Item {
        TableView {
            id: settingsList
            anchors.fill: parent

            TableViewColumn {
                role: "sw"
                title: "Название"
                width: 100
            }
            function closeProject()
            {
                swofList.model = [];
            }

            function prepare(list)
            {
                swofList.model = list;
            }

    }

   }
}
