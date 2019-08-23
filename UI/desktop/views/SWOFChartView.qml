import QtQuick 2.6
import QtCharts 2.13
import QtQuick.Controls 2.1

Item {
    property alias settingsView: settingsView

    ChartView {
        id: swofChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }


        LineSeries {
            property alias markerSize: kroSWOFS.markerSize

            id: krwSWOF
            name: qsTr("Krw")
            color: "mediumseagreen"
            width: 2
            axisX: ValueAxis{
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

            axisY: ValueAxis{
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
            style: "SolidLine"
        }

        ScatterSeries{                      
            id:krwSWOFS
            markerSize: 10
            color: krwSWOF.color
            markerShape: ScatterSeries.MarkerShapeRectangle
        }

        LineSeries{
            id: kroSWOF
            name: qsTr("Krow")
            color: "red"
            width: 2
            style: "SolidLine"
        }

        ScatterSeries{
            id:kroSWOFS
            markerSize: 10
            color: kroSWOF.color
            markerShape: ScatterSeries.MarkerShapeCircle
        }

        LineSeries {
            id: pcSWOF
            name: qsTr("Pcow")
            color: "orange"
            width: 2
            axisYRight:  ValueAxis{
                titleText: qsTr("Капиллярное давление, Psia")
                color: "Black"

                tickCount: 6
                labelFormat: "%.1f"

                gridVisible: false
            }
            style: "SolidLine"
        }
    }

    function closeProject()
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        kroSWOFS.clear();
        krwSWOFS.clear();
    }

    function prepare(list)
    {
        krwSWOF.clear();
        kroSWOF.clear();
        pcSWOF.clear();
        kroSWOFS.clear();
        krwSWOFS.clear();

        for(var i = 0; i < list.length; i++)
        {
            krwSWOF.append(list[i].sw, list[i].krw);
            kroSWOF.append(list[i].sw, list[i].kro);
            pcSWOF.append(list[i].sw, list[i].pc);
            kroSWOFS.append(list[i].sw, list[i].kro);
            krwSWOFS.append(list[i].sw, list[i].krw);
        }
    }


    Menu {
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {

                settingsView.show()
            }
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

