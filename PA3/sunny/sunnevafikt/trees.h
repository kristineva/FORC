#include <iostream>

using namespace std;



class DataClass{
public:
    DataClass(int number = 0, char letter = ' ');

    friend ostream& operator<<(ostream& out, const DataClass dc);

    bool operator<(const DataClass dc) const;
    bool operator>(const DataClass dc) const;

    char letter;
    int number;
};

class Node{
public:
    Node(DataClass data = NULL, Node *left = NULL, Node *right = NULL);
    virtual ~Node();
    
    Node* find(char c, Node* &node);

    bool operator<( Node const node) const;
    bool operator>(Node const node) const;

    friend ostream& operator<<(ostream& out, const Node *node);

    DataClass data;
    Node *left;
    Node *right;

private:
    
   
};

class HuffTree{
public:
    HuffTree();
    HuffTree(Node root);
    virtual ~HuffTree();

    friend ostream& operator<<(ostream& out, const HuffTree ht);

private:
    Node root;
};