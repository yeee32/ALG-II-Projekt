#include "bst.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(const string& key){
      if (!root) { // if tree is empty, create node
        root = new BST_node(key);
        return;
    }

    BST_node* current = root;

    while(true){
            if(key == current->key){
                current->frequency++;
                return;
            }
            if(key < current->key){
                if(!current->left){
                    current->left = new BST_node(key);
                    return;
                }
                current = current->left;
            } 
            else{
                if(!current->right){
                    current->right = new BST_node(key);
                    return;
                }
                current = current->right;
            }
        }
}

BST_node* BinarySearchTree::search(BST_node* node, string key){
    if(node == nullptr || node->key == key){
        return node;
    }

    if(key < node->key){
        return search(node->left, key);
    }
    else{
        return search(node->right, key);
    }
}

BST_node* BinarySearchTree::getRoot(){
    return root;
}

// odstranit tohle
void BinarySearchTree::printBST(BST_node* node, int space = 0){
    if (!node) return;
    int indent = 4;
    space += indent;

    printBST(node->right, space);

    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << node->key << endl;

    printBST(node->left, space);
}

int BinarySearchTree::recursiveGetHeight(BST_node* node){
    if(node == nullptr){
        return 0;
    }
    int leftHeight = recursiveGetHeight(node->left);
    int rightHeight = recursiveGetHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

int BinarySearchTree::getHeight(){
    return recursiveGetHeight(root);
}

void BinarySearchTree::recursiveWeightedDepth(BST_node* node, int depth, long long& sum, long long& totalFreq){
    if (!node){
        return;
    }
    sum += depth * node->frequency;
    totalFreq += node->frequency;

    recursiveWeightedDepth(node->left, depth + 1, sum, totalFreq);
    recursiveWeightedDepth(node->right, depth + 1, sum, totalFreq);
}

double BinarySearchTree::avgSearchDepth(){
    long long weightedSum = 0;
    long long totalFreq = 0;

    recursiveWeightedDepth(root, 1, weightedSum, totalFreq);

    if(totalFreq == 0){
        return 0.0;
    }
    

    return (double)weightedSum / totalFreq;
}