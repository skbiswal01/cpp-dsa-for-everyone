//
//  StackQueue.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 19/08/25.
//

#ifndef StackQueue_hpp
#define StackQueue_hpp

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class stackQueue {
private:
    stack<T> e_stk;  // enqueue stack
    stack<T> d_stk;  // dequeue stack
    
public:
            stackQueue() {};
            ~stackQueue() {};
    
            void enqueue(T x) {
                    e_stk.push(x);
            }
    
            T dequeue() {
                if(d_stk.empty()){
                    if(e_stk.empty()){
                        throw runtime_error("Queue Underflow");
                    }else {
                        while(!e_stk.empty()){
                                d_stk.push(e_stk.top());
                                e_stk.pop();
                        }
                    }
                }
                T x = d_stk.top();
                d_stk.pop();
                return x;
            }
    
            bool empty() const {
                    return e_stk.empty() && d_stk.empty();
            }
    
            T front() {
                    if (d_stk.empty()) {
                        if (e_stk.empty()) {
                            throw runtime_error("Queue is empty");
                        } else {
                            while (!e_stk.empty()) {
                                d_stk.push(e_stk.top());
                                e_stk.pop();
                            }
                        }
                    }
                    return d_stk.top();
                }
};


#endif /* StackQueue_hpp */
