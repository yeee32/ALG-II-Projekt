#include "opt_node.h"
#include <vector>

/**
 * @class OPTree
 * @brief Represents an Optimal Binary Search Tree (OBST) for given keys and frequencies.
 * @brief https://www.geeksforgeeks.org/dsa/optimal-binary-search-tree-dp-24/
 *
 * This class computes the optimal binary search tree using dynamic programming.
 * It allows calculation of tree height, average search depth, and other tree metrics.
 */
class OPTree{
    private:
        /** @brief Matrix storing the costs of subtrees. */
        vector<vector<int>> costs;
        /** @brief Matrix storing the roots of subtrees. */
        vector<vector<int>> roots;
        /** @brief All keys to be included in the tree. */
        vector<string> allKeys;
        /** @brief Frequencies corresponding to each key. */
        vector<int> frequencies;
        /**
         * @brief Computes the height of the given node recursively.
         * @param node Pointer to the node whose height is to be calculated.
         * @return Height of the subtree rooted at the node.
         */
        int height(OPT_node* node);
         /**
         * @brief Recursively calculates the weighted depth for average search depth computation.
         * @param node Pointer to the current node.
         * @param depth Current depth in the tree.
         * @param sum Running sum of weighted depths.
         * @param totalFreq Total frequency of all keys.
         */
        void recursiveWeightedDepth(OPT_node* node, int depth, long long& sum, long long& totalFreq);
        /** @brief Number of keys in the tree. */
        int n;
    public:
        /**
         * @brief Constructs an OPTree given keys and their frequencies.
         * @param keys Vector of keys.
         * @param freqs Vector of corresponding frequencies for each key.
         */
        OPTree(const vector<string>& keys, const vector<int>& freqs);
        /** @brief Pointer to the root node of the tree. */
        OPT_node* rootNode = nullptr;
        /**
         * @brief Builds the optimal binary search tree for a given range.
         * @param left Left index of the range.
         * @param right Right index of the range.
         * @return Pointer to the root node of the subtree for the given range.
         */
        OPT_node* buildTree(int left, int right);
        /**
         * @brief Optimized with Knuth's optimization
         * @brief https://cp-algorithms.com/dynamic_programming/knuth-optimization.html
         * @brief Computes the optimal cost of the binary search tree.
         * @return The minimal cost of the tree.
         */
        int compute();
        /**
         * @brief Returns the height of the tree.
         * @return Height of the tree.
         */
        int getHeight();
        /**
         * @brief Computes the average search depth of the tree.
         * @return Average depth of a search in the tree.
         */
        double avgSearchDepth();
};