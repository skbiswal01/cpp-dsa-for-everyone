//
//  CircularQueue.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 18/08/25.
//

#ifndef CircularQueue_hpp
#define CircularQueue_hpp

#include <stdio.h>
#include "QueueADT.hpp"
#include <iostream>

using namespace std;

template<typename T>
class CircularQueue:  public QueueADT <T> {
private:
    int front, rear, size;
    T* Q;   // dynamic array

public:
    CircularQueue (int s){
        size = s;
        front = rear = -1;
        Q = new T[size];
    }
    
    bool isEmpty() override {
        return front == -1;
    }
    
    bool isFull() override {
        return ((rear + 1) % size == front);
    }
    
    void enqueue(T x) override {
        if(isFull()){
            cout << "queue is overflow!" << endl;
            return;
        }
        
        if(isEmpty()){
            front = rear = 0;
        }else {
            rear  = (rear + 1) % size;
        }
        
        Q[rear] = x;
    }
    
    T dequeue() override {
        if (isEmpty()) {
                    cout << "Queue Underflow!" << endl;
                    return -1;
        }
        
        T x  = Q[front];
        
        if(front == rear){
            front = rear = -1;
        }else {
            front = (front + 1)%size;
        }
        return x;
    }
    
    void display() override {
        if (isEmpty()) {
                    cout << "Queue is empty." << endl;
                    return;
        }
        
        int i = front;
        do {
                    cout << Q[i] << " ";
                    i = (i + 1) % size;
                } while (i != (rear + 1) % size);
                cout << endl;
        
        
    }
    
    T frontElement() override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;   // careful: this works only if T is numeric
        }
        return Q[front];
    }
    
    ~CircularQueue()  override{
            delete[] Q;
        }
    
};

#endif /* CircularQueue_hpp */
