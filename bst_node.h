#pragma once
#include <iostream>

using namespace std;

struct BST_node{
    string key;
    BST_node* left;
    BST_node* right;
    int frequency;
    BST_node(const string& k) : key(k), left(nullptr), right(nullptr), frequency(1) {}
};