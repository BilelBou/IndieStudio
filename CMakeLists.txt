cmake_minimum_required(VERSION 3.0)
project(bomberman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/packages)
mark_as_advanced(IRRLICHT_LIBRARY IRRLICHT_INCLUDE_DIR IRRLICHT_DLL)


INCLUDE_DIRECTORIES(
    "/usr/include/irrlicht"
    "./include"
    "C:/Users/$67V000-QIIGRF35J0M4/Documents/irrlicht-1.8.4/include"
)
FILE( 
    GLOB_RECURSE
    INDIE
    src/*.cpp
    src/**/*.cpp
    include/*.hpp
    include/**/*.h*
)

add_executable(bomberman ${INDIE})

find_library(IRRLICHT_LIBRARY NAMES Irrlicht.lib
            PATHS
            "C:/Users/$67V000-QIIGRF35J0M4/Documents/irrlicht-1.8.4/lib/Win64-visualstudio"
            NO_DEFAULT_PATH
            )

find_file(IRRLICHT_DLL NAMES Irrlicht.dll
            PATHS
            "C:/Users/$67V000-QIIGRF35J0M4/Documents/irrlicht-1.8.4/bin/Win64-VisualStudio"
            DOC "C:/Users/$67V000-QIIGRF35J0M4/Documents/irrlicht-1.8.4/bin/Win64-VisualStudio/Irrlicht.dll"
            )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Irrlicht DEFAULT_MSG IRRLICHT_LIBRARY)


