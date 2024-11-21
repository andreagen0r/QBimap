cmake_minimum_required(VERSION 3.16)

project(QBimap LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(QBimap
  main.cpp
)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(QBimap Qt${QT_VERSION_MAJOR}::Core bimap)

include(GNUInstallDirs)
install(TARGETS QBimap
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CTest)
