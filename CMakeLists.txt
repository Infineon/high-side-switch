cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Arduino Library Template
set(corelib high-side-switch)

project(${corelib} CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)

# Coverage Flags
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY          ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY          ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY          ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG    ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG    ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG    ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_BINARY_DIR}/lib)

message( STATUS "PROJECT_NAME : ${PROJECT_NAME}" )
message( STATUS "CMAKE_BUILD_TYPE : ${CMAKE_BUILD_TYPE}" )
message( STATUS "CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}" )
message( STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}" )

include(CompilerSettings)

include_directories(
    src/corelib
    src/pal
)
# Header & Source Files
set(Headers
    src/corelib
    src/pal
    )

file(GLOB Sources CONFIGURE_DEPENDS src/corelib/*.cpp)

# Add Library
add_library(${corelib} ${Sources} ${Headers})

# Currently only using this target for rasbperry pi host
# if (CMAKE_HOST_UNIX)
#     # Add directory
#     add_subdirectory(src/framework/raspberrypi)
# endif()

option(SETUP_PROJECT_TESTS "Enable and setup project tests." ON)

if(SETUP_PROJECT_TESTS)

    # Add GoogleTest
    option(USE_GLOBAL_GOOGLETEST_INSTALLATION "Use available global installation of googletest." ON)
    include(UseGoogleTestInstallation)

    # Enable Testing with CTest
    enable_testing()

    # Add Tests Folder
    add_subdirectory(test/unit)

endif()