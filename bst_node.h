#pragma once
#include <iostream>

using namespace std;

struct BST_node {
    string key;
    int frequency;
    BST_node* left;
    BST_node* right;
    BST_node(string k) : key(k), left(nullptr), right(nullptr), frequency(1) {}
};