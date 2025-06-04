import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3

Item {
    ChartView {
        id: watcutChart
        anchors.fill: parent
        margins { left: 0; right: 0; bottom: 0; top: 0 }
        legend.alignment: Qt.AlignTop

        LineSeries {
            id: kinSeries
            name: qsTr("KIN")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: waterCutSeries
            name: qsTr("Обводненость")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: gofSeries
            name: qsTr("ГНФ")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: wgfSeries
            name: qsTr("ВГФ")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: wofSeries
            name: qsTr("ВНФ")

            axisX: axisX
            axisYRight: axisY2
        }

        ValueAxis {
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
        ValueAxis {
            id: axisY
            titleText:qsTr("КИН, Обводненность, %")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            minorTickCount: 4
            minorGridVisible: true
            minorGridLineColor: "gainsboro"

            gridVisible: true
            gridLineColor: "silver"
        }
        ValueAxis {
            id: axisY2
            titleText:qsTr("ГНФ, ВГФ, ВНФ")
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
            watcutChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i < watcutChart.count; i++)
            watcutChart.series(i).clear();
    }
    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.count; i++)
        {
            wofSeries.append(list.get(i).index, list.get(i).log);
            wgfSeries.append(list.get(i).index, list.get(i).xx);
            gofSeries.append(list.get(i).index, list.get(i).exp);
            kinSeries.append(list.get(i).index, list.get(i).sin);
            waterCutSeries.append(list.get(i).ndex, list.get(i).cos);
        }
    }
}
