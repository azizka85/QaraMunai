import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: pvtgList
        anchors.fill: parent

        TableViewColumn {
            role: "pg"
            title: "P"
            width: pvtgList.width/3
            resizable: false
        }

        TableViewColumn {
            role: "bg"
            title: "Bg"
            width: pvtgList.width/3
            resizable: false
        }

        TableViewColumn {
            role: "mg"
            title: "Mg"
            width: pvtgList.width/3
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
