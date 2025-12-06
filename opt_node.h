#pragma once
#include <iostream>

using namespace std;

struct OPT_node{
    string key;
    int frequency;
    OPT_node* left;
    OPT_node* right;
    OPT_node(const string& k, int freq = 1) : key(k), left(nullptr), right(nullptr), frequency(freq) {}
};

