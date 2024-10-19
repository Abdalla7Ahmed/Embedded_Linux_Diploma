import QtQuick

Window {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        // (1) identifier
        id: thisLabel

        // (2) set x- and y-position
        x: 24; y: 16

        // (3) bind height to 2 * width
        height: 1 * width

        // (4) custom property
        property int times: 24

        // (5) property alias
        property alias anotherTimes: thisLabel.times
        //property int anotherTimes: thisLabel.times
        /*
          the difference between alias and int
          if we change the alias property , the timer will change
          if we change the int property , no change happen on timer
          */
        // (6) set text appended by value
        text: "Greetings " + times

        // (7) font is a grouped property
        font.family: "Ubuntu"
        font.pixelSize: 24

        // (8) KeyNavigation is an attached property
        KeyNavigation.tab: otherLabel

        // (9) signal handler for property changes
        onHeightChanged: console.log('height:', height)

        // focus is need to receive key events
        focus: true

        // change color based on focus value
        color: focus ? "red" : "black"


    }

    Text{
        id:otherLabel
        anchors.centerIn:parent
        text: "Hello from other lable"
        font{
            family: "Ubuntu"
            pixelSize: 24
        }

        KeyNavigation.tab: thisLabel
        color: focus ? "red" : "black"
    }

}
