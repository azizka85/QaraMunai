import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: swofTable
        anchors.fill: parent
        model: swofList

        TableViewColumn {
            role: "sw"
            title: "SW"
            width: 100
        }

        TableViewColumn {
            role: "krw"
            title: "KrW"
            width: 100
        }

        TableViewColumn {
            role: "kro"
            title: "KrO"
            width: 100
        }

        TableViewColumn {
            role: "pc"
            title: "Pc"
            width: 100
        }
    }

    ListModel {
        id: swofList
    }

    function closeProject()
    {
        swofList.clear();
    }

    function prepare(list)
    {
        swofList.clear();
        swofList.append(list);
    }

}
