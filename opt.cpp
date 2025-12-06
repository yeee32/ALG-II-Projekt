#include "opt.h"

OPTree::OPTree(const vector<string>& keys, const vector<int>& freqs) : allKeys(keys), frequencies(freqs), n(keys.size()){
    costs.assign(n, std::vector<int>(n, 0));
    roots.assign(n, std::vector<int>(n, 0));
}

int OPTree::compute(){
    for(int i = 0; i < n; i++){
        costs[i][i] = frequencies[i];
        roots[i][i] = i;
    }

    for (int size = 1; size < n; size++) {
        for (int L = 0; L + size < n; L++) {
            int R = L + size;

            int sumFreq = 0;
            for(int k = L; k <= R; k++)
                sumFreq += frequencies[k];

            long long bestCost = INT64_MAX;
            int bestRoot = -1;

            for(int r = L; r <= R; r++){
                int leftCost = 0;
                if(r > L){
                    leftCost = costs[L][r - 1];
                }
                int rightCost = 0;
                if(r < R){
                    rightCost = costs[r + 1][R];
                }
                int total = leftCost + rightCost;

                if(total < bestCost){
                    bestCost = total;
                    bestRoot = r;
                }
            }

            costs[L][R] = bestCost + sumFreq;
            roots[L][R] = bestRoot;
        }
    }

    rootNode = buildTree(0, n - 1);

    return costs[0][n - 1];
}

OPT_node* OPTree::buildTree(int left, int right){
    if(left > right){
        return nullptr;
    }

    int r = roots[left][right];
    OPT_node* node = new OPT_node(allKeys[r], frequencies[r]);

    if(left == right){
        return node;
    }

    node->left = buildTree(left, r - 1);
    node->right = buildTree(r + 1, right);

    return node;
}

int OPTree::height(OPT_node* node){
    if(node == nullptr){
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int OPTree::getHeight(){
    return height(rootNode);
}

void OPTree::recursiveWeightedDepth(OPT_node* node, int depth, long long& sum, long long& totalFreq){
    if(!node){
        return;
    }
    sum += depth * node->frequency;
    totalFreq += node->frequency;

    recursiveWeightedDepth(node->left, depth + 1, sum, totalFreq);
    recursiveWeightedDepth(node->right, depth + 1, sum, totalFreq);
}

double OPTree::avgSearchDepth(){
    long long weightedSum = 0;
    long long totalFreq = 0;

    if(rootNode == nullptr){
        return 0.0;
    }

    recursiveWeightedDepth(rootNode, 1, weightedSum, totalFreq);

    if(totalFreq == 0){
        return 0.0;
    }
    
    return (double)weightedSum / totalFreq;
}
