import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle {
        id:rec1
        width:100
        height:100
        color:"red"
        x:0
        y:width
    }
    Rectangle
    {
        id:rec2
        width:rec1.width
        height:rec1.height
        color:"blue"
        x:rec1.width
        y:0
    }
    Rectangle
    {
        id:rec3
        width:rec1.width
        height:rec1.height
        color:"yellow"
        x:rec1.x+rec2.x
        y:rec1.height+rec2.height
    }
    Rectangle
    {
        id:rec4
        width:rec1.width
        height:rec1.height
        color:"black"
        x:rec1.x+rec2.x+rec3.x
        y:rec1.height
    }


}
