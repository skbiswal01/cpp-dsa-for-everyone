//
//  structsInC.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 11/01/25.
//

#ifndef structsInC_hpp
#define structsInC_hpp

struct Rectangle {
    int length;
    int breadth;
};

// Function declaration to use the struct
void printArea(const Rectangle& rect);
void fun(struct Rectangle *p);
void add(int A[], int n);

#endif /* structsInC_hpp */
