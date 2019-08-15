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
            role: "group"
            id: groupNodes
            title: "groupNodes"
        }

        TableViewColumn {
            role: "well"
            id: wellNodes
            title: "wellNodes"
        }
    }

    function closeProject(){
        treeView.model = [];
    }

    function prepare(projectData){
        console.log("Preparing started");
        var wellsList = projectData.welspecs.getList(); // Works
        var groupList = [];
        var result = [];
        for(let i = 0; i < wellsList.length; i++){
            var group = wellsList[i].wellGroup;
            if(!groupList.includes(group)) {
                groupList.push(group);
                var wells = [];
                for(let j = 0; j < wellsList.length; j++){
                    var res = wellsList[j].wellGroup === group;
                    if(res){
                        wells.push(wellsList[j].wellName);
                    }
                }
                result.push({ "group": group, "well": wells});
            }
        }
        treeView.model = result;    // works
    }

    function contains(arr, elem) {
        var res = arr.find((i) => i === elem) !== -1
        console.log("Comparing" + res);
        return res;
    }
}
