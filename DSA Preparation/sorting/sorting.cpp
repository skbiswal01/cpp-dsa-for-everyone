//
//  sorting.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 13/10/25.
//

#include "sorting.hpp"
#include <iostream>
#include <algorithm>
#include "linkedlist.hpp"

using namespace std;

// Constructor initializes counters
Sorter::Sorter() : comparisons(0), swaps(0) {}

void Sorter::resetCounters() {
    comparisons = 0;
    swaps = 0;
}

// Print current statistics
void Sorter::printStats() const {
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
}

//print original array
void Sorter::printOriginalArray(vector<int>& arr){
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}

//print Sorted Array
void Sorter::printSortedArray(vector<int>& arr){
    cout << "Sorted Array:   ";
        for (int num : arr) cout << num << " ";
        cout << endl;
}


void Sorter::bubbleSort(vector<int>& arr) {
    resetCounters();
    size_t n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }

        // Optimization: stop if already sorted
        if (!swapped) break;
    }
}


void Sorter::insertionSort(vector<int>& A){
    resetCounters();
    size_t n = A.size();
    
    for(int i = 1; i < n; i++){
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j] > x){
                    A[j+1] = A[j];
                    j--;
                }
                A[j+1] = x;
    }
}


void Sorter::selectionSort(vector<int> &A){
    resetCounters();
    size_t n = A.size();
    
    for(int i = 0; i < n-1; i++){
        int j;
        int k;
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i], A[k]);
    }
}


int Sorter::partition(vector<int>& A, int low, int high){
    int pivot = A[low];
    int i = low - 1;
    int j = high + 1;
    
    while(true){
        do {
            i++;
            
        }while(A[i] < pivot);
        
        do {
            j--;
        }while(A[j] > pivot);
        
        if(i >= j){
            return j;
        }
        
        swap(A[i], A[j]);
    }
}

void Sorter::quickSort(vector<int> &A,  int low, int high){
    if(low < high){
        int p = partition(A,  low,  high);
        quickSort(A, low, p);
        quickSort(A, p + 1, high);
        
    }
}

void Sorter::quickSort(vector<int>& A){
    resetCounters();
    int n = static_cast<int>(A.size());
    if(!A.empty()){
        quickSort(A, 0, n-1);
    }
}


void Sorter::merge(vector<int>&A, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}


void Sorter::iterativeMergeSort(vector<int> & A, int n){
    int p, l, h, mid,i;
    for(p = 2; p <=n; p = p * 2){
        for(i = 0; i+p-1 < n; i=i+p){
            l = i;
            h= i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, h);
        }
    }
    if(p/2 < n){
        merge(A, 0, p/2, n-1);
    }
}


void Sorter::recursiveMergeSort(vector<int>& A, int l,  int h){
    if(l < h){
        int mid = (l + h)/2;
        recursiveMergeSort(A,  l,  mid);
        recursiveMergeSort(A,  mid + 1,  h);
        merge(A, l, mid, h);
    }
}

void Sorter::mergeSort(vector<int>& A){
    resetCounters();
    int n = static_cast<int>(A.size());
//    iterativeMergeSort(A,  n);
    recursiveMergeSort(A,  0,  n-1);
}



void Sorter::countingSort(vector<int>& A) {
    resetCounters();
    int n = static_cast<int>(A.size());
    if (n == 0) return;

    int maxVal = *std::max_element(A.begin(), A.end());

    std::vector<int> c(maxVal + 1, 0);

    // Step 1: Count frequency
    for (int i = 0; i < n; i++) {
        c[A[i]]++;
    }

    
    int i =0, j = 0;
    while(i < maxVal+1){
        if(c[i] > 0){
            A[j++] = i;
            c[i]--;
        }else{
            i++;
        }
    }
}


void Sorter::bucketSort(std::vector<int> &A){
    resetCounters();
    int n = static_cast<int>(A.size());
    if (n == 0) return;

    // Determine the maximum value to size buckets
    int maxVal = *std::max_element(A.begin(), A.end());

    // Allocate array of bucket heads (each bucket is a linked list)
    Node **Bins = new Node*[maxVal + 1];

    // Initialize all bucket heads to nullptr
    for (int i = 0; i <= maxVal; i++) {
        Bins[i] = nullptr;
    }

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int key = A[i];
        // Push-front insert into bucket list Bins[key]
        Node* node = new Node;        
        node->data = key;             // assumes Node has an int `data` field
        node->next = Bins[key];       // assumes Node has a `next` pointer
        Bins[key] = node;
        // Optionally track operations: this is not a comparison-based sort
        swaps++; // count as a placement operation
    }

    // Collect elements back into A in order
    int idx = 0;
    for (int b = 0; b <= maxVal; b++) {
        Node* p = Bins[b];
        while (p != nullptr) {
            A[idx++] = p->data;
            Node* tmp = p;
            p = p->next;
            delete tmp; // free node
        }
    }

    // Free bucket array
    delete [] Bins;
}

void Sorter::countingSortByDigit(std::vector<int> &arr, int exp){
    int n = (int)arr.size();
    if (n <= 1) return;
    
    Node** bins = new Node*[10];
    for (int i = 0; i < 10; ++i) bins[i] = nullptr;
    
    auto getDigit = [&](int value)->int {
        return (value / exp) % 10;
    };
    
    auto InsertAtEnd = [&](int value, int binIdx) {
        Node* node = new Node(value);
        if (bins[binIdx] == nullptr) {
            bins[binIdx] = node;
        } else {
            Node* p = bins[binIdx];
            while (p->next != nullptr) p = p->next;
            p->next = node;
        }
    };
    
    // Distribute elements into bins based on current digit (left-to-right to preserve original order)
    for (int i = 0; i < n; ++i) {
        int d = getDigit(arr[i]);
        InsertAtEnd(arr[i], d);
    }

    // Collect back into arr from bins 0..9 (this preserves increasing order by digit)
    int idx = 0;
    for (int b = 0; b < 10; ++b) {
        while (bins[b] != nullptr) {
            Node* head = bins[b];
            arr[idx++] = head->data;
            bins[b] = head->next;
            delete head;
        }
    }

    // Free bins array
    delete [] bins;
}

void Sorter::radixSort(vector<int> &arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}


void Sorter::shellSort(std::vector<int> &arr){
    int n = (int)arr.size();
    for(int gap = n/2; gap >= 1; gap/=2 ){
        for(int j = gap; j < n; j++){
            int temp = arr[j];
            int i = j-gap;
            while(i >= 0 && arr[i] > temp){
                arr[i+gap] = arr[i];
                i = i  - gap;
            }
            arr[i+gap] = temp;
        }
    }
}

