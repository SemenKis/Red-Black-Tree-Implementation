#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "../RedBlackTree/RedBlackTree.hpp"
#include "../AVLTree/AVLTree.hpp"

using Clock = std::chrono::high_resolution_clock;

int main() {

    std::vector<int> sizes = {
        1000,
        5000,
        10000,
        50000,
        100000
    };

    std::mt19937 generator(42);

    std::cout
        << "Size,RB_Insert,AVL_Insert,RB_Search,AVL_Search\n";

    for (int size : sizes) {

        // Generate 0 ... size-1
        std::vector<int> values(size);
        std::iota(values.begin(), values.end(), 0);

        // Same random order for both trees
        std::shuffle(
            values.begin(),
            values.end(),
            generator
        );


        // ==========================================
        // Red-Black insertion
        // ==========================================

        RedBlackTree rbTree;

        auto start = Clock::now();

        for (int value : values) {
            rbTree.insert(value);
        }

        auto end = Clock::now();

        auto rbInsert =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(end - start).count();


        // ==========================================
        // AVL insertion
        // ==========================================

        AVLTree avlTree;

        start = Clock::now();

        for (int value : values) {
            avlTree.insert(value);
        }

        end = Clock::now();

        auto avlInsert =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(end - start).count();


        // ==========================================
        // Red-Black search
        // ==========================================

        start = Clock::now();

        for (int value : values) {
            rbTree.contains(value);
        }

        end = Clock::now();

        auto rbSearch =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(end - start).count();


        // ==========================================
        // AVL search
        // ==========================================

        start = Clock::now();

        for (int value : values) {
            avlTree.contains(value);
        }

        end = Clock::now();

        auto avlSearch =
            std::chrono::duration_cast<
                std::chrono::microseconds
            >(end - start).count();


        std::cout
            << size << ","
            << rbInsert << ","
            << avlInsert << ","
            << rbSearch << ","
            << avlSearch << "\n";
    }

    return 0;
}