#pragma once
#include "avl_node.h"

/**
 * @class AVLTree
 * @brief Represents an AVL (self-balancing binary search) tree.
 * @brief https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/
 *
 * This class supports insertion of keys while maintaining AVL balance,
 * computation of tree height, and calculation of average search depth.
 */
class AVLTree{
    private:
        /** @brief Pointer to the root node of the AVL tree. */
        AVL_node* root;
        /**
         * @brief Recursively inserts a key into the subtree rooted at the given node.
         * @param node Pointer to the root of the current subtree.
         * @param key Key to insert.
         * @return Pointer to the root node of the modified subtree.
         */
        AVL_node* recursiveInsert(AVL_node* node, const string& key);
        /**
         * @brief Performs a right rotation on the given node.
         * @param y Node to rotate.
         * @return New root after rotation.
         */
        AVL_node* rotateRight(AVL_node* y);
        /**
         * @brief Performs a left rotation on the given node.
         * @param x Node to rotate.
         * @return New root after rotation.
         */
        AVL_node* rotateLeft(AVL_node* x);
         /**
         * @brief Updates the height of the given node based on its children's heights.
         * @param node Node whose height is to be updated.
         */
        void updateHeight(AVL_node* node);
        /**
         * @brief Computes the balance factor of the given node.
         * @param node Node to check.
         * @return Balance factor (height of left subtree - height of right subtree).
         */
        int getBalance(AVL_node* node);

        /**
         * @brief Recursively calculates the weighted depth for average search depth computation.
         * @param node Pointer to the current node.
         * @param depth Current depth in the tree.
         * @param sum Running sum of weighted depths.
         * @param totalFreq Total frequency of all keys.
         */
        void recursiveWeightedDepth(AVL_node* node, int depth, long long& sum, long long& totalFreq);
        /**
         * @brief Computes the height of the given node recursively.
         * @param node Node whose height is to be calculated.
         * @return Height of the subtree rooted at the node.
         */
        int height(AVL_node* node);

    public:
        /**
         * @brief Constructs an empty AVL tree.
         */
        AVLTree() : root(nullptr) {}
        /**
         * @brief Inserts a key into the AVL tree, maintaining balance.
         * @param key Key to insert.
         */
        void insert(const string& key);
         /**
         * @brief Returns the height of the AVL tree.
         * @return Height of the tree.
         */
        int getHeight();
        /**
         * @brief Computes the average search depth of the AVL tree.
         * @return Average depth of a search in the tree.
         */
        double avgSearchDepth();
};