//
//  heap.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 11/10/25.
//

#include "heap.hpp"
# include <iostream>
#include <stdexcept>

using namespace std;

void swap_int(int &x, int &y){
    int t = x;
    x = y;
    y = t;
};

void Insert(std::vector<int> &A, int n){
    int i = n;
    int temp = A[i];
    
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    };
    A[i] = temp;
};

int Delete(std::vector<int> &A, int n){
    if(n <= 0 || n >= (int)A.size()) throw std::runtime_error("Delete: invalid n");
    int val = A[1];
    A[1] = A[n];
    A[n] = val;
    
    int i = 1;
    int j = i * 2;
    
    while(j <= n - 1){
        if(j < n - 1 && A[j + 1] > A[j]) j = j + 1;
        if(A[i] < A[j]){
            swap_int(A[i], A[j]);
            i = j;
            j = 2 * j;
        }else {
            break;
        }
    }
    return val;
};


void printVec(const std::vector<int> &v) {
    for(size_t i = 1; i < v.size(); ++i) std::cout << v[i] << ' ';
    std::cout << '\n';
};


void siftDownArray(std::vector<int> &A, int n, int i){
    while(true){
        int left = 2 * i;
        int right = 2 * i + 1;
        
        int largest = i ;
        
        if(left <= n && A[left] > A[largest]){
            largest = left;
        }
        if(right <= n && A[right] > A[largest]){
            largest = right;
        }
        
        if (largest == i){
            break;
        }
        
        swap_int(A[i], A[largest]);
        i = largest;
    }
};

void heapify_Array(std::vector<int> &A){
    int n = (int)A.size() - 1; // since A is 1-indexed
    for(int i = n/2; i >= 1; --i){
        siftDownArray(A, n, i);
    }

}
