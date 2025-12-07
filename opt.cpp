#include "opt.h"
#include <climits>

OPTree::OPTree(const vector<string>& keys, const vector<int>& freqs) : allKeys(keys), frequencies(freqs), n(keys.size()){
    costs.assign(n, vector<int>(n, 0));
    roots.assign(n, vector<int>(n, 0));
}

int OPTree::compute(){
    // knuths optimization
    for(int i = 0; i < n; i++){
        costs[i][i] = frequencies[i];
        roots[i][i] = i;
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j  < n; j++){
            int sumFreq = 0;
            for(int k = i; k <= j; k++){
                sumFreq += frequencies[k];
            }
            
            int leftBound = roots[i][j - 1];
            int rightBound   = roots[i + 1][j];

            if(leftBound < i){
                leftBound = i;
            }
            if(rightBound > j){
                rightBound = j;
            }  

            int bestCost = INT_MAX;

            for(int k = leftBound; k <= rightBound; k++){
                int leftCost = 0;
                if(k > i){
                    leftCost = costs[i][k - 1];
                }

                int rightCost = 0;
                if(k < j){
                    rightCost = costs[k + 1][j];
                }
                int total = leftCost + rightCost + sumFreq;

                if(total < bestCost){
                    bestCost = total;
                    roots[i][j] = k;
                }
            }

            costs[i][j] = bestCost;
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
