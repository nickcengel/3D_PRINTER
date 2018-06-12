import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 600
    height: 400
    property alias text1: text1

    title: qsTr("Page 1")

    Label {
        text: qsTr("Controls")
        anchors.verticalCenterOffset: -183
        anchors.horizontalCenterOffset: 1
        anchors.centerIn: parent
    }

    Text {
        id: text1
        x: 407
        y: 63
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
