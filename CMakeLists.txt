cmake_minimum_required(VERSION 3.14)

project("component system")

set(COMPONENT_SYSTEM_VERSION_MAJOR 0)
set(COMPONENT_SYSTEM_VERSION_MINOR 1)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(COMPONENT_SYSTEM_DIR "${CMAKE_BINARY_DIR}")

if(UNIX)
  include(GNUInstallDirs)
else()
  if (WIN32)
    set(${CMAKE_INSTALL_LIBDIR} "lib")
    set(${CMAKE_INSTALL_DATADIR} "share")
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
    message(STATUS "Setting installation destination on Windows to: ${CMAKE_INSTALL_PREFIX}")
  else()
    message(FATAL_ERROR "System not UNIX nor WIN32 - not implemented yet")
  endif()
endif()

option(BUILD_TESTS "Build the component system tests." OFF)
option(SETUP_CODECOVERAGE "Setup coverege for component system." OFF)

if (SETUP_CODECOVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

function(project_testcoverage_setup)
    if (PREFERENCES_EDITOR_BUILD_TESTS)
        setup_target_for_coverage_lcov(NAME coverage
            EXECUTABLE ctest -j 4
            EXCLUDE
                "${PROJECT_SOURCE_DIR}/tests/*"
                "**CompilerId*" "/usr/*"  "${CMAKE_BINARY_DIR}/*"
            )
    endif()
endfunction()

if (PREFERENCES_EDITOR_SETUP_CODECOVERAGE)
    project_testcoverage_setup()
endif()
