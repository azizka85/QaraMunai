import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.3

Item {
    property alias settingsView: settingsView

    ChartView {

        id: swofChart
        anchors.fill: parent
        legend.alignment: Qt.AlignTop

          margins.top: 0
          margins.bottom: 0
          margins.left: 0
          margins.right: 0

        LineSeries {
            property alias markerSize: krwSWOF2.markerSize
            property alias markerColor: krwSWOF2.color
            property alias markerShape: krwSWOF2.markerShape
            id: krwSWOF
            name: qsTr("Krw")
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            property alias markerSize: kroSWOF2.markerSize
            property alias markerColor: kroSWOF2.color
            property alias markerShape: kroSWOF2.markerShape
            id: kroSWOF
            name: qsTr("Krow")
            color: "mediumpurple"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            property alias markerSize: pcSWOF2.markerSize
            property alias markerColor: pcSWOF2.color
            property alias markerShape: pcSWOF2.markerShape
            id: pcSWOF
            name: qsTr("Pcow")
            color: "orange"
            axisX: axisX
            axisYRight: axisY2
            width: 2
            style: "SolidLine"
        }
        ScatterSeries{
            id:krwSWOF2
            markerSize: 8
            visible: krwSWOF.visible
            color: "mediumseagreen"
            markerShape: ScatterSeries.MarkerShapeRectangle
        }
        ScatterSeries{
            id:kroSWOF2
            markerSize: 8
            visible: kroSWOF.visible
            color: "mediumpurple"
            markerShape: ScatterSeries.MarkerShapeCircle
        }

        ScatterSeries{
            id:pcSWOF2
            markerSize: 8
            visible: pcSWOF.visible
            color: "red"
        }

        ValueAxis{
            id: axisX
            titleText:qsTr("Насыщенность воды, д.ед.")
            color: "Black"

            min: 0
            max: 1
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
            titleText:qsTr("Отн. фазовые проницаемости, д.ед.")
            color: "Black"

            min: 0
            max: 1
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
            titleText: qsTr("Капиллярное давление, Psia")
            color: "Black"

            tickCount: 6
            labelFormat: "%.1f"

            gridVisible: false
        }
    }

    function closeProject()
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        krwSWOF2.clear();
        kroSWOF2.clear();
        pcSWOF2.clear();
    }

    function prepare(list)
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        krwSWOF2.clear();
        kroSWOF2.clear();
        pcSWOF2.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
            kroSWOF2.append(list[i].sw, list[i].kro);
            krwSWOF2.append(list[i].sw, list[i].krw);
            pcSWOF2.append(list[i].sw, list[i].pc);
        }
    }

    Menu {
        id: settingsMenu
        MenuItem {
            text: "Настройка графиков"
            onClicked: {
                settingsView.show()
            }
        }

        // Дұрыстау керек
        MenuItem {
            id: captureMenuItem
            text: "Сделать снимок"
            property variant asad : ["gh"]
            onClicked: {
                swofChart.grabToImage(function(result){ asad.push(result);console.log(asad[1]); captureFileDialog.open(); });
            }
        }
    }
    FileDialog {
        id: captureFileDialog
        title: "Выберите расположение изображения"
        folder: shortcuts.pictures
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        selectExisting: false
        defaultSuffix: 'png'
        onAccepted: {
            close();
            captureMenuItem.asad[1].saveToFile(captureFileDialog.fileUrl);
        }
    }


    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton|Qt.RightButton
        onClicked: {
            if(mouse.button & Qt.RightButton)
                settingsMenu.popup()
        }
    }

    SettingsView {
        id: settingsView
        visible: false
        model: [krwSWOF, kroSWOF, pcSWOF]
    }
}
