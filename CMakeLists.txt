cmake_minimum_required(VERSION 3.16)

project(CvsQml_ToDoList VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appCvsQml_ToDoList
    main.cpp
    todomodel.cpp
    todomodel.h
)

qt_add_qml_module(appCvsQml_ToDoList
    URI CvsQml_ToDoList
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appCvsQml_ToDoList PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCvsQml_ToDoList
    PRIVATE Qt6::Quick
)

install(TARGETS appCvsQml_ToDoList
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
