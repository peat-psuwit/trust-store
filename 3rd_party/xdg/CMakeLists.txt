project(xdg)

cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS filesystem system unit_test_framework)

include_directories(
    .
    ${Boost_INCLUDE_DIRS}
)

add_library(xdg xdg.cpp)
set_property(TARGET xdg PROPERTY CXX_STANDARD 11)
target_link_libraries(xdg ${Boost_LIBRARIES})

enable_testing()
add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN -DBOOST_TEST_MODULE=xdg)
add_executable(xdg_test xdg_test.cpp)
set_property(TARGET xdg_test PROPERTY CXX_STANDARD 11)
target_link_libraries(xdg_test xdg)

add_test(xdg_test xdg_test)
