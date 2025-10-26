//
//  structsInC.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 11/01/25.
//

#include "structsInC.hpp"
#include <iostream>

using namespace std;



void printArea(const Rectangle& rect) {
    cout << "Area of Rectangle: " << rect.length * rect.breadth << std::endl;
}

void fun(struct Rectangle *p){
    p->length=20;
    cout << "Length "<<p->length<<endl;
    cout << "Breadth "<<p->breadth<<endl;
}

void add(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] <<endl;
    }
}
