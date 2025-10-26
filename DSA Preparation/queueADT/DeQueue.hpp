//
//  DeQueue.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 19/08/25.
//

#ifndef DeQueue_hpp
#define DeQueue_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
class Deque {
private:
    int front, rear, size;
    T* arr;
    
public:
    Deque(int s) {
            size = s;
            front = rear = -1;
            arr = new T[size];
        }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
            return ( (front == 0 && rear == size-1) || (front == (rear+1) % size) );
    }
    
    void insertFront(T x) {
            if (isFull()) {
                cout << "Deque Overflow!\n";
                return;
            }
            if (isEmpty()) {
                front = rear = 0;
            } else {
                front = (front - 1 + size) % size;
            }
            arr[front] = x;
        }
    
    void insertRear(T x){
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
    }
    
    T deleteFront() {
            if (isEmpty()) {
                cout << "Deque Underflow!\n";
                return -1;
            }
            T x = arr[front];
            if (front == rear) {
                front = rear = -1; // empty now
            } else {
                front = (front + 1) % size;
            }
            return x;
        }
    
    
    T deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow!\n";
            return -1;
        }
        T x = arr[rear];
        if (front == rear) {
            front = rear = -1; // empty now
        } else {
            rear = (rear - 1 + size) % size;
        }
        return x;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
        
    }
    
    ~Deque() {
            delete[] arr;
        }
};


#endif /* DeQueue_hpp */
