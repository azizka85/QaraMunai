import QtQuick 2.12
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.4 as C2

import QaraMunai.Drawers 1.0
import QaraMunai.Model.Domain.Project 1.0

C1.SplitView {
    property real ratio: 0.8
    property bool settingsVisible: false

    property alias projectData: drawer.pdata
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
            selectBlock: cbSelectBlock.checked
            axisOfRotation: cbRotationAxis.model[cbRotationAxis.currentIndex].value
            actionByMouse: cbActionByMouse.model[cbActionByMouse.currentIndex].value
            multX: parseFloat(multXField.text)
            multY: parseFloat(multYField.text)
            multZ: parseFloat(multZField.text)

            MouseArea {
                property vector2d localPosition                

                id: drawerArea
                acceptedButtons: Qt.LeftButton | Qt.MidButton
                anchors.fill: parent

                onPressed: {
                    if(mouse.buttons === Qt.LeftButton || mouse.buttons === Qt.MidButton || mouse.buttons === (Qt.LeftButton | Qt.MidButton)) {
                        drawer.mousePosition = Qt.vector2d(mouse.x, mouse.y);
                        localPosition = drawer.mousePosition;
                    }

                    mouse.accepted = true;
                }

                onPositionChanged: {
                    if(mouse.buttons !== Qt.LeftButton && mouse.buttons !== Qt.MidButton && mouse.buttons !== (Qt.LeftButton | Qt.MidButton)) return;

                    var position = Qt.vector2d(mouse.x, mouse.y);

                    var displacement = Qt.vector2d(position.x - localPosition.x, localPosition.y - position.y);

                    if(drawer.actionByMouse === FieldSceneDrawer.ActionRotate)
                    {
                        if(mouse.buttons === Qt.LeftButton)
                            drawer.rotateView(displacement, drawer.axisOfRotation);
                        else if(mouse.buttons === Qt.MidButton)
                            drawer.rotateView(displacement, FieldSceneDrawer.Z);
                        else if(mouse.buttons === (Qt.LeftButton | Qt.MidButton))
                            drawer.translateView(displacement);
                    }
                    else
                    {
                        if(mouse.buttons === Qt.LeftButton)
                            drawer.translateView(displacement);
                        else if(mouse.buttons === Qt.MidButton)
                            drawer.rotateView(displacement, drawer.axisOfRotation);
                        else if(mouse.buttons === (Qt.LeftButton | Qt.MidButton))
                            drawer.rotateView(displacement, FieldSceneDrawer.Z);
                    }

                    localPosition = position;

                    mouse.accepted = true;
                }

                onWheel: {
                    if(wheel.angleDelta.y > 0)
                        drawer.zLocation += 0.025;
                    else if(wheel.angleDelta.y < 0)
                        drawer.zLocation -= 0.025;

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

        RowLayout {
            id: legendRow
            width: parent.width
            height: 40
            visible: cbShowLegend.checked
            anchors { bottom: parent.bottom }

            Text {
                id: legendLabel
                Layout.minimumWidth: 150
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                horizontalAlignment: Qt.AlignHCenter
                color: "white"
                font.pixelSize: 12
                text: "Прон. по X, mD: "
            }

            Item {
                id: legendGradient
                visible: true
                Layout.preferredWidth: parent.width - legendLabel.width - 50
                Layout.minimumWidth: 450
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                Column {
                    anchors.fill: parent
                    spacing: 6

                    LinearGradient {
                        width: parent.width - 75
                        height: 16
                        x: 25
                        start: Qt.point(0, 0)
                        end: Qt.point(width, 0)
                        gradient: Gradient {
                            GradientStop { position: 0; color: "#0000ff" }
                            GradientStop { position: 0.25; color: "#00ffff" }
                            GradientStop { position: 0.5; color: "#00ff00" }
                            GradientStop { position: 0.75; color: "#ffff00" }
                            GradientStop { position: 1; color: "#ff0000" }
                        }
                    }

                    Row {
                        width: parent.width
                        height: 22

                        Text {
                            id: legendLabel0
                            width: parent.width/4 - 25
                            font.pixelSize: 12
                            color: "white"
                            text: "0.12345"
                        }

                        Text {
                            id: legendLabel1
                            width: parent.width/4 - 25
                            font.pixelSize: 12
                            color: "white"
                            text: "0.23456"
                        }

                        Text {
                            id: legendLabel2
                            width: parent.width/4 - 25
                            font.pixelSize: 12
                            color: "white"
                            text: "0.34567"
                        }

                        Text {
                            id: legendLabel3
                            width: parent.width/4 - 25
                            font.pixelSize: 12
                            color: "white"
                            text: "0.45678"
                        }

                        Text {
                            id: legendLabel4
                            font.pixelSize: 12
                            color: "white"
                            text: "0.45567dfdfdf"
                            width: 100
                            horizontalAlignment: Qt.AlignHCenter
                        }
                    }
                }
            }

            Item {
                id: legendSingle
                visible: false
                Layout.preferredWidth: parent.width - legendLabel.width - 50
                Layout.minimumWidth: 450
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                Column {
                    anchors.fill: parent
                    spacing: 6

                    Rectangle {
                        width: parent.width - 75
                        height: 16
                        x: 25
                        color: "#0000ff"
                    }

                    Text {
                        id: legendLabel5
                        width: parent.width
                        font.pixelSize: 12
                        color: "white"
                        horizontalAlignment: Qt.AlignHCenter
                        text: "0.12345"
                    }
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

                                onClicked: setField(modelData)
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

                                onClicked: setField(modelData)
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
                        margins: 1
                        enabled: cbShowContour.checked
                        closePolicy: C2.Popup.CloseOnEscape | C2.Popup.CloseOnPressOutside

                        MouseArea {
                            anchors.fill: parent

                            property vector2d localPosition

                            onPressed: localPosition = Qt.vector2d(mouse.x, mouse.y)

                            onPositionChanged: {
                                var position = Qt.vector2d(mouse.x, mouse.y);

                                var displacement = position.minus(localPosition);

                                contourDialog.x += displacement.x;
                                contourDialog.y += displacement.y;
                            }
                        }

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
                    id: multXRow
                    spacing: 12

                    Text {
                        id: multXLabel
                        verticalAlignment: Qt.AlignVCenter
                        leftPadding: 6
                        height: 20
                        text: "Умножение X"
                    }

                    C2.TextField {
                        id: multXField
                        width: 50
                        text: "1"
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        selectByMouse: true
                    }
                }

                Row {
                    id: multYRow
                    spacing: 12

                    Text {
                        id: multYLabel
                        verticalAlignment: Qt.AlignVCenter
                        leftPadding: 6
                        height: 20
                        text: "Умножение Y"
                    }

                    C2.TextField {
                        id: multYField
                        width: 50
                        text: "1"
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        selectByMouse: true
                    }
                }

                Row {
                    id: multZRow
                    spacing: 12

                    Text {
                        id: multZLabel
                        verticalAlignment: Qt.AlignVCenter
                        leftPadding: 6
                        height: 20
                        text: "Умножение Z"
                    }

                    C2.TextField {
                        id: multZField
                        width: 50
                        text: "-1"
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        selectByMouse: true
                    }
                }

                Rectangle { height: 6; width: 6; }

                Row {
                    id: actionByMouseRow
                    spacing: 12

                    Text {
                        id: actionByMouseLabel
                        verticalAlignment: Qt.AlignVCenter
                        leftPadding: 6
                        height: 20
                        width: 90
                        text: "Действие с помощью мыши"
                        wrapMode: Text.WordWrap
                    }

                    C2.ComboBox {
                        id: cbActionByMouse
                        width: 90
                        model: [{value: FieldSceneDrawer.ActionRotate, text: "Вращение"},
                                {value: FieldSceneDrawer.ActionMove, text: "Перемещение"}];
                        textRole: "text"
                    }
                }

                Rectangle { height: 6; width: 6; }

                C2.CheckBox {
                    id: cbSelectBlock
                    width: settingsContent.width - 40
                    checked: true
                    text: "Выбирать блоки"
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
        legendGradient.visible = true;
        legendSingle.visible = false;

        initFieldsRepeater.model = [];
        calcFieldsRepeater.model = [];

        drawer.selectedBlockIndex = -1;

        drawer.updateData(ProjectData.CLOSED);
    }

    function prepare(projectData)
    {
        var fields = drawer.getFields();

        initFieldsRepeater.model = fields;

        var calcFields = drawer.getCalcFields();

        calcFieldsRepeater.model = calcFields;

        var field = drawer.getField(FieldSceneDrawer.PERMX);

        setField(field);

        drawer.updateData(ProjectData.LOADED);

        drawer.setXZViewAxis();
    }

    function setField(field)
    {
        var unitText = field.unitText === "" ? "" : ", " + field.unitText;

        legendLabel.text = field.legendTitle + unitText;

        var values = drawer.setField(field.id);

        var minValue = values.minValue;
        var maxValue = values.maxValue;

        if(minValue === maxValue)
        {
            legendGradient.visible = false;
            legendSingle.visible = true;

            legendLabel5.text = minValue;
        }
        else
        {
            legendGradient.visible = true;
            legendSingle.visible = false;

            var val1 = minValue;
            var val2 = 0.75 * minValue + 0.25 * maxValue;
            var val3 = 0.5 * minValue + 0.5 * maxValue;
            var val4 = 0.25 * minValue + 0.75 * maxValue;
            var val5 = maxValue;

            legendLabel0.text = val1;
            legendLabel1.text = val2;
            legendLabel2.text = val3;
            legendLabel3.text = val4;
            legendLabel4.text = val5;
        }
    }
}
