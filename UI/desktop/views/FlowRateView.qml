import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3

Item {
    ChartView {
        id: flowRateChart
        anchors.fill: parent
        margins { left: 0; right: 0; bottom: 0; top: 0 }
        legend.alignment: Qt.AlignTop

        LineSeries {
            id: oilRateSeries
            name: qsTr("Дебит нефти")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: waterRateSeries
            name: qsTr("Дебит воды")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: gasRateSeries
            name: qsTr("Дебит газа")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: waterInjRateSeries
            name: qsTr("Расход воды")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: gasInjRateSeries
            name: qsTr("Расход газа")

            axisX: axisX
            axisYRight: axisY2
        }

        ValueAxis{
            id: axisX
            titleText:qsTr("Время")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            minorTickCount: 4
            minorGridVisible: true
            minorGridLineColor: "gainsboro"

            gridVisible: true
            gridLineColor: "silver"
        }
        ValueAxis{
            id: axisY
            titleText:qsTr("Дебиты воды и нефти, stb / day")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            minorTickCount: 4
            minorGridVisible: true
            minorGridLineColor: "gainsboro"

            gridVisible: true
            gridLineColor: "silver"
        }
        ValueAxis{
            id: axisY2
            titleText:qsTr("Дебиты газа, Mscf / day")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            minorTickCount: 4
            minorGridVisible: true
            minorGridLineColor: "gainsboro"

            gridVisible: true
            gridLineColor: "silver"
        }
    }

    Menu {
        id: settingsMenu

        MenuItem {
            text: "Настройка графиков"
            onTriggered: settingsView.show();
        }
        MenuItem {
            text: "Сделать снимок"
            onTriggered: captureFileDialog.open();
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled: true
        propagateComposedEvents: true
        preventStealing: false
        onClicked: {
            if(mouse.button & Qt.RightButton) settingsMenu.popup()
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [krwSWOF, kroSWOF, pcSWOF]
    }

    FileDialog {
        id: captureFileDialog
        title: "Сохранить как"
        folder: shortcuts.pictures
        nameFilters: [ "PNG файл (*.png)", "Все файлы (*)" ]
        selectExisting: false
        defaultSuffix: 'png'
        onAccepted: {
            var path = fileUrl.toString();
            // remove prefixed "file:///"
            path = path.replace(/^(file:\/{3})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            flowRateChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i < flowRateChart.count; i++)
            flowRateChart.series(i).clear();
    }
    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.length; i++)
        {
            oilRateSeries.append(list[i].sw, list[i].krw);
            waterRateSeries.append(list[i].sw, list[i].kro);
            gasRateSeries.append(list[i].sw, list[i].pc);
            waterInjRateSeries.append(list[i].sw, list[i].pc);
            gasInjRateSeries.append(list[i].sw, list[i].pc);

        }
    }
}
