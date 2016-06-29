if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")

  # Enable all warnings
  ADD_DEFINITIONS(-Wall)

  # Allow relocation
  ADD_DEFINITIONS(-fPIC)

  ADD_DEFINITIONS(-std=c++11 -stdlib=libc++)

endif()
