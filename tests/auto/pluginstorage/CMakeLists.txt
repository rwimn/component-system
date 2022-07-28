find_package(Qt5 COMPONENTS Core Test REQUIRED)
#find_package(GTest COMPONENTS gtest gmock gtest_main gmock_main REQUIRED)

set(TEST pluginstoragetest)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(BAR_PLUGIN carplugin)

set(BAR_SOURCES
    barplugin.cpp
    barsnapin.cpp
)
set(BAR_HEADERS
    barsnapin.h
)

set(CMAKE_AUTOMOC ON)

add_library(${BAR_PLUGIN} SHARED ${BAR_SOURCES} ${BAR_HEADERS})

target_link_libraries(${BAR_PLUGIN} component-system_static)
target_link_libraries(${BAR_PLUGIN} Qt5::Core Qt5::Test)


add_executable(${TEST} ${SOURCES} ${HEADERS})
target_link_libraries(${TEST} Qt5::Core Qt5::Test)
target_link_libraries(${TEST} gtest gmock)
target_link_libraries(${TEST} component-system_static)

add_test(AllTestsComponentSystem ${TEST})
