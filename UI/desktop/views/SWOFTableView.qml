import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: swofList
        anchors.fill: parent

        TableViewColumn {
            role: "sw"
            title: "Sw"
            width: swofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "krw"
            title: "Krw"
            width: swofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "kro"
            title: "Krow"
            width: swofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "pc"
            title: "Pcow"
            width: swofList.width/4
            resizable: false
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
