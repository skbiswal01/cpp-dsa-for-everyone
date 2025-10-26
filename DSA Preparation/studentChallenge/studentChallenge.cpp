//
//  studentChallenge.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 22/04/25.
//

#include "studentChallenge.hpp"
#include <iostream>

using namespace std;

//int missingElement(int arr[], int n) {
//    int maxElement = arr[0];
//    int sum1 = 0;
//    
//    for (int i = 0; i < n; i++) {
//        sum1 += arr[i];
//        if (arr[i] > maxElement) {
//            maxElement = arr[i];
//        }
//    }
//    
//    int expectedSum = (maxElement * (maxElement + 1)) / 2;
//    int missingElement = expectedSum - sum1;
//    
//    return missingElement;
//}

//optimised approach using bitwise operator
int missingElement(int arr[], int n) {
    int xor1 = 0; // XOR of all elements from 1 to n+1
    int xor2 = 0; // XOR of all elements in the array

    for (int i = 1; i <= n + 1; i++) {
        xor1 = xor1 ^ i;
    }
    
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ arr[i];
    }
    
    return xor1 ^ xor2; // missing number
}

//multiple missing element
void multipleMissingElement(int* arr, int n, int* missing, int& count){
    int diff = arr[0] - 0;
    missing = new int[100];
    count = 0;
    for(int i= 0; i < n; i++){
        while(arr[i]-i > diff){
            missing[count++] = i + diff;
            diff++;
        }
    }
}

//multiple missing elements second method
void multipleMissingElementHash(int arr[], int n){
    int low = arr[0];
    int high = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < low){
            low = arr[i];
        }if(arr[i] > high){
            high=arr[i];
        }
    }
    
    int size = high + 1;
    int* hash = new int[size]();
    for(int i = 0; i < n; i++){
        hash[arr[i]]=1;
    }
    
    for (int i = low; i <= high; i++) {
            if (hash[i] == 0) {
                cout << "Missing: " << i << endl;
            }
        }

        delete[] hash;
}

void duplicatesInSortedArray(int arr[], int n){
    int duplicate = -1;
    for(int i = 0; i < n-1; i++){
        if(arr[i] == arr[i+1] && duplicate != arr[i]){
            duplicate = arr[i];
            
            cout << "duplicate found: " << arr[i] << endl;
            i++;
        }
    }
}

//using hash find duplicatesInSortedArrays
void duplicatesInSortedArrayUsingHash(int arr[], int n){
    int low = arr[0];
    int high = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < low){
            low = arr[i];
        }else if(arr[i] > high){
            high=arr[i];
        }
    }
    
    int size = high + 1;
    int* hash = new int[size](0);
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for (int i = low; i <= high; i++) {
            if (hash[i]  >  1) {
                cout << "duplicate found: " << i << endl;
            }
    }

        delete[] hash;
    
}

void pairSum(int arr[], int n, int k){
    int hash[101] = {0};  // Assuming the numbers are within the range 0 to 100 (inclusive)

        for (int i = 0; i < n; i++) {
            int complement = k - arr[i];

            // Check if the complement is already in the hash table
            if (hash[complement] > 0) {
                cout << "found pair: " << arr[i] << " " << complement << endl;
                hash[complement]--;  // Decrease the count of complement to avoid pairing it again
            } else {
                hash[arr[i]]++;  // Increase the count for the current element
            }
        }
}

void PairSumSortedArray(int arr[], int n, int k){
    int i = 0;
    int j = n-1;
    while(i < j){
        if(arr[i] + arr[j] == k){
            cout << "found pair: "<< arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }else if(arr[i] + arr[j] > k){
            j--;
        }else{
            i++;
        }
    }
}

