#include <iostream>

#include "trees.h"

using namespace std;



DataClass::DataClass(int number, char letter){
    this->letter = letter;
    this->number = number;
}

ostream& operator<<(ostream& out, const DataClass dc){
    if(dc.number != 0){
        out << "{" << dc.letter << ":" << dc.number << "}";
    }
    return out;
}

bool DataClass::operator<(const DataClass dc) const{
    return number < dc.number;
}

bool DataClass::operator>(const DataClass dc) const{
    return number > dc.number;
}

Node::Node(DataClass data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
}

Node::~Node(){
    delete &data;
    delete left;
    delete right;
}

// Node* Node::find(char c, Node* &node){
//     if (node == NULL){
//         return node;
//     }

//     if (c < node->data->letter) {
//         return find(c, node->left);
//     }
//     else if (node->data->letter < c) {
//         return find(c, node->right);
//     }
//     return node;
// }

bool Node::operator<(Node const node) const{
    return data.number < node.data.number;
}

bool Node::operator>(Node const node) const{

    return data.number > node.data.number;
}

ostream& operator<<(ostream& out, const Node *node){
    if(node != NULL){
        out << node->left;
        out << " " << node->data << " ";
        out << node->right;
    }
    return out;
}

HuffTree::HuffTree(Node *root){
    this->root = root;
}

HuffTree::~HuffTree(){
    delete root;
}

ostream& operator<<(ostream& out, const HuffTree *ht){
    if(ht->root != NULL){
        out << ht->root;
    }
    return out;
}