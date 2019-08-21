import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: sgofList
        anchors.fill: parent

        TableViewColumn {
            role: "sg"
            title: "SG"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "krg"
            title: "KrG"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "kro"
            title: "KrO"
            width: sgofList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "pc"
            title: "Pc"
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
