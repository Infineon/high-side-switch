# cmake_minimum_required(VERSION 3.12.4)

include( TestMacros )

set( TEST_LIBRARIES     ${GOOGLETEST_LINK_LIBRARIES} ${GOOGLETEST_LINK_LIBRARIES} high-side-switch )
set( TEST_CPP_LIBRARIES ${TEST_LIBRARIES} stdc++ )
set( TEST_C_LIBRARIES   ${TEST_LIBRARIES} )


include_directories( ${CMAKE_SOURCE_DIR}/src/pal /usr/local/include )
link_directories( ${CMAKE_SOURCE_DIR}/build/lib /usr/local/lib )


###################################################################################################

set( GCOV_FILES_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${corelib}.dir/src )

add_custom_target( gcovr
                   COMMAND ${CMAKE_COMMAND} -E remove_directory coverage
                   COMMAND ${CMAKE_COMMAND} -E make_directory coverage
                   COMMAND ${CMAKE_MAKE_PROGRAM} test
                   COMMAND ${CMAKE_COMMAND} -E echo "=================== GCOVR ===================="
                   COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${GCOV_FILES_DIR} -b -k --gcov-ignore-parse-errors --html --html-details
                                 -o ${CMAKE_BINARY_DIR}/coverage/coverage.html --sonarqube ${CMAKE_BINARY_DIR}/coverage/coverage.xml
                   COMMAND ${CMAKE_COMMAND} -E echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )

###################################################################################################

# unit tests : individual functions
include_directories( ${CMAKE_SOURCE_DIR}/test/unit )

###################################################################################################
set( UNIT_TEST_CPP_LABELS "CPP;unit;coverage" )
set( UNIT_TEST_C_LABELS   "C;unit;coverage" )

set( UNIT_TEST_CPP_LIBRARIES ${TEST_CPP_LIBRARIES} )
set( UNIT_TEST_C_LIBRARIES   ${TEST_C_LIBRARIES} )

set ( TestNames "" )
set ( TestSources "" )

list(APPEND TestNames
    test_hss.cpp
    test_hss-shield-btt60xx.cpp
    test_hss-shield-bts5001x.cpp
    test_hss-shield-bts700x.cpp
    test_hss-shield-bts500xx.cpp
)

createSimpleTests( TESTS ${TestNames} LIBRARIES ${UNIT_TEST_CPP_LIBRARIES} LABELS ${UNIT_TEST_CPP_LABELS} SOURCES ${TestSources} )

add_dependencies(gcovr ${TestNames} )