include("D:/Git/QT_Projects/SnipShot/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Release/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/SnipShot-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Git/QT_Projects/SnipShot/build/Desktop_Qt_6_8_3_MSVC2022_64bit-Release/SnipShot.exe
    GENERATE_QT_CONF
)
