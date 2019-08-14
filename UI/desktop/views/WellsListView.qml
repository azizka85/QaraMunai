import QtQuick 2.0
import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    Button {
        id: addGroupButton
        height: 30
        width: (parent.width - 30)/2
        anchors { left: parent.left; margins: 10 }
        text: "+Группа"
    }

    Button {
        id: addWellButton
        height: 30
        width: (parent.width - 30)/2
        anchors { right: parent.right; margins: 10 }
        text: "+Скважина"
    }



    function closeProject(){
    }

    function prepare(projectData){
    }
}
