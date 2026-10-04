cmake_minimum_required(VERSION 3.14)

project(RedBlackTreeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# =====================================================
# Red-Black Tree library
# =====================================================

add_library(
    red_black_tree
    RedBlackTree/RedBlackTree.cpp
)

target_include_directories(
    red_black_tree
    PUBLIC
    RedBlackTree
)


# =====================================================
# AVL Tree library
# =====================================================

add_library(
    avl_tree
    AVLTree/AVLTree.cpp
)

target_include_directories(
    avl_tree
    PUBLIC
    AVLTree
)


# =====================================================
# Main program
# =====================================================

add_executable(
    redblacktree
    RedBlackTree/main.cpp
)

target_link_libraries(
    redblacktree
    PRIVATE
    red_black_tree
)


# =====================================================
# GoogleTest
# =====================================================

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(
    gtest_force_shared_crt
    ON
    CACHE BOOL ""
    FORCE
)

FetchContent_MakeAvailable(googletest)


enable_testing()


add_executable(
    tree_tests

    tests/RedBlackTreeTest.cpp
    tests/AVLTreeTest.cpp
)

target_link_libraries(
    tree_tests
    PRIVATE
    red_black_tree
    avl_tree
    GTest::gtest_main
)


include(GoogleTest)

gtest_discover_tests(tree_tests)

add_executable(
    tree_benchmark
    benchmark/benchmark.cpp
)

target_link_libraries(
    tree_benchmark
    PRIVATE
    red_black_tree
    avl_tree
)