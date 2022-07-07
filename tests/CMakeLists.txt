if (NOT ${BUILD_TESTS})
  return()
endif()

add_subdirectory(auto)
add_subdirectory(manual)
