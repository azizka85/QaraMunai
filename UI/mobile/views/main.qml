import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import QaraMunai.Model.Domain.Project 1.0
import QaraMunai.Model.DAO 1.0

ApplicationWindow {
    property Menu rightMenu: null
    property Item content: homeView

    id: mainWindow
    visible: true
    width: 300
    height: 500
    title: qsTr("Qara munai'")

    header: ToolBar {
        ToolButton {
            id: menuButton
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            icon.source: "qrc:/mobile/images/main-menu-open-24x24.png"
            onClicked: mainMenu.open()
        }

        Label {
            id: mainTitle
            anchors {
                left: menuButton.right
                right: rightMenuButton.left
            }
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            text: projectData.title === "" ? qsTr("Qara munai'") : projectData.title
            font.pixelSize: 20
            elide: Label.ElideRight
        }

        ToolButton {
            id: rightMenuButton
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            icon.source: "qrc:/mobile/images/right-menu-open-24x24.png"
            visible: rightMenu !== null
            onClicked: rightMenu.open()
        }
    }

    Drawer {
        id: mainMenu
        width: Math.min(mainWindow.width, mainWindow.height) / 3 * 2
        height: mainWindow.height

        ListView {
            id: menuList
            anchors.fill: parent
            focus: true
            currentIndex: -1
            model: homeMenuList

            delegate: ItemDelegate {
                width: parent.width
                text: model.isStarted !== undefined && model.isStarted ? model.secondText : model.text
                highlighted: ListView.isCurrentItem
                height: model.displayed() ? 48 : 0
                icon.source: model.isStarted !== undefined && model.isStarted ? model.secondIcon : model.icon
                onClicked: {
                    menuList.currentIndex = model.index
                    if(model.isStarted !== undefined) model.isStarted = !model.isStarted
                    model.triggered()
                }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    ProjectData {
        id: projectData
    }

    EclipseFileReader {
        id: eclipseReader
    }

    AsyncFileReader {
        id: projectReader
        onLoadComplete: {
            var regions = createNumberArray(projectData.tabDIMS.ntSFUN);
            swofView.loadProject(regions);
            sgofView.loadProject(regions);
            pvtoView.loadProject(regions);
            pvtgView.loadProject(regions);
            loaderDialog.close();
        }
    }

    FileDialog {
        id: importDATAOFD
        title: qsTr("Открыть Eclipse файл")
        folder: Qt.resolvedUrl("./")
        nameFilters: "DATA files(*.DATA)|*.DATA"

        onAccepted: {
            closeProject();
            loaderDialog.open();
            projectReader.load(eclipseReader, projectData, importDATAOFD.fileUrl.toString().replace("file:///", ""))
        }
    }

    Popup {
        id: loaderDialog
        width: 150
        height: 150
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Text {
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
            text: qsTr("Идет загрузка данных")
        }

        AnimatedImage {
            anchors.centerIn: parent
            source: "qrc:/mobile/images/icon-waiting.gif"
        }

        Text {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 16
            text: qsTr("Подождите...")
        }
    }

    ListModel {
        id: homeMenuList

        ListElement {
            text: qsTr("Файл")
            icon: "qrc:/mobile/images/open-child-list.svg"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = fileMenuList;
            }
        }

        ListElement {
            text: qsTr("Карта")
            icon: "qrc:/mobile/images/open-child-list.svg"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                menuList.model = fieldMenuList;
            }
        }

        ListElement {
            text: qsTr("Функции насыщенности")
            icon: "qrc:/mobile/images/open-child-list.svg"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                menuList.model = sfMenuList;
            }
        }

        ListElement {
            text: qsTr("Свойства пластовой жидкости")
            icon: "qrc:/mobile/images/open-child-list.svg"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                menuList.model = pvtMenuList;
            }
        }

        ListElement {
            text: qsTr("Расчетные данные")
            icon: "qrc:/mobile/images/open-child-list.svg"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                menuList.model = calcMenuList;
            }
        }

        ListElement {
            text: qsTr("Консоль")
            icon: "qrc:/mobile/images/console-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }
    }

    ListModel {
        id: fileMenuList

        ListElement {
            text: qsTr("Файл")
            icon: "qrc:/mobile/images/move-back-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = homeMenuList;
            }
        }

        ListElement {
            text: qsTr("Открыть Eclipse данные")
            icon: "qrc:/mobile/images/eclipse-icon-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                importDATAOFD.open();
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("Закрыть проект")
            icon: "qrc:/mobile/images/eclipse-icon-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                closeProject();
            }
        }
    }

    ListModel {
        id: fieldMenuList

        ListElement {
            text: qsTr("Карта")
            icon: "qrc:/mobile/images/move-back-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = homeMenuList;
            }
        }

        ListElement {
            text: qsTr("Поле")
            icon: "qrc:/mobile/images/icon-field-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }
    }

    ListModel {
        id: sfMenuList

        ListElement {
            text: qsTr("Функции насыщенности")
            icon: "qrc:/mobile/images/move-back-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = homeMenuList;
            }
        }

        ListElement {
            text: qsTr("ОФП и КД (нефть-вода)")
            icon: "qrc:/mobile/images/icon-linechart-16x16.png"
            displayed: function() {
                return projectData.swof.exist();
            }
            triggered: function() {
                swofView.prepare(projectData);
                rightMenu = swofView.swofRightMenu;
                content.visible = false;
                content = swofView;
                content.visible = true;
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("ОФП и КД (газ-нефть)")
            icon: "qrc:/mobile/images/icon-linechart-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                sgofView.prepare(projectData);
                rightMenu = sgofView.sgofRightMenu;
                content.visible = false;
                content = sgofView;
                content.visible = true;
                mainMenu.close();
            }
        }
    }

    ListModel {
        id: pvtMenuList

        ListElement {
            text: qsTr("Свойства пластовой жидкости")
            icon: "qrc:/mobile/images/move-back-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = homeMenuList;
            }
        }

        ListElement {
            text: qsTr("PVT нефти")
            icon: "qrc:/mobile/images/icon-linechart-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                pvtoView.prepare(projectData);
                rightMenu = pvtoView.pvtoRightMenu;
                content.visible = false;
                content = pvtoView;
                content.visible = true;
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("PVT газа")
            icon: "qrc:/mobile/images/icon-linechart-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                pvtgView.prepare(projectData);
                rightMenu = pvtgView.pvtgRightMenu;
                content.visible = false;
                content = pvtgView;
                content.visible = true;
                mainMenu.close();
            }
        }
    }

    ListModel {
        id: calcMenuList

        ListElement {
            text: qsTr("Расчетные данные")
            icon: "qrc:/mobile/images/move-back-16x16.png"
            displayed: function() {
                return true;
            }
            triggered: function() {
                menuList.model = homeMenuList;
            }
        }

        ListElement {
            isStarted: false
            text: "Запустить расчет"
            secondText: "Приостановить расчет"
            icon: "qrc:/mobile/images/run-calculation-16x16.png"
            secondIcon: "qrc:/mobile/images/pause-calculation-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }

        ListElement {
            text: "Остановить расчет"
            icon: "qrc:/mobile/images/stop-calculation-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("Обводненность и КИН")
            icon: "qrc:/mobile/images/calc-results-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("Дебиты воды и нефти")
            icon: "qrc:/mobile/images/calc-results-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }

        ListElement {
            text: qsTr("Объем закачки и добычи")
            icon: "qrc:/mobile/images/calc-results-16x16.png"
            displayed: function() {
                return projectData.loaded;
            }
            triggered: function() {
                mainMenu.close();
            }
        }
    }

    Item {
        id: homeView
        anchors.fill: parent
        visible: true

        Image {
            anchors.centerIn: parent
            source: "qrc:/mobile/images/main-image-32x32.png"
        }
    }

    SWOFView {
        id: swofView
        visible: false
        anchors.fill: parent
    }

    SGOFView {
        id: sgofView
        visible: false
        anchors.fill: parent
    }

    PVTOView {
        id: pvtoView
        visible: false
        anchors.fill: parent
    }

    PVTGView {
        id: pvtgView
        visible: false
        anchors.fill: parent
    }
    function createNumberArray(length)
    {
        var items = [];
        for(var i = 0; i < length; i++) items[i] = i+1;
        return items;
    }

    function closeProject()
    {
        swofView.closeProject();
        sgofView.closeProject();
        pvtoView.closeProject();
        pvtoView.closeProject();

        projectData.initVariables();

        rightMenu = null;

        content.visible = false;
        content = homeView;
        content.visible = true;

        mainMenu.close();
    }
}
