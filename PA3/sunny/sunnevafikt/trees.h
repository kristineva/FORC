#include <iostream>

#include <unordered_map>

using namespace std;


class Node{
public:
    Node(char letter = ' ', int number = 0, Node *left = NULL, Node *right = NULL);
    virtual ~Node();

    friend ostream& operator<<(ostream& out, const Node *node);


    char letter;
    int number;
    Node *left;
    Node *right;
    

private:
    

};

class CompareNodes{
public:
    bool operator()(Node* node1, Node* node2);
};

class HuffTree{
public:
    HuffTree(Node *root = NULL);
    virtual ~HuffTree();
    Node* newNode(char letter, int number, Node* left, Node* right);
    void insert(Node *node);
    friend ostream& operator<<(ostream& out, const HuffTree *ht);


    void huffmanEncoding(Node* node, string str, unordered_map<char, string> &huffCode);
    void huffmanDecoding(Node* node, char letter, string code);
    void huffmanDecodingRecurr(Node* node, char letter, string code);
    Node *root;
private:
    
};