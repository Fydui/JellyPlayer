import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import QtQuick 2.0

Rectangle {
    id: main

    width: 1080
    height: 720
    color: "#dcdce3"

    Column {
        id: body
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        spacing: 1

        Rectangle {
            id: rectangle1
            width: parent.width
            height: 45
            color: "#d81919"
            radius: 0
        }

        Row {
            id: row2
            width: parent.width
            height: 910;
            spacing: 1

            Rectangle {
                id: rectangle3
                width: 455
                height: parent.height
                color: "#201212"
            }

            Rectangle {
                id: rectangle4
                width: parent.width//620
                height: parent.height//610
                color: "#6da662"
            }
        }

    }

    Rectangle {
        id: rectangle2
        x: 0
        y: 957
        width: parent.width
        height: 70
        color: "#ffffff"
    }

}
