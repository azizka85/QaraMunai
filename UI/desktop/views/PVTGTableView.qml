import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: pvtgList
        anchors.fill: parent

        TableViewColumn {
            role: "rv"
            title: "RV"
            width: pvtgList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "pg"
            title: "PG"
            width: pvtgList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "bg"
            title: "BG"
            width: pvtgList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "mg"
            title: "MG"
            width: pvtgList.width/4
            resizable: false
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
