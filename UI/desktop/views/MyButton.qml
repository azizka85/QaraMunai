import QtQuick 2.13
import QtQuick.Controls 2.5

Button {
    id: button
    width: 56
    height: 56
    background: Rectangle {
        color: pressed ? '#aaaaaa' : hovered || checked ? '#bbbbbb' : 'transparent'
        border.color: checked && hovered ? '#383838' : "transparent"
        border.width: 1
    }
}
