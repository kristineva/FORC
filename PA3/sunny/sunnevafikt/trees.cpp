#include <iostream>

#include "trees.h"

using namespace std;



// DataClass::DataClass(int number, char letter){
//     this->letter = letter;
//     this->number = number;
// }

// ostream& operator<<(ostream& out, const DataClass dc){
//     if(dc.number != 0){
//         out << "{" << dc.letter << ":" << dc.number << "}";
//     }
//     return out;
// }

// bool DataClass::operator<(const DataClass dc) const{
//     return number < dc.number;
// }

// bool DataClass::operator>(const DataClass dc) const{
//     return number > dc.number;
// }

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
    return node1->number < node2->number;
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

ostream& operator<<(ostream& out, const HuffTree *ht){
    if(ht->root != NULL){
        out << ht->root;
    }
    return out;
}