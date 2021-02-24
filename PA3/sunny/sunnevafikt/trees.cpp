#include <iostream>

#include "trees.h"

using namespace std;


DataClass::DataClass(char letter){
    this->letter = letter;
}

ostream& operator<<(ostream& out, const DataClass *dc){
    if(dc != NULL){
        out << "{" << dc->letter << "}";
    }
    return out;
}

Node::Node(DataClass *data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
}

Node::~Node(){
    delete data;
    delete left;
    delete right;
}

Node* Node::find(char c, Node* &node){
    if (node == NULL){
        return node;
    }

    if (c < node->data->letter) {
        return find(c, node->left);
    }
    else if (node->data->letter < c) {
        return find(c, node->right);
    }
    return node;
}

ostream& operator<<(ostream& out, const Node *node){
    if(node != NULL){
        out << node->left;
        out << " " << node->data << " ";
        out << node->right;
    }
    return out;
}