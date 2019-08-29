import QtQuick 2.0

Item {
    property var i: 0
    property alias list: listElement
    property bool running: false
    property var callbackPrepare: null
    function next(){
        for(i = 0; i < 100; i++){
            listElement.append({"index": i, "sin": Math.sin(i), "cos": Math.cos(i),
                                   "exp": Math.exp(i), "xx": Math.pow(i, 2), "log": Math.log(i)});
            console.log(i+")"+Math.pow(i, 2))
            iPropChanged();
        }
    }
    signal iPropChanged
    ListModel {
        id: listElement
    }
}
