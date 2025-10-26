//
//  sparseMatrix.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 03/06/25.
//

#ifndef sparseMatrix_hpp
#define sparseMatrix_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Element {
public:
    int i;
    int j;
    int x;
};

class Sparse {
private:
    int m;
    int n;
    int num;
    Element *ele;
    
public:
    Sparse(int m, int n, int num);
    ~Sparse();
//    void read();
//    void display();
    Sparse operator+(Sparse &s);
    friend istream& operator>>(istream &is, Sparse &s);
    friend ostream& operator<<(ostream &os, Sparse &s);
};


class Term {
public:
    int Coeff;
    int Exp;
};

class Polynomials {
private:
    int n;
    Term *terms;
    
public:
    Polynomials(int n);
    void create();
    void Display();
    Polynomials add(Polynomials &p);
};

#endif /* sparseMatrix_hpp */
