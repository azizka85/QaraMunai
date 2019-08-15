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
        width: (parent.width - 60)/2
        anchors { left: parent.left; margins: 10; leftMargin: 20; topMargin: 30; top:parent.top }
        text: "+Группа"
    }

    Button {
        id: addWellButton
        height: 30
        width: (parent.width - 60)/2
        anchors { right: parent.right; margins: 10; rightMargin: 20; topMargin: 30; top:parent.top }
        text: "+Скважина"
    }

    TreeView {
        id: treeView
        anchors { top: addGroupButton.bottom; left:  parent.left; right: parent.right; bottom: parent.bottom;
                  topMargin: 30;  margins: 20 }

        TableViewColumn {
            id: groupNodes
            title: "groupNodes"
        }

        TableViewColumn {
            id: wellNodes
            title: "wellNodes"
        }
    }

    function closeProject(){
        treeView.model = [];
    }

    function prepare(projectData){
        var resource = projectData.welspecs.getList();

        var groupLis = [];
        for(let i = 0; i< resource.length; i++){
            if(resource[i].)
        }
    }

}
