find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(TEST management_console)

file(GLOB SOURCES  "*.cpp")
file(GLOB HEADERS  "*.h")
file(GLOB UI_FILES "*.ui")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${TEST} ${SOURCES} ${HEADERS} ${UI_FILES})
target_link_libraries(${TEST} Qt5::Core Qt5::Widgets)
