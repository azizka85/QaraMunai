import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: sgofList
        anchors.fill: parent

        TableViewColumn {
            role: "sg"
            title: "Sg"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "krg"
            title: "Krg"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "kro"
            title: "Krog"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "pc"
            title: "Pcog"
            width: sgofList.width/4
            resizable: false
        }
    }

    function closeProject()
    {
        sgofList.model = [];
    }

    function prepare(list)
    {
        sgofList.model = list;
    }

}
