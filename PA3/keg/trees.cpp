#include <iostream>
#include "trees.h"

using namespace std;

DataClass::DataClass(char letter, int counter) {
    this->letter = letter;
    this->counter = counter;
};

ostream& operator<<(ostream& out, const DataClass *dc) {
    if(dc != NULL) {
        out << "{" << dc->letter << ":" << dc->counter << "}";
    }

    return out;
};

Node::Node(DataClass *data, Node *left, Node *right) {
    this->data = data;
    this->left = left;
    this->right = right;

};

Node::~Node(){
    delete data;
    delete left;
    delete right;
};

ostream& operator<<(ostream& out, const Node *node) {
    if (node != NULL) {
        // INORDER
        out << node->left;
        out << " " << node->data << " ";
        out << node->right;

        // POSTORDER
        /* out << node->left;
        out << node->right;
        out << " " << node->data << " "; */
         
    }
    
    return out;

};