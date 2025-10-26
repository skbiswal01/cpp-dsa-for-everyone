//
//  arrays.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 24/03/25.
//

#ifndef arrays_hpp
#define arrays_hpp

void dynamicArrayAllocation();
void twoDArrays();
struct Array {
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr);
void append(struct Array *arr, int x);
void Insert(struct Array  *arr, int index, int x);
int Delete(struct Array  *arr, int index);
int linearSearch(struct Array arr, int x);
int binarySearch(struct Array arr, int x);
int RBinSearch(int a[], int l, int h, int key);
int Get(struct Array arr, int index);
void Set(struct Array *arr,  int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void Reverse(struct Array *arr);
void Reverse2(struct Array *arr);
void InsertSort(struct Array *arr, int x);
int isSorted(struct Array arr);
void Rearrange(struct Array *arr);
struct Array*  Merge(struct Array *arr1, struct Array *arr2);
struct Array*  Union(struct Array *arr1, struct Array *arr2);
struct Array*  Intersection(struct Array *arr1, struct Array *arr2);
struct Array*  Difference(struct Array *arr1, struct Array *arr2);


#endif /* arrays_hpp */
