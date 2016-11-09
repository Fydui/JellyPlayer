import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import my.Music 1.0
import QtMultimedia 5.6
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import QtQuick 2.0
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
            Text {
                id: musicteitle
                x:5
                y:5
                width: parent.width
                height: 30
                color: "#C8C8C8"
                font.family: "microsoft yahei"
                font.pixelSize: 23
                text:"正在播放: " + myTITLE

            }
        }

        RowLayout {
            id: middle
            y: 50
            width: parent.width//1080
            height: parent.height//965
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumHeight: 0
            Layout.maximumHeight: 965
            clip: true

            Rectangle {
                id: lift
                y: 0
                width: 300
                height: parent.height//965
                color: "#191b1f"
                Layout.minimumWidth: 0
                opacity: 0.9
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.maximumHeight: 965
                Layout.maximumWidth: 300
                clip: true

                ListView {
                    id: musiclist
                    x: 10
                    y: 5
                    width: 300
                    height: parent.height//965//605
                    spacing: 5
                    contentWidth: 0


                    model:myModel
                    delegate: Item {
                        x: 5
                        width: 300
                        height: 20

                        Row {
                            id: row1
                            Rectangle {
                                width: 300
                                height: 20
                                color: "Gray"
                                Text {
                                    id: musicname
                                    x:10
                                    y:2
                                    color: "#C8C8C8"
                                    font.family: "microsoft yahei"
                                    font.pixelSize: 16
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: qsTr(modelData);

                                    MouseArea {
                                        id: playArea
                                        anchors.fill:  parent
                                        onClicked: {myPlay.startPlay(modelData)}
                                    }
                                }
                            }
                            spacing: 5
                        }
                    }
                }
            }

            Rectangle {
                id: right
                x: 405
                y: 5
                width: parent.width
                height: parent.height
                color: "#16181c"
                opacity: 0.8
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.maximumHeight: 965
                clip: true

                ListView {
                    id: lrclist
                    x:500
                    y:30
                    width: 500
                    height: parent.height - 120
                    contentWidth: 0
                    model:myLRC
                    anchors.horizontalCenter: right.horizontalCenter
                    currentIndex: 100
                    spacing: 35
                    contentY: 100
                    delegate: Item {
                        Row {
                            id: row2
                            x:250

                            Text {
                                id: lrc
                                color: "#C8C8C8"
                                font.family: "microsoft yahei"
                                font.pixelSize: 23
                                text: qsTr(modelData);
                                anchors.horizontalCenter: row2.horizontalCenter
                                Connections {
                                    target: myPlay
                                    onPositionChanged: {
                                        lrclist.contentY = LRC_Y
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            id: foot
            x: 3
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
                id: last
                x: 50
                y: 13
                width: 35
                height: 35
                Layout.maximumHeight: 40
                Layout.maximumWidth: 70
                Layout.fillHeight: true
                Layout.fillWidth: true

                onClicked: {
                    myPlay.lastMusic();
                }
                Image {
                    id: last_pix
                    x: 0
                    y: 0
                    width: 35
                    height: 35
                    source: "///img/img/last.png"
                }
            }

            Button {
                id: sta_pau
                x: 120
                y: 8
                width: 45
                height: 45
                Layout.maximumHeight: 40
                Layout.maximumWidth: 70
                Layout.fillHeight: true
                Layout.fillWidth: true
                onClicked: {
                    myPlay.pausePlay();
                }


            }
            Image {
                id: sta_pau_bg
                x: 120
                y: 8
                width: 45
                height: 45
                source: "///img/img/start_music.png"

            }

            Button {
                id: next
                x: 200
                y: 13
                width: 35
                height: 35
                Layout.maximumWidth: 70
                Layout.maximumHeight: 40
                Layout.fillHeight: true
                Layout.fillWidth: true
                onClicked: {
                    myPlay.nextMusic();
                }
                Image {
                    id: next_pix
                    x: 0
                    y: 0
                    width: 35
                    height: 35
                    source: "///img/img/next.png"
                }
            }

            RowLayout {
                id: footbody
                x: 270
                width: 810
                height: 60
                spacing: 5


                RowLayout {
                    id: progress
                    x: 0
                    y: 20
                    width: 580
                    height: 60
                    spacing: 5
                    Layout.maximumWidth: 580

                    Text {
                        id: s_time
                        y: 0
                        width: 40
                        height: 20
                        color: "#C8C8C8";
                        text: mySTIME
                        font.pixelSize: 18

                    }

                    Slider {
                        id: bar
                        x: 50
                        width: 450
                        height: 20
                        Layout.maximumWidth: 550
                        Layout.maximumHeight: 20
                        Layout.fillWidth: true
                        maximumValue: myPlay.getEndtime();
                        value: setNOW
                        onPressedChanged:  {
                            myPlay.setNowMusicPos(value);
                        }

                    }

                    Text {
                        id: e_time
                        x: 515
                        y: 0
                        width: 40
                        height: 20
                        color: "#C8C8C8"
                        text: myETIME
                        font.pixelSize: 18
                    }


                }


                RowLayout {
                    id: vol_body
                    x: 580
                    width: 230
                    height: 60
                    Layout.minimumHeight: 20
                    Layout.minimumWidth: 230
                    Layout.maximumHeight: 20
                    Layout.maximumWidth: 230
                    Layout.fillWidth: false


                    Image {
                        id: vol_pix
                        x: 5
                        y: 20
                        width: 20
                        height: 20
                        Layout.maximumHeight: 20
                        Layout.maximumWidth: 20
                        source: "///img/img/vol.png"

                    }

                    Slider {
                        id: volume
                        x: 25
                        y: 20
                        width: 120
                        height: 20
                        Layout.maximumHeight: 20
                        Layout.maximumWidth: 120
                        Layout.fillWidth: true
                        maximumValue: 100
                        value: myPlay.getVol();
                        onValueChanged: {
                            myPlay.setVol(value);
                        }
                    }

                    Button {
                        id: loop
                        x: 175
                        y: 20
                        width: 30
                        height: 20
                        text: qsTr("")
                        Layout.minimumHeight: 20
                        Layout.minimumWidth: 30
                        Layout.maximumHeight: 20
                        Layout.maximumWidth: 30
                    }

                }
            }


        }
    }

}
