import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: sgofList
        anchors.fill: parent

        TableViewColumn {
            role: "sg"
            title: "SG"
            width: 100
        }

        TableViewColumn {
            role: "krg"
            title: "KrG"
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
        sgofList.model = [];
    }

    function prepare(list)
    {
        sgofList.model = list;
    }

}
