#include <iostream>

#include <fstream>

#include "node.h"

#include <queue>

#include <string.h>

#include <string>

#include <unordered_map>

#include <algorithm>

using namespace std;


int main(int argc, char ** argv){
    Node *node = NULL;

    HuffTree *tree = NULL;
    string lineString;
    string fileString;
    string uniqueString;
    unordered_map<char, string> huffCode;


    if (strcmp(argv[1],"-e") == 0){
        
        priority_queue<Node*, vector<Node*>, CompareNodes> node_queue;
        
        int countChar;
        int checkChar;
        
        ifstream fin;
        fin.open(argv[2]);

        while(!fin.eof()){
            fin >> lineString;
            fileString.append(lineString + "\n");
        }

        fin.close();


        for(int i = 0; i < fileString.length(); i++){

            checkChar = count(uniqueString.begin(), uniqueString.end(), fileString[i]);

            if (checkChar == 0){
                countChar = count(fileString.begin(), fileString.end(), fileString[i]);
                if (fileString[i] != '\n'){
                    uniqueString.append(string(1,fileString[i]));
                    node_queue.push(new Node(fileString[i], countChar, NULL, NULL));
                }
            }
        }


        sort(uniqueString.begin(), uniqueString.end());
        priority_queue<Node*, vector<Node*>, CompareNodes> copyQueue;
        copyQueue = node_queue;


        while(node_queue.size() > 1){
            Node *left = node_queue.top();
            node_queue.pop();
            Node *right = node_queue.top();
            node_queue.pop();

            countChar = left->number + right->number;
            node_queue.push(new Node('\0', countChar, left, right));
        }


        tree = new HuffTree(node_queue.top());

        tree->huffmanEncoding(tree->root, "", huffCode);

        ofstream fout;
        remove(argv[3]);
        fout.open(argv[3], ios_base::app);

        for (int i = 0; i < uniqueString.size(); i++){
            fout << uniqueString[i] << " " << huffCode[uniqueString[i]] << "\n";
        }

        fout << "\\\n\n";

        for (int i = 0; i < fileString.size(); i++){
            if (fileString[i] != '\n'){
                fout << huffCode[fileString[i]];
            }
            else{
                fout << fileString[i];
            }
        }
        fout.close();
    }

    else if (strcmp(argv[1],"-d") == 0){

        char letter;

        ofstream fout;
        remove(argv[3]);

        ifstream fin;
        fin.open(argv[2]);

        bool readCode = false;

        while(!fin.eof()){
            fin >> lineString;
            if (!readCode){
                if (lineString == "\\"){
                    fin >> lineString;
                    readCode = true;
                }
                
                else{
                    letter = lineString[0];
                    fin >> lineString;
                    huffCode[letter] = lineString;

                    node = new Node();

                    if (tree == NULL){
                        tree = new HuffTree(node);
                    }

                    string code;

                    for (unordered_map<char, string>::iterator it = huffCode.begin(); it != huffCode.end(); it++){
                        tree->huffmanDecodingBuildTree(it->first, it->second);
                        
                    }
                }
            }
            
            if (readCode){
                
                if (!fin.eof()){
                
                    fout.open(argv[3], ios_base::app);

                    fout << tree->huffmanDecode(lineString) << "\n";

                    fout.close();
                }
            }
        }

        fin.close();

    }

}