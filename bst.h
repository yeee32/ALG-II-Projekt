#pragma once
#include "bst_node.h"

class BinarySearchTree{
    private:
        BST_node* root;
        int recursiveGetHeight(BST_node* node);
        void recursiveWeightedDepth(BST_node* node, int depth, long long& sum, long long& freq);
    public:
        BinarySearchTree() : root(nullptr) {}
        void insert(const string& key);
        BST_node* search(BST_node* node, const string& key);
        BST_node* getRoot();
        int getHeight();
        double avgSearchDepth();
};