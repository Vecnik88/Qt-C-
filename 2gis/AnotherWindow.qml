import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.0

Window {
    id: anotherWindow
    signal signalExit
    width:480
    height:320

    Button {
        text: qsTr("Back")
        width: 180
        height: 50
        anchors.centerIn: parent
        onClicked: {
            anotherWindow.signalExit()
        }
    }
}

