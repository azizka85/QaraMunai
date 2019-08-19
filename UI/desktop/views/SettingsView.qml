import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window{
    visible: false
    width: 500
    height: 150
    title: qsTr("Настройка графиков")
    TableView {
        id: settings
        anchors.fill: parent

        TableViewColumn {
            role: "name"
            title: "Название"
            width: 60
        }

        TableViewColumn {
            role: "show"
            title: "Отображение"
            width: 80
        }

        TableViewColumn {
            role: "linecolor"
            title: "Цвет \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "linethck"
            title: "Толщина \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "linedash"
            title: "Тип \nлинии"
            width: 60
        }

        TableViewColumn {
            role: "markercolor"
            title: "Цвет \nмаркера"
            width: 60
        }

        TableViewColumn {
            role: "markerthck"
            title: "Толщина \nмаркера"
            width: 60
        }

        TableViewColumn {
            role: "markerdash"
            title: "Тип \nмаркера"
            width: 60
        }
    }
}

