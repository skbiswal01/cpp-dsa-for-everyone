//
//  binaryTree.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 26/08/25.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <stdio.h>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;


struct Node {
    int data;
    Node* lchild;
    Node* rchild;
    Node(int x = 0) : data(x), lchild(nullptr), rchild(nullptr) {}
};

class Tree {
private:
    Node* root;
    
public:
    Tree() : root(nullptr) {}
    
    void CreateTree() {
            Node* p;
            Node* t;
            int x;
            queue<Node*> q;

            cout << "Enter root data: " << flush;
            if (!(cin >> x)) return;

            root = new Node(x);
            q.emplace(root);

            while (!q.empty()) {
                p = q.front(); q.pop();

                cout << "Enter left child data of " << p->data << ": " << flush;
                cin >> x;
                if (x != -1) {
                    t = new Node(x);
                    p->lchild = t;
                    q.emplace(t);
                }

                cout << "Enter right child data of " << p->data << ": " << flush;
                cin >> x;
                if (x != -1) {
                    t = new Node(x);
                    p->rchild = t;
                    q.emplace(t);
                }
            }
        }
    
    
    void Preorder() { preOrder(root); cout << "\n"; }
    void Inorder() { Inorder(root); cout << "\n"; }
    void Postorder() { Postorder(root); cout << "\n"; }
    
    void preOrder(Node *p) {
        if(p){
            cout << p -> data << " " << flush;
            preOrder(p-> lchild);
            preOrder(p -> rchild);
        }
    };
    
    void Inorder(Node* p) {
            if (p) {
                Inorder(p->lchild);      // left
                cout << p->data << " ";  // root
                Inorder(p->rchild);      // right
            }
        }
    
    void Postorder(Node* p) {
            if (p) {
                Postorder(p->lchild);    // left
                Postorder(p->rchild);    // right
                cout << p->data << " ";  // root
            }
    }
    
    void iterativeInorder(Node* p){
        stack<Node*> st;
        
    }
    
    void IterativeInOrder(){
        iterativeInOrder(root);
        cout << "\n";
    }
    
    void iterativeInOrder(Node *p){
        stack<Node*> st;
        
        while(p != nullptr ||  !st.empty()){
            if (p != nullptr) {
                st.push(p);
                p = p -> lchild;
            }else {
                p = st.top(); st.pop();
                cout << p -> data << " " << endl;
                p = p -> rchild;
            }
        }
    }
    
    
    void LevelOrder(){
        levelOrder(root);
        cout << "\n";
    }
    
    void levelOrder(Node* p){
        queue<Node*> q;
        if(!p) return;
        
        cout << p -> data << " " << endl;
        q.push(p);
        
        while(!q.empty()){
            p = q.front();
            q.pop();
            
            if(p -> lchild){
                cout <<  p -> lchild -> data << " " << endl;
                q.push(p->lchild);
            }
            if(p -> rchild){
                cout << p->rchild->data << " " << endl;
                q.push(p->rchild);
            }
        }
    }
    
    int searchInorder(int inArray[], int inStart, int inEnd, int data){
        for (int i=inStart; i<=inEnd; i++){
            if (inArray[i] == data){
                return i;
            }
        }
        return -1;
    }
    
    Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd){
        static int preIndex = 0;
        
        if (inStart > inEnd){
                return nullptr;
            }
        
        Node* node = new Node(preorder[preIndex++]);
        
        if (inStart == inEnd){
                return node;
        }
        
        int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
        node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
        node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
        
        return node;
    }
    
    void Count(){
        cout << count(root) << endl;
    }
    
    int count(Node *p){
        
        if(p != NULL){
            return count(p->lchild) + count(p -> rchild) + 1;
        }
        return 0;
    }
    
    void Height(){
        cout << height(root) << endl;
    }
    int height(Node *p){
        if (p == nullptr) return 0;
        int l = height(p->lchild);
        int r = height(p -> rchild);
        return 1 + max(l, r);
    }
    
    void CountLeaf(){
        cout << countLeaf(root) << endl;
    }
    
    int countLeaf(Node *p){
        if(p != nullptr){
            if(!p->lchild && !p->rchild){
                return 1;
            }else{
                return countLeaf(p->lchild) + countLeaf(p->rchild);
            }
        }
        return 0;
    }
};

#endif /* binaryTree_hpp */
