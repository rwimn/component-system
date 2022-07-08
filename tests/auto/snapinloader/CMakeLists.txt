find_package(Qt5 COMPONENTS Core Test REQUIRED)
find_package(GTest COMPONENTS gtest gmock gtest_main gmock_main REQUIRED)

set(TEST snapinloadertest)

set(SOURCES
    snapinloadertest.cpp
    main.cpp
)
set(HEADERS
    snapinloadertest.h
)

set(FOO_PLUGIN fooplugin)
set(BAR_PLUGIN barplugin)

set(FOO_SOURCES
    fooplugin.cpp
    foosnapin.cpp
)
set(FOO_HEADERS
    foosnapin.h
)

set(BAR_SOURCES
    barplugin.cpp
    barsnapin.cpp
)
set(BAR_HEADERS
    barsnapin.h
)

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(${FOO_PLUGIN} SHARED ${FOO_SOURCES} ${FOO_HEADERS})

target_link_libraries(${FOO_PLUGIN} component-system_static)
target_link_libraries(${FOO_PLUGIN} Qt5::Core Qt5::Test)


add_library(${BAR_PLUGIN} SHARED ${BAR_SOURCES} ${BAR_HEADERS})

target_link_libraries(${BAR_PLUGIN} component-system_static)
target_link_libraries(${BAR_PLUGIN} Qt5::Core Qt5::Test)


add_executable(${TEST} ${SOURCES} ${HEADERS})

target_link_libraries(${TEST} Qt5::Core Qt5::Test)
target_link_libraries(${TEST} gtest gmock)
target_link_libraries(${TEST} component-system_static)
target_link_libraries(${TEST} commontest_static)

add_dependencies(${TEST} ${BAR_PLUGIN} ${FOO_PLUGIN})

add_test(AllTestsComponentSystem ${TEST})
