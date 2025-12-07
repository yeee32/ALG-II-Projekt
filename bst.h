#pragma once
#include "bst_node.h"

/**
 * @class BinarySearchTree
 * @brief Represents a standard Binary Search Tree (BST).
 * @brief https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/
 * @brief Supports insertion, searching, height calculation, and average search depth computation.
 */
class BinarySearchTree{
    private:
        /** @brief Pointer to the root node of the BST. */
        BST_node* root;
        /**
         * @brief Recursively computes the height of the subtree rooted at the given node.
         * @param node Pointer to the root of the current subtree.
         * @return Height of the subtree.
         */
        int recursiveGetHeight(BST_node* node);
        /**
         * @brief Recursively calculates the weighted depth for average search depth computation.
         * @param node Pointer to the current node.
         * @param depth Current depth in the tree.
         * @param sum Running sum of weighted depths.
         * @param freq Total frequency of all keys.
         */
        void recursiveWeightedDepth(BST_node* node, int depth, long long& sum, long long& freq);
    public:
        /**
         * @brief Constructs an empty Binary Search Tree.
         */
        BinarySearchTree() : root(nullptr) {}
        /**
         * @brief Inserts a key into the BST.
         * @param key Key to insert.
         */
        void insert(const string& key);
        /**
         * @brief Searches for a key in the BST starting from the given node.
         * @param node Node to start the search from.
         * @param key Key to search for.
         * @return Pointer to the node containing the key, or nullptr if not found.
         */
        BST_node* search(BST_node* node, const string& key);
        /**
         * @brief Returns the root node of the BST.
         * @return Pointer to the root node.
         */
        BST_node* getRoot();
        /**
         * @brief Returns the height of the BST.
         * @return Height of the tree.
         */
        int getHeight();
        /**
         * @brief Computes the average search depth of the BST.
         * @return Average depth of a search in the tree.
         */
        double avgSearchDepth();
};