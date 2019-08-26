import QtQuick 2.0
import QtCharts 2.3

Item {
    property alias markerSize: scatter.markerSize
    property alias markerShape: scatter.markerShape
    property alias style: line.style
    property var color: 'red'

    LineSeries {
        id: line
        color: color
    }

    ScatterSeries {
        id: scatter
        color: color
    }
}
