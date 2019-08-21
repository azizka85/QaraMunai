import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: pvtoList
        anchors.fill: parent

        TableViewColumn {
            role: "rs"
            title: "RS"
            width: pvtoList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "po"
            title: "PO"
            width: pvtoList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "bo"
            title: "BO"
            width: pvtoList.width/4
            resizable: false
        }

        TableViewColumn {
            role: "mo"
            title: "MO"
            width: pvtoList.width/4
            resizable: false
        }
    }

    function closeProject()
    {
        pvtoList.model = [];
    }

    function prepare(list)
    {
        pvtoList.model = list;
    }

}
