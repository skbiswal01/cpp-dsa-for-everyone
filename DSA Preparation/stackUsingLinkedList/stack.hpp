#pragma once
#include <iostream>
using namespace std;

template <typename T>
class stackNode {
public:
    T data;
    stackNode<T>* Next;  // FIX: add <T> here
    stackNode(T val) : data(val), Next(nullptr) {}
};

template <typename T>
class Stack {
private:
    stackNode<T>* top;
public:
    Stack() : top(nullptr) {}
    ~Stack();
    void push(T value);
    T pop();
    T peek(int pos);
    bool isEmpty() const;
    void display() const;
};

// Implementation

template <typename T>
Stack<T>::~Stack() {
    while (top != nullptr) {
        stackNode<T>* temp = top;
        top = top->Next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::push(T value) {
    stackNode<T>* newNode = new stackNode<T>(value);
    newNode->Next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return T();
    }
    stackNode<T>* temp = top;
    T value = top->data;
    top = top->Next;
    delete temp;
    return value;
}

template <typename T>
T Stack<T>::peek(int pos) {
    stackNode<T>* p = top;
    for (int i = 0; p != nullptr && i < pos - 1; i++) {
        p = p->Next;
    }
    return p ? p->data : T();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::display() const {
    stackNode<T>* p = top;
    while (p != nullptr) {
        cout << p->data << " | " << flush;
        p = p->Next;
    }
    cout << endl;
}
