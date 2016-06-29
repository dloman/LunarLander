IF (WIN32)
  # https://cmake.org/cmake/help/v3.0/variable/WIN32.html
  # WIN32 is true on windows systems including win64
  CMAKE_MINIMUM_REQUIRED(VERSION 3.1.3)
ENDIF()

IF (MSVC)
  # Try to find the Toyon boost installation
  IF (CMAKE_CL_64)

    # Assume either VC-9 or VC-12.
    # The variable MSVC90 is defined for VC9.
    # The variable MSVC12 is defined for VC12.

    IF(EXISTS "C:/ExternalPackages/boost-1.55.0-t1-VC12/lib/x64" AND IS_DIRECTORY "C:/ExternalPackages/boost-1.55.0-t1-VC12/include/boost-1_55" AND MSVC12)
      SET(BOOST_LIBRARYDIR C:/ExternalPackages/boost-1.55.0-t1-VC12/lib/x64)
      SET(BOOST_INCLUDEDIR C:/ExternalPackages/boost-1.55.0-t1-VC12/include/boost-1_55)
      UNSET(BOOST_ROOT)
    ELSEIF(EXISTS "C:/ExternalPackages/boost-1.54.0-t1-VC9/lib/x64" AND IS_DIRECTORY "C:/ExternalPackages/boost-1.54.0-t1-VC9/include/boost-1_54" AND MSVC90)
      SET(BOOST_LIBRARYDIR C:/ExternalPackages/boost-1.54.0-t1-VC9/lib/x64)
      SET(BOOST_INCLUDEDIR C:/ExternalPackages/boost-1.54.0-t1-VC9/include/boost-1_54)
      UNSET(BOOST_ROOT)
    ENDIF()
  ELSE()
    IF(EXISTS "C:/ExternalPackages/boost-1.55.0-t1-VC12/lib/x86" AND IS_DIRECTORY "C:/ExternalPackages/boost-1.55.0-t1-VC12/include/boost-1_55" AND MSVC12)
      SET(BOOST_LIBRARYDIR C:/ExternalPackages/boost-1.55.0-t1-VC12/lib/x86)
      SET(BOOST_INCLUDEDIR C:/ExternalPackages/boost-1.55.0-t1-VC12/include/boost-1_55)
      UNSET(BOOST_ROOT)
    ELSEIF(EXISTS "C:/ExternalPackages/boost-1.54.0-t1-VC9/lib/x86" AND IS_DIRECTORY "C:/ExternalPackages/boost-1.54.0-t1-VC9/include/boost-1_54" AND MSVC90)
      SET(BOOST_LIBRARYDIR C:/ExternalPackages/boost-1.54.0-t1-VC9/lib/x86)
      SET(BOOST_INCLUDEDIR C:/ExternalPackages/boost-1.54.0-t1-VC9/include/boost-1_54)
      UNSET(BOOST_ROOT)
    ENDIF()
  ENDIF()

  # Disable boost's auto-link
  ADD_DEFINITIONS("-DBOOST_ALL_NO_LIB -D_WIN32_WINNT=0x0501")

  # Disable some annoying warnings
  ADD_DEFINITIONS("/wd4996")
ENDIF()
