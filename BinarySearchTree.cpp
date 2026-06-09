#include <iostream>
#include <string>
using namespace std;

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

class BinaryTree {
    public:
        Node* ROOT;

        BinaryTree() {
            ROOT = nullptr; // Initializing ROOT to null
        }

    void insert(string element) //Insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //Allocate memory for the new node

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //Locate the new node wich will be the parent of the node to be insert

        if (parent == nullptr) //If the parent is NULL (Tree is empty)
        {
            ROOT = newNode; //Mark the new node as ROOT
            return; //Exit
        }
        
        if (element < parent->info) //If the value in the data field of the new node is less than that of the parent 
        {
            parent->leftchild = newNode; //Make the left child of the parent point to the new node 
        }
        else if (element > parent->info) //If the value in the data field of the new node is grater than that
        {
            parent->rightchild = newNode; //Make the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode){
        //This function searches the currentNode of the specified node as well as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr; // Diperbaiki dari NULL ke nullptr
        while ((currentNode != nullptr) && (currentNode->info != element)){
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else 
                currentNode = currentNode->rightchild;
        }   
    }

    void inorder(Node* ptr){
        if (ROOT == nullptr){
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr){
            inorder(ptr->leftchild); //LEFT
            cout << ptr->info << " "; //ROOT
            inorder(ptr->rightchild); //RIGHT
        }
    }

    void preorder(Node* ptr){
        if (ROOT == nullptr){
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr){
            cout << ptr->info << " "; //ROOT
            preorder(ptr->leftchild); //LEFT
            preorder(ptr->rightchild); //RIGHT
        }
    }

    void postorder(Node* ptr){
        if (ROOT == nullptr){
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr){
            postorder(ptr->leftchild); //LEFT
            postorder(ptr->rightchild); //RIGHT
            cout << ptr->info << " "; //ROOT
        }
    }
};

int main(){
    BinaryTree x;
    while (true){