#include <gtest/gtest.h>

#include "../AVLTree/AVLTree.hpp"


TEST(AVLTreeTest, TreeStartsEmpty) {
    AVLTree tree;

    EXPECT_TRUE(tree.empty());
}


TEST(AVLTreeTest, InsertMakesTreeNotEmpty) {
    AVLTree tree;

    tree.insert(10);

    EXPECT_FALSE(tree.empty());
}


TEST(AVLTreeTest, FindsInsertedValue) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(15));
}


TEST(AVLTreeTest, DoesNotFindMissingValue) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_FALSE(tree.contains(100));
}


TEST(AVLTreeTest, HandlesLeftLeftRotation) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(3);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(3));
}


TEST(AVLTreeTest, HandlesRightRightRotation) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(20);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
    EXPECT_TRUE(tree.contains(20));
}


TEST(AVLTreeTest, HandlesLeftRightRotation) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(7);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(7));
}


TEST(AVLTreeTest, HandlesRightLeftRotation) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
    EXPECT_TRUE(tree.contains(20));
}


TEST(AVLTreeTest, RemovesValue) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    tree.remove(5);

    EXPECT_FALSE(tree.contains(5));
    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
}


TEST(AVLTreeTest, RemovesNodeWithTwoChildren) {
    AVLTree tree;

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