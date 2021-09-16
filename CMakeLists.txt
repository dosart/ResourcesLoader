###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Assets_Loader)
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
##      Source files
##
###################################################################################################


add_library(${PROJECT_NAME} STATIC src/AssetsLoader.hpp src/AssetsLoader.inl)
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINKER_LANGUAGE CXX
)

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
