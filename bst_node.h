#pragma once
#include <iostream>

using namespace std;

struct BST_node{
    BST_node(string k) : key(k), left(nullptr), right(nullptr), frequency(1) {}
    string key;
    int frequency;
    BST_node* left;
    BST_node* right;
};