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

add_executable(${PROJECT_NAME})
set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_sources(
        ${PROJECT_NAME}
        PRIVATE
        src/main.cpp
        src/AssetsLoader.hpp
)
