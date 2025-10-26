//
//  linkedList.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 10/06/25.
//

#ifndef linkedList_hpp
#define linkedList_hpp

#include <stdio.h>

class Node {
public:
    int data;
    Node *next;
};

class doublyNode {
public:
    doublyNode *prev;
    int data;
    doublyNode *next;
    doublyNode(int val) {
            prev = nullptr;
            data = val;
            next = nullptr;
    };
};

class LinkedList {
private:
    Node *first;
    
public:
    LinkedList() {
        first=NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    
    void Display();
    int count();
    int add();
    int max();
    Node* Search(int key);
    Node* ImproSearch(int key);
    void Insert(int index, int x);
    void InsertLast(int x);
    void SortedInsert(int x);
    void Delete(int index);
    bool checkSorted();
    void DeleteDuplicate();
    void ReverseLinkedList();
    void Reverse2();
    void RecReverseLinkedList();
    void RecReverse(Node *current, Node *prev);
    void concatenate(LinkedList &Second);
    LinkedList Merge(const LinkedList &second) const;
    void createLoop(int value);
    bool detectLoop();
};


class circularLinkedList {
private:
    Node *first;
public:
        circularLinkedList(int A[], int n); // create from array
        void Display();
        void Insert(int index, int x);
        void Delete(int index);
        ~circularLinkedList();
};


class DoublyLinkedList {
private:
    doublyNode* first;
public:
    DoublyLinkedList(int A[], int n); // constructor from array
    void Display();
    ~DoublyLinkedList();
    void insert(int index, int val);
    int Length();
    void Delete(int index);
    void reverse();
};

#endif /* linkedList_hpp */


