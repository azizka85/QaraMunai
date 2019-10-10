import QtQuick 2.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4 as C2
import QaraMunai.Drawers 1.0

C1.SplitView {
    property real ratio: 0.8
    property bool settingsVisible: false

    property alias showContour: drawer.showContour
    property alias showMesh: drawer.showMesh

    id: fieldSplit
    anchors.fill: parent
    orientation: Qt.Horizontal

    Item {
        id: field
        width: parent.width
        height: parent.height

        FieldSceneDrawer {
            id: drawer
            width: parent.width
            height: parent.height
            showContour: cbShowContour.checked
            showMesh: cbShowMesh.checked
            transparent: cbTransparent.checked
            lighting: cbLighting.checked
            axisOfRotation: cbRotationAxis.model[cbRotationAxis.currentIndex].value

            onSelectedValueChanged: console.log(drawer.selectedValue)

            MouseArea {
                property vector2d localPosition

                anchors.fill: parent

                onPressed: {
                    if(mouse.buttons === Qt.LeftButton) {
                        drawer.mousePosition = Qt.vector2d(mouse.x, mouse.y);
                        localPosition = drawer.mousePosition;
                    }

                    mouse.accepted = true;
                }

                onPositionChanged: {
                    if(mouse.buttons !== Qt.LeftButton) return;

                    var position = Qt.vector2d(mouse.x, mouse.y);

                    drawer.mouseDisplacement = Qt.vector2d(position.x - localPosition.x, localPosition.y - position.y);

                    localPosition = position;

                    mouse.accepted = true;
                }

                onWheel: {
                    if(wheel.angleDelta.y > 0)
                        drawer.zLocation += 0.25;
                    else if(wheel.angleDelta.y < 0)
                        drawer.zLocation -= 0.25;

                    wheel.accepted = true;
                }
            }
        }

        Image {
            anchors { right: parent.right; top: parent.top; topMargin: 10; }
            source: settingsVisible ? "qrc:/desktop/images/icon-right-24x24.png" : "qrc:/desktop/images/icon-left-24x24.png"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    settingsVisible = !settingsVisible;
                    resizeItems();
                }
            }
        }
    }

    Rectangle {
        id: settings
        visible: settingsVisible
        border { width: 1; color: "lightgray" }

        C2.ScrollView {
            id: settingsContent
            anchors { top: parent.top; bottom: parent.bottom; left:  parent.left; right: parent.right; margins: 10 }
            clip: true

            Column {
                spacing: 6

                Text {
                    id: fieldsLabel
                    font.pixelSize: 12
                    text: "Список полей"
                }

                Row {
                    id: initGroupRow
                    spacing: 6

                    Text {
                        text: initFieldsList.visible ? "-" : "+"
                        color: "blue"

                        MouseArea {
                            anchors.fill: parent

                            onClicked: initFieldsList.visible = !initFieldsList.visible
                        }
                    }

                    Text {
                        text: "Начальные данные"
                        color: initGroupArea.containsMouse ? "orange" : "blue"
                        font.bold: true

                        MouseArea {
                            id: initGroupArea
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: initFieldsList.visible = !initFieldsList.visible
                        }
                    }
                }

                Column {
                    id: initFieldsList
                    spacing: 6

                    Repeater {
                        id: initFieldsRepeater

                        delegate: Text {
                            leftPadding: 12
                            text: modelData.title
                            color: initFieldArea.containsMouse ? "red" : "blue"

                            MouseArea {
                                id: initFieldArea
                                anchors.fill: parent
                                hoverEnabled: true
                            }
                        }
                    }
                }

                Row {
                    id: calcGroupRow
                    spacing: 6

                    Text {
                        text: calcFieldsList.visible ? "-" : "+"
                        color: "green"

                        MouseArea {
                            anchors.fill: parent

                            onClicked: calcFieldsList.visible = !calcFieldsList.visible
                        }
                    }

                    Text {
                        text: "Рассчитанные данные"
                        color: calcGroupArea.containsMouse ? "orange" : "green"
                        font.bold: true

                        MouseArea {
                            id: calcGroupArea
                            anchors.fill: parent
                            hoverEnabled: true

                            onClicked: calcFieldsList.visible = !calcFieldsList.visible
                        }
                    }
                }

                Column {
                    id: calcFieldsList
                    spacing: 6

                    Repeater {
                        id: calcFieldsRepeater

                        delegate: Text {
                            leftPadding: 12
                            text: modelData.title
                            color: calcFieldArea.containsMouse ? "red" : "green"

                            MouseArea {
                                id: calcFieldArea
                                anchors.fill: parent
                                hoverEnabled: true
                            }
                        }
                    }
                }

                Row {
                    id: showContourRow
                    spacing: 6

                    C2.CheckBox {
                        id: cbShowContour
                        width: settingsContent.width - 40
                        checked: true
                        text: "Контур"
                    }

                    C2.Button {
                        id: btnContourSettings
                        width: 30
                        text: "..."
                        onClicked: contourDialog.open()
                    }

                    C2.Popup {
                        id: contourDialog
                        width: 150
                        height: 180
                        x: cbShowContour.x
                        y: btnContourSettings.y + 30
                        enabled: cbShowContour.checked

                        Column {
                            spacing: 6

                            Text {
                                id: contourLabel
                                font.pixelSize: 12
                                text: "Контур"
                            }

                            C2.CheckBox {
                                id: cbTransparent
                                text: "Прозрачный"
                            }

                            C2.CheckBox {
                                id: cbLighting
                                checked: true
                                text: "Освещение"
                            }

                            Text {
                                id: contourBrushLabel
                                font.pixelSize: 12
                                text: "Тип окраски"
                            }

                            Column {
                                spacing: 6

                                C2.RadioButton {
                                    id: rbContourBlock
                                    text: "Блочная"
                                    checked: true
                                }

                                C2.RadioButton {
                                    id: rbContourInterpolation
                                    text: "Интерполяция"
                                }
                            }
                        }
                    }
                }

                Row {
                    id: showMeshRow
                    spacing: 6

                    C2.CheckBox {
                        id: cbShowMesh
                        checked: true
                        text: "Сетка"
                    }
                }

                C2.Button {
                    id: btnBlockSettings
                    width: settingsContent.width
                    text: "Видимость блоков"
                }

                Rectangle { height: 6; width: 6; }

                Text {
                    id: wellSettingsLabel
                    font.pixelSize: 12
                    text: "Скважины"
                }

                Row {
                    id: showWellsRow
                    spacing: 6

                    Text {
                        height: 20
                        verticalAlignment: Text.AlignVCenter
                        text: wellSettings.visible ? "-" : "+"

                        MouseArea {
                            anchors.fill: parent

                            onClicked: wellSettings.visible = !wellSettings.visible
                        }
                    }

                    C2.CheckBox {
                        id: cbShowWells
                        checkState: Qt.PartiallyChecked
                        text: "Показать скважины"
                        onCheckStateChanged: {
                            if(checkState != Qt.PartiallyChecked)
                            {
                                cbShowWellName.checked = checkState == Qt.Checked;
                                cbShowWellControl.checked = checkState == Qt.Checked;
                                cbShowWellPerforation.checked = checkState == Qt.Checked;
                            }
                        }
                    }
                }

                Column {
                    id: wellSettings
                    spacing: 6
                    leftPadding: 12

                    C2.CheckBox {
                        id: cbShowWellName
                        checked: true
                        text: "Показать имена скважин"
                        onClicked: cbShowWells.checkState = checkWellSettings()
                    }

                    C2.CheckBox {
                        id: cbShowWellControl
                        checked: false
                        text: "Показать тип контроля скважин"
                        onClicked: cbShowWells.checkState = checkWellSettings()
                    }

                    C2.CheckBox {
                        id: cbShowWellPerforation
                        checked: false
                        text: "Показать зоны перфорации скважин"
                        onClicked: cbShowWells.checkState = checkWellSettings()
                    }
                }


                Rectangle { height: 6; width: 6; }

                Text {
                    id: otherSettingsLabel
                    font.pixelSize: 12
                    text: "Другое"
                }

                Row {
                    id: showLegendRow
                    spacing: 6

                    C2.CheckBox {
                        id: cbShowLegend
                        width: settingsContent.width - 40
                        checked: true
                        text: "Легенда"
                    }

                    C2.Button {
                        id: btnLegendSettings
                        width: 30
                        text: "..."
                    }
                }

                Row {
                    id: rotationAxisRow
                    spacing: 12

                    Text {
                        id: rotationAxisLabel
                        verticalAlignment: Qt.AlignVCenter
                        leftPadding: 6
                        height: 20
                        text: "Вращение"
                    }

                    C2.ComboBox {
                        id: cbRotationAxis
                        width: 50
                        model: [{value: FieldSceneDrawer.XY, text: "XY"}, {value: FieldSceneDrawer.X, text: "X"},
                                {value: FieldSceneDrawer.Y, text: "Y"}, {value: FieldSceneDrawer.Z, text: "Z"}]
                        textRole: "text"
                    }
                }

                Rectangle { height: 6; width: 6; }

                Row {
                    id: viewAxisRow
                    spacing: 12

                    C2.Button {
                        id: btnXYViewAxis
                        text: "XY"
                        width: 30
                        onClicked: drawer.setXYViewAxis()
                    }

                    C2.Button {
                        id: btnXZViewAxis
                        text: "XZ"
                        width: 30
                        onClicked: drawer.setXZViewAxis()
                    }

                    C2.Button {
                        id: btnYZViewAxis
                        text: "YZ"
                        width: 30
                        onClicked: drawer.setYZViewAxis()
                    }
                }
            }
        }
    }

    onResizingChanged: {
        if(!resizing) {
            ratio = Math.min(field.width/fieldSplit.width, field.height/fieldSplit.height);
            resizeItems();
        }
    }

    onWidthChanged: resizeItems()

    function resizeItems() {
        field.width = settingsVisible ? ratio >= 0 && ratio <= 1 ? ratio*fieldSplit.width : fieldSplit.width/2 : fieldSplit.width;
        settings.width = settingsVisible ? ratio >= 0 && ratio <= 1 ? (1-ratio)*fieldSplit.width : fieldSplit.width/2 : fieldSplit.width;
    }

    function checkWellSettings()
    {
        if(cbShowWellName.checked && cbShowWellControl.checked && cbShowWellPerforation.checked) return Qt.Checked;

        if(!cbShowWellName.checked && !cbShowWellControl.checked && !cbShowWellPerforation.checked) return Qt.Unchecked;

        return Qt.PartiallyChecked;
    }

    function closeProject()
    {
        initFieldsRepeater.model = [];
        calcFieldsRepeater.model = [];
    }

    function prepare(projectData)
    {
        var fields = drawer.getFields();

        initFieldsRepeater.model = fields;

        var calcFields = drawer.getCalcFields();

        var data = [];

        calcFields.forEach(function(ind) {
            data.push(fields[ind]);
        });

        calcFieldsRepeater.model = data;
    }
}
