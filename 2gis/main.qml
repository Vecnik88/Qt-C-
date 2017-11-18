import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

import io.qt.file 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("2gis")

    Rectangle {
        anchors.fill: parent
        color: "white"
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.column: 1
        Layout.row: 1

        Button {
            text: qsTr("Open FileSystem")
            anchors.centerIn: parent
            width: 300
            height: 50
            onClicked: {
                fileDialog.visible = true
                mainWindow.hide()
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            firstWindow.show()
            fileio.setSource(fileDialog.fileUrl)
            fileio.read()
        }
        onRejected: {
            mainWindow.show()
        }
        Component.onCompleted: visible = false
    }

    FileIO {
        id: fileio
    }

    AnotherWindow {
        id: firstWindow
        title: qsTr("Window interrupt")

        Text {
            id: textOutput
            wrapMode: Text.WordWrap
            anchors.verticalCenter: parent
            text: 'Processed rows: ' + fileio.str.toString() + '\n' +
                  'Amount unique words: ' + fileio.words.toString()
            font.pixelSize: 15
        }
        onSignalExit: {
            firstWindow.close()
            fileio.clear()
            mainWindow.show()
        }
    }
}

