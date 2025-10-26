
#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

#include "QueueADT.hpp"
#include <iostream>

using namespace std;

template <typename T>
class ArrayQueue:  public QueueADT <T> {
     T arr [100];
    int front, rear;
    
public:
    ArrayQueue() { front = -1; rear = -1; }
    bool isEmpty() override {
        return front == -1 || front > rear;
    }
    
   
    bool isFull() override {
        return rear == 99;
    }

    void enqueue(T x) override {
            if (isFull()) {
                cout << "Queue Overflow\n";
                return;
            }
            if (front == -1) front = 0;
            arr[++rear] = x;
    }
    
    
    T dequeue() override {
        if(isEmpty()){
            cout << "Queue Underflow\n";
            return T(); // default value
        }
        return arr[front++];
    }
    
    T frontElement() override {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return T();
            }
            return arr[front];
    }
    
    void display() override {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

#endif

