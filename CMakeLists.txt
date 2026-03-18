cmake_minimum_required(VERSION 3.19)
project(SnipShot LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SnipShot
    WIN32 MACOSX_BUNDLE
    main.cpp
    mywidget.cpp
    mywidget.h
    snipasteapp.h snipasteapp.cpp
)

qt_add_resources(SnipShot "app_resources"
    PREFIX "/"
    FILES
        icon/logo.png
)

target_link_libraries(SnipShot
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS SnipShot
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SnipShot
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
