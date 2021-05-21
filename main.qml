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


    // массив QML, в который можно поместить что угодно, в C++ это будет либо QVariantMap, либо QVariantList
//    property var objectsArray: []

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
        id: addOBjectStructure
        text: qsTr("Add Participant")
        anchors {
            right: parent.horizontalCenter
            left: parent.left
            bottom: addOBjectButton.top
            margins: 5
        }
        onClicked: {
//            objectsArray.push(factory.addParticipant("Mike"))
        }
    }

    Button {
        id: addOBjectButton
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
        text: qsTr("Print participants")
        anchors {
            right: parent.right
            left: parent.horizontalCenter
            bottom: parent.bottom
            margins: 5
        }
        onClicked: {
            var count_participants = file.countParticipants()
            textView.text = ""
            for (var i = 0; i < count_participants; ++i)
            {
                var str_2 = i + 1 + " " + file.getParticipantByIndex(i) + "\n"
                textView.text += str_2
            }
        }
    }
}
