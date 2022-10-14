

set( GOOGLETEST_LIBRARIES      gmock gmock_main gtest gtest_main )
set( GOOGLETEST_LINK_LIBRARIES ${GOOGLETEST_LIBRARIES} pthread )


if( USE_GLOBAL_GOOGLETEST_INSTALLATION )

  if( NOT GOOGLETEST_PATH )

    set( GOOGLETEST_PATH "${CMAKE_SOURCE_DIR}/googletest" )
    message(STATUS "GOOGLETEST_PATH not set, setting it to ${GOOGLETEST_PATH} !")

  endif( NOT GOOGLETEST_PATH )

  set( GOOGLETEST_INCLUDE_PATH "${GOOGLETEST_PATH}/googlemock/include" "${GOOGLETEST_PATH}/googletest/include" )
  set( GOOGLETEST_LIBRARY_PATH "${GOOGLETEST_PATH}/build/lib" )

  include_directories( ${GOOGLETEST_INCLUDE_PATH} )
  link_directories( ${GOOGLETEST_LIBRARY_PATH} )


  foreach(LIBNAME ${GOOGLETEST_LIBRARIES})

    add_library( ${LIBNAME} STATIC IMPORTED )

    set_target_properties( ${LIBNAME}
                           PROPERTIES
                           IMPORTED_LOCATION         "${GOOGLETEST_LIBRARY_PATH}/lib${LIBNAME}.a"
                           IMPORTED_LOCATION_RELEASE "${GOOGLETEST_LIBRARY_PATH}/lib${LIBNAME}.a"
                           IMPORTED_LOCATION_DEBUG   "${GOOGLETEST_LIBRARY_PATH}/lib${LIBNAME}.a"
                           IMPORTED_CONFIGURATIONS   "RELEASE;DEBUG" )

  endforeach(LIBNAME ${GOOGLETEST_LIBRARIES})


else( USE_GLOBAL_GOOGLETEST_INSTALLATION )

  add_subdirectory( ${CMAKE_SOURCE_DIR}/googletest )

endif( USE_GLOBAL_GOOGLETEST_INSTALLATION )

