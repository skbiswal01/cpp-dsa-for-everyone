//
//  sorting.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 13/10/25.
//

#ifndef sorting_hpp
#define sorting_hpp

#include <stdio.h>
#include <vector>
#include <functional>

class Sorter  {
private:
    long long comparisons;   // Count how many element comparisons done
    long long swaps;          // Count how many swaps (for analysis)
    
public:
    Sorter();
    void resetCounters();
    void printStats() const;
    void printOriginalArray(std::vector<int>& arr);
    void printSortedArray(std::vector<int>& arr);
    void bubbleSort(std::vector<int>& arr);
    void insertionSort(std::vector<int>& arr);
    void selectionSort(std::vector<int>& arr);
    void merge(std::vector<int>& A, int low, int mid, int high);
    void recursiveMergeSort(std::vector<int>& A, int l, int h);
    void iterativeMergeSort(std::vector<int>& A, int n);
    void mergeSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& A, int low, int high);
    int partition(std::vector<int>& A, int low, int high);
    void heapSort(std::vector<int>& arr);
    void shellSort(std::vector<int>& arr);
    void countingSort(std::vector<int>& arr);
    void bucketSort(std::vector<int>& arr);
    void countingSortByDigit(std::vector<int>& arr, int exp);
    void radixSort(std::vector<int>& arr);
};


#endif /* sorting_hpp */

/**
 
 // if calling main function include below
 vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
 Sorter s;
 
 cout << "Sorting using Bubble Sort: "  << endl;
 s.printOriginalArray(arr);
 s.bubbleSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Insertion Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.insertionSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Selection Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.selectionSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Quick Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.selectionSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Merge Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.mergeSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Count Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.countingSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 cout << "Sorting using Bin/Bucket Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.bucketSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 
 cout << "Sorting using radix Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.radixSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 
 
 cout << "Sorting using shell Sort: " << endl;
 arr = {5, 3, 8, 4, 2, 7, 1, 10};
 s.printOriginalArray(arr);
 s.radixSort(arr);
 s.printSortedArray(arr);
 cout <<  endl;
 */
