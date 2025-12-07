#pragma once
#include <iostream>

using namespace std;
/**
 * @struct OPT_node
 * @brief Represents a node in an Optimal Binary Search Tree (OBST).
 *
 * Each node stores a key, its frequency of access, and pointers to left and right child nodes.
 */
struct OPT_node{
    /** @brief Key stored in the node. */
    string key;
    /** @brief Pointer to the left child node. */
    OPT_node* left;
    /** @brief Pointer to the right child node. */
    OPT_node* right;
    /** @brief Frequency of words for the key. */
    int frequency;
    /**
     * @brief Constructs an OPT_node with a given key and optional frequency.
     * @param k Key to store in the node.
     * @param freq Frequency of the key (default is 1).
     */
    OPT_node(const string& k, int freq = 1) : key(k), left(nullptr), right(nullptr), frequency(freq) {}
};

