//
//  matrices.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 12/05/25.
//

#include "matrices.hpp"
#include <iostream>

using namespace std;

Diagonal::Diagonal() {
    n = 2;
    A = new int[n]{0};  // initialize with zeros
}

Diagonal::Diagonal(int n) {
    this->n = n;
    A = new int[n]{0};
}

Diagonal::~Diagonal() {
    delete[] A;
}

void Diagonal::Set(int i, int j, int x) {
    if (i == j) {
        A[i - 1] = x;
    }
}

int Diagonal::Get(int i, int j) {
    if (i == j ) {
        return A[i - 1];
    }
    return 0;
}

void Diagonal::Display(){
    for(int i=0; i <n; i++){
        for(int j=0; j < n; j++){
            if(i==j){
                cout << A[i] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

lowerTriangular::lowerTriangular() {
    n = 2;
    A = new int[n*(n+1)/2];
}

lowerTriangular::lowerTriangular(int n) {
    this->n = n;
    A = new int[n*(n+1)/2];
}

lowerTriangular::~lowerTriangular() {
    delete[] A;
}

void lowerTriangular::Set(int i, int j, int x) {
    if (i >= j) {
        A[i *(i-1)/2+j-1] = x;
    }
}

int lowerTriangular::Get(int i, int j) {
    if (i == j ) {
        return A[i *(i-1)/2+j-1];
    }
    return 0;
}

void lowerTriangular::Display(){
    for(int i=1; i <=n; i++){
        for(int j=1; j <= n; j++){
            if(i>=j){
                cout << A[i *(i-1)/2+j-1] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int lowerTriangular::getDimension(){
    return this->n;
}
