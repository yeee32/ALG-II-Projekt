#pragma once
#include <iostream>

using namespace std;

struct AVL_node{
    string key;
    int frequency;
    int height;
    AVL_node* left;
    AVL_node* right;
    AVL_node(string k) : key(k), left(nullptr), right(nullptr), frequency(1), height(1) {}
};