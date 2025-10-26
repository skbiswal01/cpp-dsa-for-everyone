//
//  avlTree.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 13/09/25.
//

#include "avlTree.hpp"
#include <iostream>

AVLNode::AVLNode(int val) {
    data = val;
    lchild = nullptr;
    rchild = nullptr;
    height = 1;  // leaf AVLNode height = 1
}

AVL::AVL() {
    root = nullptr;
}

//helper utilities function
int AVL::AVLNodeHeight(AVLNode* p) {
    if (!p) return 0;
    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;
    return (hl > hr ? hl : hr) + 1;
}

int AVL::BalanceFactor(AVLNode* p) {
    if (!p) return 0;
    int hl = p->lchild ? p->lchild->height : 0;
    int hr = p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

AVLNode* AVL::LLRotation(AVLNode* p) {
    AVLNode* pl = p->lchild;
    AVLNode* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = AVLNodeHeight(p);
    pl->height = AVLNodeHeight(pl);

    return pl;
}

AVLNode* AVL::RRRotation(AVLNode* p) {
    AVLNode* pr = p->rchild;
    AVLNode* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = AVLNodeHeight(p);
    pr->height = AVLNodeHeight(pr);

    return pr;
}

AVLNode* AVL::LRRotation(AVLNode* p) {
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}

AVLNode* AVL::RLRotation(AVLNode* p) {
    p->rchild = LLRotation(p->rchild);
    return RRRotation(p);
}


void AVL::Inorder(AVLNode* p) {
    if (!p) return;
    Inorder(p->lchild);
    std::cout << p->data << " ";
    Inorder(p->rchild);
}


AVLNode* AVL::rInsert(AVLNode *p, int key){
    if (!p) {
        return new AVLNode(key);
    }
    
    if (key < p->data) {
        p->lchild = rInsert(p->lchild, key);
    }else if (key > p->data) {
        p->rchild = rInsert(p->rchild, key);
    } else {
        return p; // ignore duplicates
    }
    
    p->height = AVLNodeHeight(p);
    int bf = BalanceFactor(p);
    
    // Left heavy
    if (bf == 2) {
        if (BalanceFactor(p->lchild) >= 0) {
            return LLRotation(p);
        } else {
            return LRRotation(p);
        }
    }
        // Right heavy
    else if (bf == -2) {
        if (BalanceFactor(p->rchild) <= 0) {
            return RRRotation(p);
        } else {
            return RLRotation(p);
        }
    }
    
    
    return p;
}

void AVL::Insert(int key) {
    root = rInsert(root, key);
}


AVLNode* AVL::getRoot() {
    return root;
}
