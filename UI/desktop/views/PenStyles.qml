import QtQuick 2.12
import QtQuick.Controls 2.5

ListModel {
    id: penStyleCombobox

    ListElement {
        penStyle: "NoPen"
    }

    ListElement {
        penStyle: "SolidLine"
    }

    ListElement {
        penStyle: "DashLine"
    }

    ListElement {
        penStyle: "DotLine"
    }

    ListElement {
        penStyle: "DashDotLine"
    }

    ListElement {
        penStyle: "DashDotDotLine"
    }
}
