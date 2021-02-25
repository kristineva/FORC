#include <iostream>

using namespace std;



class DataClass{
public:
    DataClass(int number = 1, char letter = ' ');

    friend ostream& operator<<(ostream& out, const DataClass *dc);

    //bool operator<(const DataClass dc);
    //bool operator>(const DataClass dc);

    friend bool operator<(const DataClass & one, const DataClass &other){
        return (one.number < other.number);
    }

    int number;
    char letter;
};

class Node{
public:
    Node(DataClass *data = NULL, Node *left = NULL, Node *right = NULL);
    virtual ~Node();
    
    Node* find(char c, Node* &node);

    bool operator<(const Node node);
    bool operator>(const Node node);

    friend ostream& operator<<(ostream& out, const Node *node);

    DataClass *data;

private:
    
    Node *left;
    Node *right;
};

class HuffTree{
public:
    HuffTree(Node *root = NULL);
    virtual ~HuffTree();

    friend ostream& operator<<(ostream& out, const HuffTree *ht);

private:
    Node *root;
};