#include <iostream>

using namespace std;

class DataClass{
public:
    DataClass(char letter, int counter);

    friend ostream& operator<<(ostream& out, const DataClass *dc);

    char letter;
    int counter;
};

class Node{
public:
    Node(DataClass *data = NULL, Node *left = NULL, Node *right = NULL);
    virtual ~Node();

    friend ostream& operator<<(ostream& out, const Node *node);

private:
    DataClass *data;
    Node *left;
    Node *right;
};