import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0

import GolModel 1.0

Window {
    id: gameOfLife
    visible: true
    width: 640
    height: 480
    title: qsTr("Game of life")

    GolModel {
        id: golModel
    }

    MenuBar {
        id: menu
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Menu {
            title: "File"

            MenuItem {
                text: qsTr("Initialize universe")
                onClicked: golModel.initializeUniverse()
            }

            MenuItem {
                text: qsTr("Initialize galaxies")
                onClicked: golModel.initializeGalaxies()
            }

            MenuItem {
                text: qsTr("Initialize cells")
                onClicked: golModel.initializeCells();
            }

            MenuItem {
                text: qsTr("Randomize cells")
                onClicked: golModel.randomizeCells()
            }

            MenuItem {
                text: qsTr("Evolve universe using one thread")
                onClicked: golModel.evolveSingleThread()
            }

            MenuItem {
                text: qsTr("Evolve universe using all threads")
                onClicked: golModel.evolveMultipleThreads()
            }
        }
    }

    BusyIndicator {
        id: loading
        visible: golModel.isLoading
        x: 278
        y: 198
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    GridView {
        id: cells
        flickableDirection: Flickable.HorizontalAndVerticalFlick
        opacity: golModel.isLoading ? 0.3 : 1
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: elapsedTime.top
        anchors.bottomMargin: 10
        anchors.top: galaxiesCount.bottom
        anchors.topMargin: 10
        model: golModel.cells
        cellHeight: 10
        cellWidth: 10

        transitions: Transition {
            NumberAnimation { property: "opacity"; duration: 500}
        }

        delegate: Item {
            height: 10
            anchors.margins: 10

            Column {
                Rectangle {
                    width: 8
                    height: 8
                    color: model.display.color
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    Label {
        id: universeSizeLabel
        height: 24
        text: qsTr("Universe size: ")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: menu.bottom
        anchors.topMargin: 10
        anchors.right: elapsedTime.left
        anchors.rightMargin: 6
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: universeSize
        x: 6
        height: 24
        text: golModel.universeSize
        horizontalAlignment: Text.AlignHCenter
        anchors.top: menu.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: universeSizeLabel.right
        onTextChanged: golModel.setUniverseSize(universeSize.text)
    }

    Label {
        id: galaxiesCountLabel
        height: 24
        text: qsTr("Galaxies count: ")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: universeSizeLabel.bottom
        anchors.topMargin: 10
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: galaxiesCount
        height: 24
        text: golModel.galaxiesCount
        anchors.left: galaxiesCountLabel.right
        anchors.leftMargin: 8
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: universeSize.bottom
        anchors.topMargin: 10
        onTextChanged: golModel.setGalaxiesCount(galaxiesCount.text)
    }

    Label {
        id: elapsedTimeLabel
        y: 452
        height: 24
        text: qsTr("Elapsed time: ")
        anchors.right: elapsedTime.left
        anchors.rightMargin: 6
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: elapsedTime
        y: 446
        height: 24
        text: golModel.elapsedTime
        readOnly: true
        anchors.left: parent.left
        anchors.leftMargin: 93
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }
}
