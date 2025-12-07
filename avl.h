#pragma once
#include "avl_node.h"

class AVLTree{
    private:
        AVL_node* root;
        AVL_node* recursiveInsert(AVL_node* node, const string& key);
        AVL_node* rotateRight(AVL_node* y);
        AVL_node* rotateLeft(AVL_node* x);
        void updateHeight(AVL_node* node);
        int getBalance(AVL_node* node);

        void recursiveWeightedDepth(AVL_node* node, int depth, long long& sum, long long& totalFreq);
        int height(AVL_node* node);

    public:
    AVLTree() : root(nullptr) {}
    void insert(const string& key);
    int getHeight();
    double avgSearchDepth();
};