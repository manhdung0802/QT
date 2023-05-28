import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12
import manhdung 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    ListModel{
//        id: myModel
//        ListElement{
//            content: "abc"
//            isDone: false
//        }
//        ListElement{
//            content: "xyz"
//            isDone: false
//        }
//    }

    TodoModel{
        id: myModel
    }

    ListView{
        id: myList
        model: myModel
        anchors.fill: parent

        anchors.leftMargin: 20
        height: parent.height
        header: Row{
            Button {
                text: "Append"
                onClicked: {
                    myModel.addItem();
                }
            }
        }
        delegate: Row{
            width: parent.width
            TextField{
                placeholderText: noidung
                width: parent.width - 200
                onTextEdited: {
                    noidung = text
                }
            }
            CheckBox{
                checked: trangthai
                onTextEdited: {
                    trangthai = checked
                }
            }
            Button{
                text: "Remove"
                onClicked: {
                    myModel.removeItem(index) // remove element
                }
            }
        }
        footer: Row{
            Button{
                text: "Close"
                onClicked: Qt.quit()
            }
        }
    }
}
