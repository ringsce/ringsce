import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Column {
        anchors.centerIn: parent

        RadioButton { text: qsTr("Small") }
        RadioButton { text: qsTr("Medium");  checked: true }
        RadioButton { text: qsTr("Large") }
    }


    Pane {
        Material.theme: Material.Dark

        Button {
            text: qsTr("Button")
            highlighted: true
            Material.background: Material.Teal
        }
    }

    SplitView {
        anchors.fill: parent
        orientation: Qt.Horizontal

        Rectangle {
            width: 200
            Layout.maximumWidth: 400
            color: "lightblue"
            Text {
                text: "View 1"
                anchors.centerIn: parent
            }
        }
        Rectangle {
            id: centerItem
            Layout.minimumWidth: 50
            Layout.fillWidth: true
            color: "lightgray"
            Text {
                text: "View 2"
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            color: "lightgreen"
            Text {
                text: "View 3"
                anchors.centerIn: parent
            }
        }
    }
}
