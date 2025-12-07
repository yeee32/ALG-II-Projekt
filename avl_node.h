#pragma once
#include <iostream>

using namespace std;

struct AVL_node{
    string key;
    AVL_node* left;
    AVL_node* right;
    int frequency;
    int height;
    AVL_node(const string& k) : key(k), left(nullptr), right(nullptr), frequency(1), height(1) {}
};