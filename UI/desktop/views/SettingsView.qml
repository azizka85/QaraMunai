import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window{
    visible: false
    width: 700
    height: 200
    title: qsTr("Настройка графиков")
    TableView {
        id: settings
        anchors.fill: parent

        TableViewColumn {
            role: "name"
            title: "Название"
            width: 90
        }

        TableViewColumn {
            role: "show"
            title: "Отображение"
            width: 90
        }

        TableViewColumn {
            role: "linecolor"
            title: "Цвет линии"
            width: 90
        }

        TableViewColumn {
            role: "linethck"
            title: "Толщина линии"
            width: 80
        }

        TableViewColumn {
            role: "linedash"
            title: "Тип линии"
            width: 90
        }

        TableViewColumn {
            role: "markercolor"
            title: "Цвет маркера"
            width: 90
        }

        TableViewColumn {
            role: "markerthck"
            title: "Толщина маркера"
            width: 80
        }

        TableViewColumn {
            role: "markerdash"
            title: "Тип маркера"
            width: 90
        }
    }
}
