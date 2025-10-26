//
//  patterns.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 26/12/24.
//

#include <iostream>
using namespace std;

void printPattern(int n){
    char ch = 'A';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout << ch << " ";
        }
        ch = ch + 1;
        cout << endl;
    }
}

void reverseTrianglePattern(int n) {
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

void floydsTrianglePattern(int n) {
    int x = 1;
    for(int i = 1; i <=n; i++){
        for(int j = 0; j < i; j++){
            cout << x << " ";
            x = x+1;
        }
        cout << endl;
    }
}

void invertedTrianglePattern(int n){
    for(int i = 1; i <= n ; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = i; j <= n; j++){
            cout << i;
        }
        
        cout << endl;
    }
}

void pyramidPattern(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        for(int k = i-1; k > 0; k--){
            cout << k;
        }
        cout << endl;
    }
}

void hollowDiamondPattern(int n){
    for(int i = 0; i < n; i++){
        //printing spaces
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        
        cout << "*";
        if(i != 0){
            for(int j = 0; j < 2*i-1; j++){
                cout << " ";
            }
            cout << "*";
        }
        
        
        cout << endl;
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < i+1; j++){
            cout << " ";
        }
        
        cout << "*";
        if(i != n-2){
            for(int j = 0; j < 2*(n-2-i)-1; j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

void butterflyPattern(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout << "*";
        }
        
        
        //print spaces
        for(int k = 0; k < 2*(n-i-1); k++){
            cout << " ";
        }
        
        for(int j = 0; j < i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        
        
        //print spaces
        for(int k = 1; k <= 2*i; k++){
            cout << " ";
        }
        
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        cout << endl;
//        *    *
//        **  **
//        ******
//        ******
//        **  **
//        *    *
    }
}
