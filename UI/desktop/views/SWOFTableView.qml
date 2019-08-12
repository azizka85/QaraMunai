import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: swofList
        anchors.fill: parent

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

    function closeProject()
    {
        swofList.model = [];
    }

    function prepare(list)
    {
        swofList.model = list;
    }

}
