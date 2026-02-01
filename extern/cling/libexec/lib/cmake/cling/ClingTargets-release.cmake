#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "clingInterpreter" for configuration "Release"
set_property(TARGET clingInterpreter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clingInterpreter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingInterpreter.a"
  )

list(APPEND _cmake_import_check_targets clingInterpreter )
list(APPEND _cmake_import_check_files_for_clingInterpreter "${_IMPORT_PREFIX}/lib/libclingInterpreter.a" )

# Import target "clingMetaProcessor" for configuration "Release"
set_property(TARGET clingMetaProcessor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clingMetaProcessor PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingMetaProcessor.a"
  )

list(APPEND _cmake_import_check_targets clingMetaProcessor )
list(APPEND _cmake_import_check_files_for_clingMetaProcessor "${_IMPORT_PREFIX}/lib/libclingMetaProcessor.a" )

# Import target "clingUserInterface" for configuration "Release"
set_property(TARGET clingUserInterface APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clingUserInterface PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingUserInterface.a"
  )

list(APPEND _cmake_import_check_targets clingUserInterface )
list(APPEND _cmake_import_check_files_for_clingUserInterface "${_IMPORT_PREFIX}/lib/libclingUserInterface.a" )

# Import target "clingUtils" for configuration "Release"
set_property(TARGET clingUtils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clingUtils PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingUtils.a"
  )

list(APPEND _cmake_import_check_targets clingUtils )
list(APPEND _cmake_import_check_files_for_clingUtils "${_IMPORT_PREFIX}/lib/libclingUtils.a" )

# Import target "libclingJupyter" for configuration "Release"
set_property(TARGET libclingJupyter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libclingJupyter PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingJupyter.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libclingJupyter.dylib"
  )

list(APPEND _cmake_import_check_targets libclingJupyter )
list(APPEND _cmake_import_check_files_for_libclingJupyter "${_IMPORT_PREFIX}/lib/libclingJupyter.dylib" )

# Import target "libcling" for configuration "Release"
set_property(TARGET libcling APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libcling PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcling.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libcling.dylib"
  )

list(APPEND _cmake_import_check_targets libcling )
list(APPEND _cmake_import_check_files_for_libcling "${_IMPORT_PREFIX}/lib/libcling.dylib" )

# Import target "clingDemoPlugin" for configuration "Release"
set_property(TARGET clingDemoPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(clingDemoPlugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libclingDemoPlugin.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libclingDemoPlugin.dylib"
  )

list(APPEND _cmake_import_check_targets clingDemoPlugin )
list(APPEND _cmake_import_check_files_for_clingDemoPlugin "${_IMPORT_PREFIX}/lib/libclingDemoPlugin.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
