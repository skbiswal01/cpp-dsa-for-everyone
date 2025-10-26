//
//  genericClass.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 16/02/25.
//

#ifndef genericClass_hpp
#define genericClass_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
class airthmetic {
private:
    T a;
    T b;
    
public:
    airthmetic(T a, T b);
    T add();
    T sub();
};

template <typename T>
airthmetic<T>::airthmetic(T val1, T val2){
    a = val1;
    b = val2;
}

template <typename T>
T airthmetic<T>::add() {
    T c;
    c = a + b;
    return c;
};


template <typename T>
T airthmetic<T>::sub(){
    T c;
    c = a - b;
    return c;
}


#endif /* genericClass_hpp */
