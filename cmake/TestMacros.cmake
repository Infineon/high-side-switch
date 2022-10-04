
MACRO( createSimpleTests )

set( TestList    "" )
set( LibraryList "" )
set( SourceList  "" )
set( LabelList   "" )
set( CurrentVar  "" )

FOREACH( arg ${ARGN} )

  IF( ${arg} STREQUAL "LIBRARIES" )
    set( CurrentVar "LibraryList" )
  ELSEIF( ${arg} STREQUAL "LABELS" )
    set( CurrentVar "LabelList" )
  ELSEIF( ${arg} STREQUAL "TESTS" )
    set( CurrentVar "TestList" )
  ELSEIF( ${arg} STREQUAL "SOURCES" )
    set( CurrentVar "SourceList" )
  ELSE( ${arg} STREQUAL "LIBRARIES" )
    set( ${CurrentVar} ${${CurrentVar}} ${arg} )
  ENDIF( ${arg} STREQUAL "LIBRARIES" )
          
ENDFOREACH( arg ${ARGN} )


string( TOUPPER ${CMAKE_BUILD_TYPE} MY_LOCAL_BUILD_TYPE )


IF( ${MY_LOCAL_BUILD_TYPE} STREQUAL "DEBUG" )
 
    message( STATUS "#############################" )
    message( STATUS "ARGN        = ${ARGN}" )
    message( STATUS "TestList    = ${TestList}" )
    message( STATUS "LibraryList = ${LibraryList}" )
    message( STATUS "SourceList  = ${SourceList}" )
    message( STATUS "LabelList   = ${LabelList}" )
    message( STATUS "#############################" )
    
ENDIF( ${MY_LOCAL_BUILD_TYPE} STREQUAL "DEBUG" )
    

FOREACH( TestName ${TestList} )

  IF( ${MY_LOCAL_BUILD_TYPE} STREQUAL "DEBUG" )    

    message( STATUS "###" )
    message( STATUS "Testname  = ${TestName}" )
    message( STATUS "###" )

  ENDIF( ${MY_LOCAL_BUILD_TYPE} STREQUAL "DEBUG" )


  add_executable( ${TestName} ${TestName} ${SourceList} )
  target_link_libraries( ${TestName} PUBLIC ${LibraryList} )


  add_test( NAME ${TestName}
            COMMAND ${TestName} )

  set_tests_properties( ${TestName}
                        PROPERTIES
                        LABELS "${LabelList}")

ENDFOREACH( TestName ${TestList} )

ENDMACRO( createSimpleTests )
