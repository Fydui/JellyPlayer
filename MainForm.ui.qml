import QtQuick 2.5
import QtQuick.Controls 2.0

Rectangle {

    width: 360;
    height: 360;
    color: "#ffffff"

    Image {
        id: bg;
        x: 0
        y: 0
        width: parent.width;
        height: parent.height;
        source: "qrc:///img/img/background.png";

    }

    Button {
        id: button1
        x: 80
        y: 650
        width: 70
        height: 70
        Image {
            id: s;
            width: 70
            height: 70
            source: "qrc:///img/img/start_music.png"
        }
    }

}
