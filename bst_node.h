#pragma once
#include <iostream>

using namespace std;
/**
 * @struct BST_node
 * @brief Represents a node in a standard Binary Search Tree (BST).
 *
 * Each node stores a key, frequency of insertion/access, and pointers to left and right child nodes.
 */
struct BST_node{
    /** @brief Key stored in the node. */
    string key;
    /** @brief Pointer to the left child node. */
    BST_node* left;
    /** @brief Pointer to the right child node. */
    BST_node* right;
    /** @brief Frequency of words for the key. */
    int frequency;
    /**
     * @brief Constructs a BST_node with a given key.
     * @param k Key to store in the node.
     *
     * By default, the frequency is set to 1.
     */
    BST_node(const string& k) : key(k), left(nullptr), right(nullptr), frequency(1) {}
};