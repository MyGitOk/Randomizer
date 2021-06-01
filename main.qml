import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Randomizer")
    //Component.onCompleted: console.log("Completed Running!")

    Text {
        id: textView
        clip: true
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: parent
            margins: 5
        }
    }

    Rectangle {
        id: winner
        width: root.width / 3
        height: root.height / 10
        color: "transparent"
        border {
            color: "black"
            width: 1
        }
        radius: 10
        anchors {
            right: parent.right
            left: parent.horizontalCenter
            margins: 10
        }

        Text {
            id: winnerName
            x: winner.width / 2 - width / 2
            y: winner.height / 2 - height / 2
            text: ""
            font {
                pointSize: Math.min(winner.width, winner.height) / 4
                bold: true
            }
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }
        }

    }

    Button {
        id: testButton
        text: qsTr("test")
        anchors {
            right: parent.horizontalCenter
            left: parent.left
            bottom: randomButton.top
            margins: 5
        }
        onClicked: {

        }
    }

    Button {
        id: testButton2
        text: qsTr("test2")
        anchors {
            right: parent.right
            left: parent.horizontalCenter
            bottom: printButton.top
            margins: 5
        }
        onClicked: {

        }
    }

    Button {
        id: randomButton
        text: qsTr("Get random")
        anchors {
            right: parent.horizontalCenter
            left: parent.left
            bottom: parent.bottom
            margins: 5
        }

        onClicked: {
            winnerName.text = file.getRandomParticipant()
        }
    }

    Button {
        id: printButton
        text: qsTr("Print participants")
        anchors {
            right: parent.right
            left: parent.horizontalCenter
            bottom: parent.bottom
            margins: 5
        }
        onClicked: {
            var countParticipant = file.countParticipant()
            textView.text = ""
            for (var i = 0; i < countParticipant; ++i){
                var str = i + 1 + " " + file.getParticipantByIndex(i) + "\n"
                textView.text += str
            }
        }
    }
}
