#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <chrono>
#include "bst.h"
#include "avl.h"

using namespace std;

vector<string> getInput(ifstream& file){
    vector<string> allWords (0);
    string line;

    while(getline(file, line)){
        if(!line.empty() && line.back() == '\r'){ // removes the stupid invisible '\r' at the end of words
            line.pop_back();
        }
        allWords.push_back(line);
    }
    
    file.close();
    return allWords;
}
template <typename T>
void printTreeStuff(T tree, int uniqueCount){
    if(is_same_v<T, BinarySearchTree>){
        cout << "Binary search tree test" << endl;
    }
    if(is_same_v<T, AVLTree>){
        cout << "AVL tree test" << endl;
    }
    cout << "Building tree...done." << endl;
    cout << "Number of unique words: " << uniqueCount << endl;
    cout << "Height of tree: " << tree.getHeight() << endl;
    cout << "All words found." << endl;
    cout << "Average search depth: " << tree.avgSearchDepth() << endl;
    cout << endl;
}

void header(int wordCount){
    cout << "Reading source word...done." << endl;
    cout << "Number of words: " << wordCount << endl << endl;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    ifstream inputFile("TestData/OptimalniBinarniVyhledavaciStrom/Test5.txt");
    if (!inputFile.is_open()){
        cout << "Failed to open the file!" << endl;
        return 1;
    }

    unordered_map<string, int> freqMap;
    vector<string> wrds = getInput(inputFile);    

    for(const auto& word : wrds){
        freqMap[word]++; 
    }

    int wordCount = wrds.size();
    int uniqueCount = freqMap.size();

    BinarySearchTree bst;
    for(const auto& word : wrds){
        bst.insert(word);
    }

    AVLTree avl;
    for(const auto& word : wrds){
        avl.insert(word);
    }
    
    header(wordCount);
    printTreeStuff(bst, uniqueCount);
    printTreeStuff(avl, uniqueCount);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Program ran for " << duration.count() << " ms" << std::endl;

    return 0;
}
