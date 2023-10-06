import QtQuick 2.4
import QtQuick.Layouts 1.3

ColumnLayout {
    spacing: 10

    RowLayout {
        width: parent.width
        spacing: 20

        Text {
            id: position
            text: "Земля"
            textFormat: Text.RichText
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
            width: parent.width / 3
        }

        Text {
            id: weather
            text: "Погода"
            Layout.fillWidth: true
            width: parent.width / 3
        }

        Text {
            id: time
            text: "Время"
            Layout.fillWidth: true
            width: parent.width / 3
        }
    }

    RowLayout {
        width: parent.width
        spacing: 20

        RowLayout {
            spacing: 0

            Image {
                id: constellations_lines
                source: "res/images/constellations.png"
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: constellations_names
                source: "res/images/constellation_name.png"
                fillMode: Image.Stretch
                scale: 1
                transformOrigin: Item.Center
                antialiasing: false
                enabled: true
                smooth: true
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        RowLayout {
            spacing: 0

            Image {
                id: equatorial_grid
                source: "res/images/equatorial_grid.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: azimuthal_grid
                source: "res/images/azimuth_grid.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        RowLayout {
            spacing: 0

            Image {
                id: landscape
                source: "res/images/landscape.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: atmosphere
                source: "res/images/atmosphere.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: cardinal_directions
                source: "res/images/cardinal_directions.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        RowLayout {
            spacing: 0

            Image {
                id: deep_space
                source: "res/images/deep_space.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: planets
                source: "res/images/planets.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: exoplanets
                source: "res/images/exoplanets.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: meteor_showers
                source: "res/images/meteor_showers.png"
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: satellite
                source: "res/images/satellite.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        RowLayout {
            spacing: 0

            Image {
                id: night_vision
                source: "res/images/nightvision.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: full_screen
                source: "res/images/full_screen.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        RowLayout {
            spacing: 0

            Image {
                id: decrease_time_speed
                source: "res/images/previous.png"
                scale: 0.7
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: pause
                source: "res/images/pause.png"
                scale: 0.8
                transformOrigin: Item.Center
                Layout.fillWidth: false
                fillMode: Image.Stretch
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: current_time
                source: "res/images/current_time.png"
                scale: 0.8
                sourceSize.height: 40
                sourceSize.width: 40
            }

            Image {
                id: increase_time_speed
                source: "res/images/next.png"
                scale: 0.7
                sourceSize.height: 40
                sourceSize.width: 40
            }
        }

        Image {
            id: quit
            source: "res/images/quit.png"
            scale: 0.8
            sourceSize.height: 40
            sourceSize.width: 40
            clip: false
            visible: true
            fillMode: Image.Stretch
        }
    }
}
