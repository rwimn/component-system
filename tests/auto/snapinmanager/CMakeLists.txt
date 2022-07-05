find_package(Qt5 COMPONENTS Core Test REQUIRED)
find_package(GTest COMPONENTS gtest gmock gtest_main gmock_main REQUIRED)

set(TEST snapinmanagertest)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${TEST} ${SOURCES} ${HEADERS})
target_link_libraries(${TEST} Qt5::Core Qt5::Test)
target_link_libraries(${TEST} gtest gmock)
target_link_libraries(${TEST} component-system_static)

add_test(AllTestsComponentSystem ${TEST})
