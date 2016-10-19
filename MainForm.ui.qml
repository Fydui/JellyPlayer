import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import QtQuick 2.0
import my.Music 1.0
import QtMultimedia 5.6

Rectangle {
    id: main

    width: 1080//1080
    height: 720//720
    Layout.minimumWidth: 1080
    Layout.minimumHeight: 720

    color: "#dcdce3"
    clip: true

    Image {
        id: main_bg
        width: parent.width
        height: parent.height
        Layout.minimumWidth: 1080
        Layout.minimumHeight: 720
        source: "///img/img/Qt3.jpg"
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
