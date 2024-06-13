#include<iostream>
#include<string>

class Node {
    public:
        string info;
        Node* leftchild;
        Node* rightchild;

    //Constructor for the node class
    Node(string i, Node* l, Node* r){
        info = i;
        leftchild = l;
        rightchild = r;
    }
};