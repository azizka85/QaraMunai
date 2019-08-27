import QtQuick 2.6
import QtCharts 2.3
import QtQuick.Controls 2.1

Item {
    property alias settingsView: settingsView

    ChartView {
        id: sgofChart
        anchors.fill: parent

        legend {
            visible: true
            alignment: Qt.AlignBottom
        }

        LineSeries {
            property alias markerSize: krgSGOF2.markerSize
            property alias markerColor: krgSGOF2.color

            id: krgSGOF
            name: qsTr("Krg")
            color: "mediumseagreen"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            property alias markerSize: kroSGOF2.markerSize
            property alias markerColor: kroSGOF2.color

            id: kroSGOF
            name: qsTr("Krog")
            color: "mediumpurple"
            axisX: axisX
            axisY: axisY
            width: 2
            style: "SolidLine"
        }
        LineSeries {
            id: pcSGOF
            name: qsTr("Pcog")
            color: "orange"
            axisX: axisX
            axisYRight: axisY2
            width: 2
            style: "SolidLine"
        }

        ScatterSeries{
            id: krgSGOF2
            markerSize: 8
            visible: krgSGOF.visible
            color: "mediumseagreen"
            markerShape: ScatterSeries.MarkerShapeRectangle
        }
        ScatterSeries{
            id:kroSGOF2
            markerSize: 8
            visible: kroSGOF.visible
            color: "mediumpurple"
            markerShape: ScatterSeries.MarkerShapeCircle
        }

        ValueAxis{
            id: axisX
            titleText: qsTr("Насыщенность газа, д.ед.")
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
            titleText:qsTr("Отн. фазовые проницаемости, д.ед. ")
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
            titleText:qsTr("Капиллярное давление, Psia")
            color: "Black"

            min: 0
            max: 4
            tickCount: 6
            labelFormat: "%.1f"

            gridVisible: false
        }
    }

    function closeProject()
    {
        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();
        krgSGOF2.clear();
        kroSGOF2.clear();
    }

    function prepare(list)
    {
        krgSGOF.clear();
        kroSGOF.clear();
        pcSGOF.clear();
        krgSGOF2.clear();
        kroSGOF2.clear();

        for(var i = 0; i < list.length; i++)
        {
            krgSGOF.append(list[i].sg, list[i].krg);
            kroSGOF.append(list[i].sg, list[i].kro);
            pcSGOF.append(list[i].sg, list[i].pc);
            krgSGOF2.append(list[i].sg, list[i].krg);
            kroSGOF2.append(list[i].sg, list[i].kro);
        }
    }

    Menu{
        id: settingsMenu
        MenuItem{
            text: "Настройка графиков"
            onClicked: {
                settingsView.show()
            }
        }
    }

    MouseArea{
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
        model: [krgSGOF, kroSGOF, pcSGOF]
    }
}
