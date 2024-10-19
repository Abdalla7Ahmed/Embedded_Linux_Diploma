import QtQuick

Window {
    id: root
    width: 500
    height: 500
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        // name this element root
        id: rectangle

        // properties: <name>: <value>
        width: 120; height: 240

        // color property
        color: "#4A4A4A"
        anchors.centerIn:parent
        // Declare a nested element (child of rectangle)
        Image {
            id: triangle

            // reference the parent
            x: (parent.width - width)/2; y: 40
            width:rectangle.width / 2
            height:rectangle.height / 2
            fillMode:Image.PreserveAspectFit
            source: 'assets/triangle_red.png'
        }

        // Another child of rectangle
        Text {
            // un-named element

            // reference element by id
            y: triangle.y + triangle.height + 20

            // reference rectangle element
            width: rectangle.width

            color: 'white'
            horizontalAlignment: Text.AlignHCenter
            text: 'Triangle'
        }
    }
}
