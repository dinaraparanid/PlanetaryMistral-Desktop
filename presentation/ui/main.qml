import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1900
    height: 1000
    title: qsTr("Planetary Mistral")

    Rectangle {
        anchors.fill: parent

        Rectangle {
            id: menu
            anchors.bottom: parent.bottom
            border.color: "black"
            border.width: 2
            width: menu_form.width + 20
            height: menu_form.height + 20
            opacity: 0.5
            anchors.bottomMargin: menu_mouse_area.containsMouse ? 0 : -50

            MainMenu {
                id: menu_form
                anchors.centerIn: menu
            }
        }

        MouseArea {
            id: menu_mouse_area
            anchors.bottom: parent.bottom
            width: menu.width
            height: menu.height
            enabled: true
            hoverEnabled: true
        }

        Text {
            id: focused_button
            text: "Focused button"
            anchors.left: parent.left
            opacity: 0.5
            anchors.bottomMargin: 10
            anchors.bottom: menu.top
            anchors.leftMargin: 10
            font.pixelSize: 12
        }
    }
}
