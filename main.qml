import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import my.Music 1.0

Window {
    visible: true
    width: 1080
    height: 720
    minimumWidth: 1080
    minimumHeight: 720

    title: qsTr("JellyPlayer")

    MainForm {
        anchors.fill: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            music.star();
        }
    }
    Music {
        id: music
        onStart: new ShowMusic()
    }

}
