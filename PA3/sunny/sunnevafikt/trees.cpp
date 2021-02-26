#include <iostream>

#include "trees.h"

using namespace std;



Node::Node(char letter, int number, Node *left, Node *right){
    this->letter = letter;
    this->number = number;
    this->left = left;
    this->right = right;
}

Node::~Node(){
    delete &letter;
    delete &number;
    delete left;
    delete right;
}


ostream& operator<<(ostream& out, const Node *node){
    if(node != NULL){
        out << node->left;
        out << " " << node->letter << ":" << node->number << " ";
        out << node->right;
    }
    return out;
}



bool CompareNodes::operator()(Node* node1, Node* node2){
    return node2->number < node1->number;
}


HuffTree::HuffTree(Node *root){
    this->root = root;
}

HuffTree::~HuffTree(){
    delete root;
}

Node* HuffTree::newNode(char letter, int number, Node* left, Node* right){
    Node* node = new Node();

    node->letter = letter;
    node->number = number;
    node->left = left;
    node->right = right;

    return node;
}

void HuffTree::huffmanEncoding(Node* node, string code, unordered_map<char, string> &huffCode){
    if (node == NULL){
        return;
    }
    if (!node->left && !node->right){
        huffCode[node->letter] = code;
    }

    huffmanEncoding(node->left, code + "0", huffCode);
    huffmanEncoding(node->right, code + "1", huffCode);
}

void HuffTree::huffmanDecodingBuildTreeRecurr(Node *node, char letter, string code){
    if (code.empty()){
        node->letter = letter;
        return;
    }

    if (code[0] == '0'){
        if (node->left == NULL){
            node->left = new Node();
        }
        huffmanDecodingBuildTreeRecurr(node->left, letter, code.erase(0, 1));
    }
    else{
        if (node->right == NULL){
            node->right = new Node();
        }
        huffmanDecodingBuildTreeRecurr(node->right, letter, code.erase(0, 1));
    }
}

void HuffTree::huffmanDecodingBuildTree(char letter, string code){
    huffmanDecodingBuildTreeRecurr(root, letter, code);
}

string HuffTree::huffmanDecodeRecurr(Node *node, string toDecode, string toReturn){
    if (!node->left && !node->right){
        toReturn += node->letter;
        if (toDecode.empty()){
            return toReturn;
        }
        return huffmanDecodeRecurr(root, toDecode, toReturn);
    }

    if (toDecode[0] == '0'){
        return huffmanDecodeRecurr(node->left, toDecode.erase(0, 1), toReturn);
    }

    if (toDecode[0] == '1'){
        return huffmanDecodeRecurr(node->right, toDecode.erase(0, 1), toReturn);
    }

    return toReturn;
}

string HuffTree::huffmanDecode(string toDecode){
    return huffmanDecodeRecurr(root, toDecode, "");
}

ostream& operator<<(ostream& out, const HuffTree *ht){
    if(ht->root != NULL){
        out << ht->root;
    }
    return out;
}