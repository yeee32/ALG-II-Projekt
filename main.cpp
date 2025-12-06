#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <map>
#include <chrono>
#include "bst.h"
#include "avl.h"
#include "opt.h"

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
void printTreeStuff(T tree, int uniqueCount, ofstream& out){
    if(is_same_v<T, BinarySearchTree>){
        out << "Binary search tree test" << endl;
        out << "Building tree...done." << endl;
    }
    if(is_same_v<T, AVLTree>){
        out << "AVL tree test" << endl;
        out << "Building tree...done." << endl;
    }
    if(is_same_v<T, OPTree>){
        out << "Optimal binary search tree test" << endl;
    }
    out << "Number of unique words: " << uniqueCount << endl;
    out << "Height of tree: " << tree.getHeight() << endl;
    out << "All words found." << endl;
    out << "Average search depth: " << tree.avgSearchDepth() << endl;
    out << endl;
}

void header(int wordCount, ostream& out){
    out << "Reading source word...done." << endl;
    out << "Number of words: " << wordCount << endl << endl;
}

int main(int argc, char* argv[]){
    auto start = std::chrono::high_resolution_clock::now();

    if(argc != 2){
        cout << "need file name" << endl;
        exit(1);
    }

    string path = "TestData/";
    path.append(argv[1]);
    ifstream inputFile(path);

    if (!inputFile.is_open()){
        cout << "Failed to open the file!" << endl;
        exit(1);
    }

    ofstream outputFile("result.txt");

    map<string, int> freqMap;
    vector<string> wrds = getInput(inputFile);    

    for(const auto& word : wrds){
        freqMap[word]++; // gets unique words and their frequency
    }

    vector<string> keys;
    vector<int> freqs;

    // ordered keys and values
    for (auto &p : freqMap) {
        keys.push_back(p.first);
        freqs.push_back(p.second);
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
    
    OPTree opt(keys, freqs);
    opt.compute();

    header(wordCount, outputFile);
    printTreeStuff(bst, uniqueCount, outputFile);
    printTreeStuff(avl, uniqueCount, outputFile);
    printTreeStuff(opt, uniqueCount, outputFile);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    outputFile << "Program ran for " << duration.count() << " ms";

    outputFile.close();
    return 0;
}
