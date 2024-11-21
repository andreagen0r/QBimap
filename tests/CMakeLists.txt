find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(test_bimap test_bimap.cpp)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

include(Catch)
catch_discover_tests(test_bimap)

target_link_libraries(test_bimap Catch2::Catch2 Qt${QT_VERSION_MAJOR}::Core bimap)

target_include_directories(test_bimap PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

