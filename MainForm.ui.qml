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

    width: 1080//1080
    height: 720//720

    color: "#dcdce3"
    property alias foot: foot
    clip: true

    Image {
        id: main_bg
        width: parent.width
        height: parent.height
        source: "///img/img/Qt3.jpg"
    }

    ColumnLayout {
        id: body
        width: parent.width//1080
        height: parent.height
        opacity: 1//720
        spacing: 2//720
        clip: false

        Rectangle {
            id: head
            y: 0
            width: parent.width//1080
            height: 40
            color: "#222225"
            opacity: 0.95
            Layout.maximumHeight: 45
            Layout.fillWidth: true
            Layout.fillHeight: false
        }

        RowLayout {
            id: middle
            y: 50
            width: parent.width//1080
            height: 965
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumHeight: 0
            Layout.maximumHeight: 965
            clip: true

            Rectangle {
                id: lift
                y: 0
                width: 300
                height: 965
                color: "#191b1f"
                Layout.minimumWidth: 0
                opacity: 0.9
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.maximumHeight: 965
                Layout.maximumWidth: 300
                clip: true


            }

            Rectangle {
                id: right
                x: 405
                y: 5
                width: parent.width//755
                height: parent.height
                color: "#16181c"
                opacity: 0.8
                Layout.fillWidth: true
                Layout.fillHeight: true//605
                Layout.maximumHeight: 965//600
                //color: "#5d5d45"
                clip: true

                Image {
                    id: right_bg
                    x: 0
                    y: 0
                    width: 1515
                    //755
                    height: parent.height//610
                    clip: true
                    //source: "///img/img/background.png"
                }
            }

        }

        Rectangle {
            id: foot
            y: 1015
            width: parent.width//1080
            height: 65
            color: "#222225"
            opacity: 0.95
            Layout.maximumHeight: 60
            Layout.fillWidth: true
            Layout.fillHeight: false
            clip: true

            Button {
                id: button1
                x: 50
                y: 13
                width: 35
                height: 35
                Layout.maximumHeight: 40
                Layout.maximumWidth: 70
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: button2
                x: 120
                y: 8
                width: 45
                height: 45
                Layout.maximumHeight: 40
                Layout.maximumWidth: 70
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: button3
                x: 200
                y: 13
                width: 35
                height: 35
                Layout.maximumWidth: 70
                Layout.maximumHeight: 40
                Layout.fillHeight: true
                Layout.fillWidth: true
            }





        }
    }

    /*
    Image {
        id: image2
        width: parent.width
        height: parent.height
        source: "///img/img/background.png"
    }
*/


}
