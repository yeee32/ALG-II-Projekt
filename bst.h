#pragma once
#include "bst_node.h"
#include <unordered_map>

class BinarySearchTree{
    private:
        BST_node* root;
        int recursiveGetHeight(BST_node* node);
        void recursiveWeightedDepth(BST_node* node, int depth, long long& sum, long long& freq);

    public:
        BinarySearchTree();
        void insert(const string& key);
        BST_node* search(BST_node* node, string key);
        BST_node* getRoot();
        void setFreqMap(unordered_map<string,int>* map);

        int getHeight();

        // odstranit
        void printBST(BST_node* node, int space);

        double avgSearchDepth();
};