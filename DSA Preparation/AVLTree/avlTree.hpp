//
//  avlTree.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 13/09/25.
//

#ifndef avlTree_hpp
#define avlTree_hpp

#include <stdio.h>

class AVLNode{
public:
    int data;
    AVLNode* lchild;
    AVLNode* rchild;
    int height;
    AVLNode(int val);
};

class AVL {
private:
    AVLNode* root;

    // Helpers
    int AVLNodeHeight(AVLNode* p);
    int BalanceFactor(AVLNode* p);

    // Rotations
    AVLNode* LLRotation(AVLNode* p);
    AVLNode* RRRotation(AVLNode* p);
    AVLNode* LRRotation(AVLNode* p);
    AVLNode* RLRotation(AVLNode* p);

    // Recursive insert
    AVLNode* rInsert(AVLNode* p, int key);

public:
    AVL();

    // Public operations
    void Insert(int key);
    void Inorder();
    void Preorder();
    AVLNode* Search(int key);

    // For traversal helpers
    void Inorder(AVLNode* p);
    void Preorder(AVLNode* p);

    AVLNode* getRoot();
};
#endif /* avlTree_hpp */
