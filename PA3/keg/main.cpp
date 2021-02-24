#include <iostream>
#include "trees.h"
#include <deque>

using namespace std;

int main(){
    // Node *root = new Node(new DataClass(1, 'a'), new Node(new DataClass(2, 'b'), NULL, new Node(new DataClass(4, 'd'), NULL, NULL)), new Node(new DataClass(3, 'c'), NULL, NULL));

    Node *root = NULL;
    deque<Node *> node_queue;

    Node *node = NULL;

    for (int i = 0; i < 12; i++) {
        node = new Node(new DataClass((char)((int)'a' + i), i + 1));

        node_queue.push_back(node);
    }

    while(!node_queue.empty()) {
        Node *left = node_queue.front();
        node_queue.pop_front();
        Node *right = node_queue.front();
        node_queue.pop_front();
        node = new Node(NULL, left, right);
        if(!node_queue.empty()) {
            node_queue.push_back(node);
        }
        
    }

    root = node;

    cout << root << endl;

    delete root;
    root = NULL;
    cout << root << endl;

}
