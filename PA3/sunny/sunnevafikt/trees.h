#include <iostream>

using namespace std;



class DataClass{
public:
    DataClass(char letter);

    friend ostream& operator<<(ostream& out, const DataClass *dc);

    int number;
    char letter;
};

class Node{
public:
    Node(DataClass *data = NULL, Node *left = NULL, Node *right = NULL);
    virtual ~Node();
    
    Node* find(char c, Node* &node);

    friend ostream& operator<<(ostream& out, const Node *node);

private:
    DataClass *data;
    Node *left;
    Node *right;
};