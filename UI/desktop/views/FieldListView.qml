import QtQuick 2.0
import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    Column {
        spacing:20
        Text {
            id: kartaText
            text: qsTr("Карты")
//            anchors { left: parent.left; leftMargin: 20; topMargin: 20 }
        }

        GroupBox {
            id: grop
            title: qsTr("Карты")
//            Layout.fillWidth: true
//            anchors {/*right: parent.right; left: parent.left;*/ rightMargin: 20; leftMargin: 20; topMargin: 20; }
            Row {
                spacing: 200
                ExclusiveGroup { id: tabPositionGroup }
                RadioButton {
                    text: "Начальный"
                    width: (grop.width-60)/2
                    checked: true
                    exclusiveGroup: tabPositionGroup
                }

                RadioButton {
                    text: "Расчитанный"
                    width: (grop.width-60)/2
                    checked: false
                    exclusiveGroup: tabPositionGroup
                }
            }
        }

        ListView {
            id: listView
//            anchors { right: parent.right; left: parent.left;/* topMargin: 20;*/ rightMargin: 20; leftMargin: 20 }
            height: 200
            width: 180;
            Component {
                id: contactsDelegate
                Rectangle {
                    id: wrapper
                    width: 180
                    height: contactInfo.height
                    color: ListView.isCurrentItem ? "black" : "red"
                    Text {
                        id: contactInfo
                        text: wellName + ": "
                        color: wrapper.ListView.isCurrentItem ? "red" : "black"
                    }
                }
            }

            delegate: contactsDelegate
            focus: true
        }

        Item {
            id: fasef
            Text {
                id: name
                text: qsTr("tex00000000000000000000000000000000000000000000000000000000000000000000000t")
            }
        }
    }
    function closeProject()
    {
        listView.model = [];
    }

    function prepare(projectData)
    {
        listView.model = projectData.welspecs;
    }
}

