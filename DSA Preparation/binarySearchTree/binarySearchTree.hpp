//
//  binarySearchTree.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 08/09/25.
//

#ifndef binarySearchTree_hpp
#define binarySearchTree_hpp

#include <stdio.h>
class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;

        // default constructor
        Node();

        // parameterized constructor
        Node(int value);
};

class BST {
private:
    Node* root;

public:
    BST(){root = nullptr;}
    Node* getRoot();
    void insert(int key);
    void inorder(Node *p);
    Node* Search(int key);
    Node* insertRec(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};

#endif /* binarySearchTree_hpp */
