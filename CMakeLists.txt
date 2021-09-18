###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME ResourcesLoader)
project(${PROJECT_NAME} VERSION 1.0.0
        DESCRIPTION "Assets' loader for SFML Game"
        LANGUAGES CXX
        )

###################################################################################################
##
##      Project options
##
###################################################################################################

option(USE_TEST "Turn on testing" On)

###################################################################################################
##
##      Compilation options
##
###################################################################################################

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)

###################################################################################################
##
##      Header library
##
###################################################################################################

add_library(${PROJECT_NAME}_header INTERFACE)
target_include_directories(${PROJECT_NAME}_header INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>
        )
target_compile_features(${PROJECT_NAME}_header INTERFACE cxx_std_17)

add_library(${PROJECT_NAME}::headers ALIAS ${PROJECT_NAME}_header)

###################################################################################################
##
##      Compiled library
##
###################################################################################################


add_library(${PROJECT_NAME}_library STATIC src/AssetsLoader.hpp src/AssetsLoader.inl)
target_link_libraries(${PROJECT_NAME}_library PUBLIC ${PROJECT_NAME}_header)
set_target_properties(
        ${PROJECT_NAME}_library PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINKER_LANGUAGE CXX
)

add_library(${PROJECT_NAME}::library ALIAS ${PROJECT_NAME}_library)

###################################################################################################
##
##      Tests
##
###################################################################################################

if (NOT USE_TEST)
    message(STATUS "Tests is disabled")
else ()
    add_subdirectory(test)
endif ()
