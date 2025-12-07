#pragma once
#include <iostream>

using namespace std;
/**
 * @struct AVL_node
 * @brief Represents a node in an AVL tree.
 *
 * Each node stores a key, frequency of words, height for balancing, and pointers to left and right child nodes.
 */
struct AVL_node{
    /** @brief Key stored in the node. */
    string key;
    /** @brief Pointer to the left child node. */
    AVL_node* left;
    /** @brief Pointer to the right child node. */
    AVL_node* right;
    /** @brief Frequency of words for the key. */
    int frequency;
    /** @brief Height of the node in the AVL tree. */
    int height;
    /**
     * @brief Constructs an AVL_node with a given key.
     * @param k Key to store in the node.
     *
     * By default, the frequency is set to 1 and height is set to 1.
     */
    AVL_node(const string& k) : key(k), left(nullptr), right(nullptr), frequency(1), height(1) {}
};