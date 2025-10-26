//
//  binarySearchTree.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 08/09/25.
//

#include "binarySearchTree.hpp"
#include <iostream>

using namespace std;

// default constructor
Node::Node() : lchild(nullptr), data(0), rchild(nullptr) {}

// parameterized constructor
Node::Node(int value) : lchild(nullptr), data(value), rchild(nullptr) {}


void BST::insert(int key){
    Node *t = root;
    Node* p;
    Node* r = nullptr;
    
    if(root == nullptr){
        root = new Node(key);
        return;
    }
    
    while(t != nullptr){
        r = t;
        if (key == t->data) return;    // no duplicates
        else if (key < t->data) t = t->lchild;
        else t = t->rchild;
    }
    
    p = new Node(key);
    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}


Node* BST::getRoot(){
    return root;
}



void BST::inorder(Node *p){
    if(p){
        inorder(p -> lchild);
        cout << p -> data << "," << flush;
        inorder(p -> rchild);
    }
}



Node* BST::Search(int key){
    Node *t = root;
    while(t != nullptr){
        if(t-> data == key){
            return t;
        }else if(key < t->data){
            t = t-> lchild;
        }else {
            t = t-> rchild;
        }
    }
    return nullptr;
}



Node* BST::insertRec(Node* p, int key){
    if (p == nullptr) {
            // insertion point found
            Node* t = new Node(key);
            return t;
    }
    if (key < p->data){
            p->lchild = insertRec(p->lchild, key);
        } else if (key > p->data){
            p->rchild = insertRec(p->rchild, key);
        }
        return p;
}


Node* BST:: Delete(Node* p, int key){
    Node* q;
    
    //first case node itself is nullptr
    if (p == nullptr){
            return nullptr;
    }
    
    //if the key is leaf node or rootnode with no child
    if (p->lchild == nullptr && p->rchild == nullptr){
            if (p == root){
                root = nullptr;
            }
            delete p;
            return nullptr;
        }
    
    if (key < p->data){
            p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    }else {
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }else {
            q = InSucc(p->rchild);
           p->data = q->data;
           p->rchild = Delete(p->rchild, q->data);
        }
    }
    
    return p;
}


int BST::Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}

Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}
