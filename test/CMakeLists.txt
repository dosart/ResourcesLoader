###################################################################################################
##
##      Information about project
##
###################################################################################################

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Test_ResourcesLoader)
project(${PROJECT_NAME} VERSION 0.0.1
        LANGUAGES CXX
        )

find_package(GTest REQUIRED)

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
target_sources(${PROJECT_NAME}
        PRIVATE
        test_main.cpp
        loader_tests/test.cpp
        )
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${GTEST_BOTH_LIBRARIES}
        pthread
        sfml-graphics
        sfml-audio
        ResourcesLoader)

