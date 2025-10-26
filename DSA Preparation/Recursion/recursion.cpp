//
//  recurssion.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 19/02/25.
//

#include <stdio.h>
#include <iostream>
#include "recursion.hpp"

using namespace std;

int recursivefun(int n){
    static int x = 0;
    if(n > 0){
        x++;
        return recursivefun(n-1) + x;
    }
    return 0;
}

void treeRecursion(int n){
    if(n > 0){
        cout << n;
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

void indirectRecursionB(int n);


void indirectRecursionA(int n){
    if(n > 0){
        printf("%d\n", n);
        indirectRecursionB(n-1);
    }
}

void indirectRecursionB(int n){
    if(n > 0){
        printf("%d\n", n);
        indirectRecursionA(n/2);
    }
}

int nestedRecursion(int n){
    if(n > 100){
        return n - 10;
    }else{
        return nestedRecursion(nestedRecursion(n + 11));
    }
};

int sumOfNaturals(int n){
    if ( n > 0){
        return sumOfNaturals(n-1)+n;
    }
    return 0;
};

int factorial(int n){
    if ( n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
};

int exponential(int m, int n){
    if( n == 0){
        return 1;
    }
    if( n % 2 == 0){
        return exponential(m * m , n/2);
    }else {
        return m * exponential(m * m, (n-1)/2);
    }
};

double taylorSeries(int x, int n){
    static double p=1, f=1;
    double r;
    if(n==0){
        return 1;
    }else {
        r = taylorSeries(x, n-1);
        p=p*x;
        f=f*n;
        return r + p/f;
    }
};

double optimisedTaylorSeries(int x, int n){
    static double s;
    if( n == 0){
        return s;
    }
    s = 1 + x*s/n;
    return optimisedTaylorSeries(x, n-1);
}


double taylorSeriesIterative(int x, int n){
    double s = 1;
    for(int i = 1; i <= n; i++){
        s = 1 + s*x/i;
    }
    return s;
};

int fib(int n){
    int t0=0, t1=1, s=0;
    
    if ( n <= 1){
        return n;
    }
    
    for(int i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    
    return s;
};


int fibRecursiveApproach(int n){
    if(n <= 1){
        return n;
    }
    
    return fibRecursiveApproach(n-1) + fibRecursiveApproach(n-2);
}


int memoizationfib(int n) {
    
    if(n <= 1) {
        f[n] =n;
        return n;
    }else {
        if (f[n - 1] == -1) {
                f[n - 1] = memoizationfib(n - 1);
            }
            if (f[n - 2] == -1) {
                f[n - 2] = memoizationfib(n - 2);
            }

            return f[n] = f[n - 1] + f[n - 2];
        
    }
    
}

int combination(int n , int r){
    int num = factorial(n);
    int den = factorial(r) * factorial(n-r);
    return num/den;
}

int ncr(int n, int r){
    if(r == 0 || n == r){
        return 1;
    }
    return ncr(n-1, r-1) + ncr(n-1,r);
}

void toh(int n,  int A, int B, int C){
    if(n > 0) {
        toh(n-1,  A, C, B);
        cout << "Moved from tower " << A << " to " << C << endl;
        toh(n-1,  B,  A,  C);
    }
};
