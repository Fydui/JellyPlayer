import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import QtQuick 2.0
import QtQuick.LocalStorage 2.0
import QtQuick.Particles 2.0
import QtQuick.Templates 2.0

Rectangle {
    id: main

    width: 1920//1080
    height: 1080//720

    color: "#dcdce3"
    clip: true

    Image {
        id: image2
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
                y: 2
                width: 320
                height: 965
                color: "#191b1f"
                opacity: 0.9
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.maximumHeight: 965
                Layout.maximumWidth: 320
                clip: true
            }

            Rectangle {
                id: right
                x: 325
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
                    id: image1
                    x: 0
                    y: 0
                    width: parent.width//755
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
            clip: false
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
