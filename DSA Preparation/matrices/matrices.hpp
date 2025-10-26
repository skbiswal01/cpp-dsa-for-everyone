//
//  matrices.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 12/05/25.
//

#ifndef matrices_hpp
#define matrices_hpp

#include <stdio.h>

class Diagonal {
private:
    int* A;
    int  n;

public:
    Diagonal();             // default constructor
    Diagonal(int size);     // parameterized constructor
    ~Diagonal();            // destructor
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    
};

class lowerTriangular {
private:
    int* A;
    int  n;

public:
    lowerTriangular();             // default constructor
    lowerTriangular(int size);     // parameterized constructor
    ~lowerTriangular();            // destructor
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimension();
    
};

#endif /* matrices_hpp */
