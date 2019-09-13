import QtQuick 2.12
import QtCharts 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3

Item {
    ChartView {
        id: volumeRateChart
        anchors.fill: parent
        legend.alignment: Qt.AlignTop
        margins { left: 0; right: 0; bottom: 0; top: 0 }

        LineSeries {
            id: vOilProdSeries
            name: qsTr("Нак. объем доб. нефти")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: vWaterProdSeries
            name: qsTr("Нак. объем доб. воды")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: vWaterInjSeries
            name: qsTr("Нак. объем рас. воды")

            axisX: axisX
            axisY: axisY
        }
        LineSeries {
            id: vGasProdSeries
            name: qsTr("Нак. объем доб. газа")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: vDistGasProdSeries
            name: qsTr("Нак. объем доб. раст. газа")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: vGasInjSeries
            name: qsTr("Нак. объем рас. газа")

            axisX: axisX
            axisYRight: axisY2
        }
        LineSeries {
            id: vRastGasInjSeries
            name: qsTr("Нак. объем рас. своб. газа")

            axisX: axisX
            axisY: axisY
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
            titleText:qsTr("Накопленый объем воды и нефти, stb")
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
            titleText:qsTr("Накопленный объем газа, Mscf")
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

    SettingsView {
        id: settingsView
        visible: false
        model: volumeRateChart
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
            volumeRateChart.grabToImage(function(result){result.saveToFile(cleanPath)});
        }
    }

    function closeProject()
    {
        for(let i = 0; i < volumeRateChart.count; i++)
            volumeRateChart.series(i).clear();
    }
    function prepare(list)
    {
        closeProject();
        for(var i = 0; i < list.length; i++)
        {
            vOilProdSeries.append(list[i].sw, list[i].krw);
            vWaterProdSeries.append(list[i].sw, list[i].kro);
            vWaterInjSeries.append(list[i].sw, list[i].pc);
            vGasProdSeries.append(list[i].sw, list[i].pc);
            vDistGasProdSeries.append(list[i].sw, list[i].pc);
            vGasInjSeries.append(list[i].sw, list[i].pc);
            vRastGasInjSeries.append(list[i].sw, list[i].pc);

        }
    }
}
