//
//  heap.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 11/10/25.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>

#include <vector>

// Simple swap (no <algorithm>)
void swap_int(int &x, int &y);

// Insert: insert A[n] into heap stored at A[1..n-1]
void Insert(std::vector<int> &A, int n);

// Delete: remove root (max) from heap A[1..n] and place it at A[n]
// After call, heap portion is A[1..n-1]. Returns removed max.
int Delete(std::vector<int> &A, int n);

// siftDown on plain array (1-indexed) for heapify usage
void siftDownArray(std::vector<int> &A, int n, int i);

// heapify_array: build max-heap in O(n) on A[1..n] (A[0] unused)
void heapify_Array(std::vector<int> &A);

void printVec(const std::vector<int> &v);


#endif /* heap_hpp */
