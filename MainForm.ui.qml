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
                    width: 240
                    height: parent.height//965//605
                    spacing: 5
                    contentWidth: 0

                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            number:"555 3246"

                            //colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            number:"555 3246"
                            //colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            number:"555 3246"
                            //colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                        ListElement {
                            name: "Grey"
                            number:"555 3246"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                        ListElement {
                            name: "Grey"
                            number:"555 3246"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                        ListElement {
                            name: "Grey"
                            number:"555 3246"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
                    delegate: Item {
                        x: 5
                        width: 80
                        height: 20
                        Row {
                            id: row1
                            Rectangle {
                                width: 230
                                height: 20
                                color: colorCode
                            }

                            Text {
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
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
                        id: e_time
                        y: 0
                        width: 40
                        height: 20
                        text: qsTr("Text")
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
                        value: 0.5
                    }

                    Text {
                        id: s_time
                        x: 515
                        y: 0
                        width: 40
                        height: 20
                        text: qsTr("Text")
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
                        value: 0.5
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

    /*
    Image {
        id: image2
        width: parent.width
        height: parent.height
        source: "///img/img/background.png"
    }
*/


}
