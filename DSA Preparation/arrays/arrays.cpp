//
//  arrays.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 24/03/25.
//

#include "arrays.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void dynamicArrayAllocation(){
    int *p = new int[5]{3, 5, 7, 9, 11};
    int *q = new int[10];
    
    for(int i = 0; i < 5; i++){
        q[i] = p[i];
    }
    
    free(p);
    p = q;
    q = NULL;
    for(int i = 0; i < 10; i++){
        cout <<  p[i] << endl;
    }
}

void twoDArrays(){
//    int A[3][4] = {{1,2 ,3,4}, {2,4,6,8},{1,3,5,7}};
    
    int *B[3];
    int **C;
    int i, j;
    
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            cout << C[i][j] <<  " ";
        }
        cout <<  endl;
    }
}

//Array as Abstract Data Type
void Display(struct Array arr){
    int i;
    cout << " Elements are " << endl;
    for(i = 0; i < arr.length; i++){
        cout << arr.A[i] << endl;
    }
}

void append(struct Array *arr, int x){
    if(arr -> length < arr -> size){
        arr -> A[arr -> length++] = x;
    }
}

void Insert(struct Array  *arr, int index, int x){
    if(index >= 0 && index <= arr->length){
        for(int i =arr->length;i >index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr,  int index ){
    int x = 0;
    int i;
    if(index >= 0 && index<arr->length){
        x = arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int linearSearch(struct Array arr, int x){
    for(int i  = 0; i < arr.length; i++){
        if(arr.A[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array arr, int x){
    int l,mid,h;
    l = 0;
    h = arr.length-1;
    while(l <= h){
        mid=  (l+h)/2;
        if(arr.A[mid] == x){
            return mid;
        }else if(arr.A[mid] < x){
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key){
    int mid;
    if(l <= h){
        mid = (l+h)/2;
        if(key == a[mid]){
            return mid;
        }else if(key < a[mid]){
            return RBinSearch(a, l, mid-1, key);
        }else {
            return RBinSearch(a, mid+1, h, key);
        }
    }
    return -1;
}

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr,  int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index]=x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i = 0; i < arr.length; i++){
        if(arr.A[i] > max){
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i = 0; i < arr.length; i++){
        if(arr.A[i] < min){
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int s=0;
    int i;
    for(i =0; i < arr.length; i++){
        s+=arr.A[i];
    }
    return s;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    int *B;
    int i, j;
    
    B = new int[arr->length];
    for(i=arr->length-1,j=0; i>=0; i--,j++){
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->length; i++){
        arr->A[i]=B[i];
    }
}

void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i < j;i++,j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x){
    int i  = arr->length-1;
    if(arr->length==arr->size){
        return;
    }
    while(i>=0&&arr->A[i] > x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int j = arr->length-1;
    int i = 0;
    while(i < j){
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >=0)j--;
        if(i<j)swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array*  Merge(struct Array *arr1, struct Array *arr2){
    int i, j,k;
    i=j=k=0;
    struct Array *arr3 = new Array;
    
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=15;
    
    return arr3;
}

struct Array*  Union(struct Array *arr1, struct Array *arr2){
    int i, j,k;
    i=j=k=0;
    struct Array *arr3 = new Array;
    
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }else if(arr2->A[j] < arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            //include any one element from both array as both elements are same
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    arr3->size=15;
    
    return arr3;
}


struct Array*  Intersection(struct Array *arr1, struct Array *arr2){
    int i, j,k;
    i=j=k=0;
    struct Array *arr3 = new Array;
    
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }else if(arr2->A[j] < arr1->A[i]){
            j++;
        }
        else{
            //include any one element from both array as both elements are same
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=15;
    
    return arr3;
}


struct Array*  Difference(struct Array *arr1, struct Array *arr2){
    int i, j,k;
    i=j=k=0;
    struct Array *arr3 = new Array;
    
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }else if(arr2->A[j] < arr1->A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=15;
    
    return arr3;
}
