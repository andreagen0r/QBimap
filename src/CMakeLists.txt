add_library(bimap STATIC bimap.cpp)

find_package(Qt5 REQUIRED COMPONENTS Core)
target_link_libraries(bimap PRIVATE Qt5::Core)

target_include_directories(bimap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

