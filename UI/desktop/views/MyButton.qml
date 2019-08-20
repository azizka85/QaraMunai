import QtQuick 2.13
Rectangle {
    property string iconSource: icon.source
    property string title: title.text
    property Image icon: icon


    id: button
    width: 64
    height: 64
    radius: 2;
    gradient: nonPressedGradient
    border {width: 1; color: "black"}
    Gradient{
        id: nonPressedGradient
        GradientStop { position: 0.0; color: "white" }
        GradientStop { position: 1.0; color: "lightgray" }
    }

    Gradient{
        id: pressedGradient
        GradientStop { position: 0.0; color: "lightgray" }
        GradientStop { position: 1.0; color: "white" }
    }

    Image {
        id: icon
        source: "qrc:/desktop/images/flow_rate.png"
        anchors { top: button.top; topMargin: 2; horizontalCenter: button.horizontalCenter }
    }
    Text {
        id: title
        text: "dhrdths"
        anchors { top: icon.bottom; left: icon.left; right: icon.right; topMargin: 2;  }
    }

    MouseArea {
        anchors.fill: parent;
        onPressed: gradient = pressedGradient;
        onReleased: gradient = nonPressedGradient
    }
}
