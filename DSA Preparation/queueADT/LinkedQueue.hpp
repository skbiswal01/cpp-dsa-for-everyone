//
//  LinkedQueue.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 19/08/25.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include <stdio.h>
#include "QueueADT.hpp"
#include <iostream>

using  namespace std;

template <typename T>
class LinkedQueue:  public QueueADT <T> {
private:
    struct Node {
        T data;
        Node * next;
        Node(T val) : data(val), next(nullptr) {};
    };
    
    Node* front;
    Node* rear;
    
public:
    LinkedQueue () {
        front = rear = nullptr;
    }
    
    bool isEmpty() override{
        return front == nullptr;
    }
    
    bool isFull()  override {
        return  false;
    }
    
    void enqueue(T x) override {
        Node* temp = new Node(x);
        if (rear == nullptr) {   // empty queue
            front = rear = temp;
        } else {
                    rear->next = temp;
                    rear = temp;
        }
    }
    
    T dequeue() override {
        if (isEmpty()) {
                    cout << "Queue Underflow!" << endl;
                    return -1;  // careful: this assumes T can be compared to -1
        }
        
        Node *temp = front;
        T val = temp->data;
        front = front->next;
        
        if (front == nullptr) rear = nullptr;
        delete temp;
        return val;
    }
    
    T frontElement() override {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return front->data;
    }
    
    
    void display() override {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    
    
    ~LinkedQueue() {
            while (!isEmpty()) {
                dequeue();
            }
        }
};

#endif /* LinkedQueue_hpp */
