import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: pvtgList
        anchors.fill: parent

        TableViewColumn {
            role: "rv"
            title: "RV"
            width: 100
        }

        TableViewColumn {
            role: "pg"
            title: "PG"
            width: 100
        }

        TableViewColumn {
            role: "bg"
            title: "BG"
            width: 100
        }

        TableViewColumn {
            role: "mg"
            title: "MG"
            width: 100
        }
    }

    function closeProject()
    {
        pvtgList.model = [];
    }

    function prepare(list)
    {
        pvtgList.model = list;
    }

}
