#include "opt_node.h"
#include <vector>

class OPTree{
    private:
        vector<vector<int>> costs;
        vector<vector<int>> roots;
        vector<string> allKeys;
        vector<int> frequencies;
        int height(OPT_node* node);
        void recursiveWeightedDepth(OPT_node* node, int depth, long long& sum, long long& totalFreq);
        int n;
    public:
        OPTree(const vector<string>& keys, const vector<int>& freqs);
        OPT_node* rootNode = nullptr;
        OPT_node* buildTree(int left, int right);
        int compute();
        int getHeight();
        double avgSearchDepth();
};