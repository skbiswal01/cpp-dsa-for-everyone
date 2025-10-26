//
//  sparseMatrix.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 03/06/25.
//

#include "sparseMatrix.hpp"
#include <iostream>

using namespace std;

Sparse::Sparse(int m, int n, int num){
    this->m=m;
    this->n=n;
    this->num=num;
    ele = new Element[this->num];
}

Sparse::~Sparse(){
    delete [] ele;
}

//void Sparse::read(){
//    cout << "Enter non-zero elements";
//    for(int i = 0; i < num; i++){
//        cin >> ele[i].i>>ele[i].j>>ele[i].x;
//    }
//}

istream& operator>>(istream &is, Sparse &s){
    cout << "Enter non-zero elements";
    for(int i = 0; i < s.num; i++){
        is>> s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    }
    return is;
}

//void Sparse::display(){
//    int k =0;
//    for(int  i =0; i < m; i++){
//        for(int j=0; j < n; j++){
//            if(ele[k].i==i && ele[k].j==j){
//                cout<<ele[k++].x<<" ";
//            }else{
//                cout << "0 ";
//            }
//        }
//        cout << endl;
//    }
//}

ostream& operator<<(ostream &os, Sparse &s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j)
                os << s.ele[k++].x << " ";
            else
                os << "0 ";
        }
        os << endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &s) {
    int i, j, k;

    if (m != s.m || n != s.n) {
        // If dimensions don't match, return an empty sparse matrix (or handle error properly)
        cout << "Matrix dimensions do not match." << endl;
        return Sparse(0, 0, 0);
    }

    Sparse result(m, n, num + s.num);  // Max possible non-zero elements: num + s.num

    i = j = k = 0;

    // Merge logic like merge step in merge sort
    while (i < num && j < s.num) {
        // Compare row index
        if (ele[i].i < s.ele[j].i) {
            result.ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i) {
            result.ele[k++] = s.ele[j++];
        }
        else {  // Row indices are equal, compare column
            if (ele[i].j < s.ele[j].j) {
                result.ele[k++] = ele[i++];
            }
            else if (ele[i].j > s.ele[j].j) {
                result.ele[k++] = s.ele[j++];
            }
            else {
                // Same row and column: add values
                result.ele[k] = ele[i];
                result.ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }

    // Copy remaining elements
    for (; i < num; i++) result.ele[k++] = ele[i];
    for (; j < s.num; j++) result.ele[k++] = s.ele[j];

    result.num = k;  // Update number of non-zero elements
    return result;
}

Polynomials::Polynomials(int n){
    this->n=n;
    terms = new Term[this->n];
}

void Polynomials::create(){
    cout << "Number of terms: ";
    cin >> n;

    terms = new Term[n]; // allocate memory based on new n

        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
            cin >> terms[i].Coeff >> terms[i].Exp;
        }
}

void Polynomials::Display(){
    for(int i = 0; i < n; i++){
            cout << "coeff of polynomial is: " << terms[i].Coeff << endl;
            cout << "Exp of polynomial is: " << terms[i].Exp << endl;
    }
}

Polynomials Polynomials::add(Polynomials &p) {
    Polynomials sum(n + p.n);  // Allocate max possible terms
    int i = 0, j = 0, k = 0;
    
    cout << terms[i].Coeff << endl;
    cout << p.terms[i].Coeff << endl;

    while (i < n && j < p.n) {
        if (terms[i].Exp > p.terms[j].Exp) {
            sum.terms[k++] = terms[i++];
        } else if (terms[i].Exp < p.terms[j].Exp) {
            sum.terms[k++] = p.terms[j++];
        } else {
            sum.terms[k].Exp = terms[i].Exp;
            sum.terms[k++].Coeff = terms[i++].Coeff + p.terms[j++].Coeff;
        }
    }

    for(;i<n;i++)sum.terms[k++]=p.terms[i];
    for(;j<p.n;j++)sum.terms[k++]=p.terms[j];

    sum.n = k; // update actual number of terms in result
    return sum;
}

