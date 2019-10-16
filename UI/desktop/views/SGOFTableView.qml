import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: sgofTable
        anchors.fill: parent
        model: sgofList

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

    ListModel {
        id: sgofList
    }

    function closeProject()
    {
        sgofList.clear();
    }

    function prepare(list)
    {
        sgofList.clear();
        sgofList.append(list);
    }

}
