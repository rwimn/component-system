find_package(Qt5 COMPONENTS Core Test REQUIRED)
find_package(GTest COMPONENTS gtest gmock gtest_main gmock_main REQUIRED)

set(LIBRARY_NAME commontest_static)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${LIBRARY_NAME} Qt5::Core Qt5::Test)
target_link_libraries(${LIBRARY_NAME} gtest gmock)
target_link_libraries(${LIBRARY_NAME} component-system_static)
