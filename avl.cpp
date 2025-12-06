#include "avl.h"

AVL_node* AVLTree::recursiveInsert(AVL_node* node, const string& key){
    if(node == nullptr){
        return new AVL_node(key);
    }
    if(key < node->key){
        node->left = recursiveInsert(node->left, key);
    }
    else if(key > node->key){
        node->right = recursiveInsert(node->right, key);
    }
    else{
        node->frequency++;
        return node; 
    }

    updateHeight(node);

    int balance = getBalance(node);    
    // LL
    if(balance > 1 && key < node->left->key){
        return rotateRight(node);
    }
    // RR
    if(balance < -1 && key > node->right->key){
        return rotateLeft(node);
    }
    // LR
    if(balance > 1 && key > node->left->key){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RL
    if(balance < -1 && key < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(const string& key){
    root = recursiveInsert(root, key);
}

int AVLTree::getBalance(AVL_node* node){
    if(node == nullptr){
        return 0;
    }
    return height(node->left) - height(node->right);
}

void AVLTree::updateHeight(AVL_node* node){
    if(node == nullptr){
        return;
    }
    node->height = 1 + max(height(node->left), height(node->right));
}

AVL_node* AVLTree::rotateRight(AVL_node* y){
    AVL_node* center = y->left;
    AVL_node* r = center->right;
    center->right = y;
    y->left = r;
    updateHeight(y);
    updateHeight(center);
    return center;
}
AVL_node* AVLTree::rotateLeft(AVL_node* x){
    AVL_node* center = x->right;
    AVL_node* l = center->left;
    center->left = x;
    x->right = l;
    updateHeight(x);
    updateHeight(center);
    return center;
}

int AVLTree::height(AVL_node* node){
    if(node == nullptr){
        return 0;
    }
    return node->height;
}

int AVLTree::getHeight(){
    return height(root);
}

void AVLTree::recursiveWeightedDepth(AVL_node* node, int depth, long long& sum, long long& totalFreq){
    if(!node){
        return;
    }
    sum += depth * node->frequency;
    totalFreq += node->frequency;

    recursiveWeightedDepth(node->left, depth + 1, sum, totalFreq);
    recursiveWeightedDepth(node->right, depth + 1, sum, totalFreq);
}

double AVLTree::avgSearchDepth(){
    long long weightedSum = 0;
    long long totalFreq = 0;

    recursiveWeightedDepth(root, 1, weightedSum, totalFreq);

    if(totalFreq == 0){
        return 0.0;
    }
    
    return (double)weightedSum / totalFreq;
}