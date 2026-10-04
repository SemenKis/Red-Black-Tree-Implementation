#include <gtest/gtest.h>

#include "../RedBlackTree/RedBlackTree.hpp"


TEST(RedBlackTreeTest, TreeStartsEmpty) {
    RedBlackTree tree;

    EXPECT_TRUE(tree.empty());
}


TEST(RedBlackTreeTest, InsertMakesTreeNotEmpty) {
    RedBlackTree tree;

    tree.insert(10);

    EXPECT_FALSE(tree.empty());
}


TEST(RedBlackTreeTest, FindsInsertedValues) {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(15));
}


TEST(RedBlackTreeTest, DoesNotFindMissingValue) {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);

    EXPECT_FALSE(tree.contains(100));
}


TEST(RedBlackTreeTest, HandlesRotation) {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(3);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(3));
}


TEST(RedBlackTreeTest, RemovesValue) {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    tree.remove(5);

    EXPECT_FALSE(tree.contains(5));
    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
}


TEST(RedBlackTreeTest, RemovesNodeWithTwoChildren) {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(12);
    tree.insert(20);

    tree.remove(15);

    EXPECT_FALSE(tree.contains(15));
    EXPECT_TRUE(tree.contains(12));
    EXPECT_TRUE(tree.contains(20));
}