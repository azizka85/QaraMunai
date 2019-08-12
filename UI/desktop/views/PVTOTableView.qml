import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    TableView {
        id: pvtoList
        anchors.fill: parent

        TableViewColumn {
            role: "rs"
            title: "RS"
            width: 100
        }

        TableViewColumn {
            role: "po"
            title: "PO"
            width: 100
        }

        TableViewColumn {
            role: "bo"
            title: "BO"
            width: 100
        }

        TableViewColumn {
            role: "mo"
            title: "MO"
            width: 100
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
