//
//  recursion.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 19/02/25.
//

#ifndef recursion_hpp
#define recursion_hpp

int recursivefun(int n);
void treeRecursion(int n);
void indirectRecursionA(int n);
void indirectRecursionB(int n);
int nestedRecursion(int n);
int exponential(int m, int n);
int sumOfNaturals(int n);
int factorial(int n);
double taylorSeries(int e, int x);
double optimisedTaylorSeries(int e, int x);
double taylorSeriesIterative(int e, int x);
int fib(int n);
int fibRecursiveApproach(int n);

extern int f[10]; // ✅ Declares f[] from main.cpp
int memoizationfib(int n);
int combination(int n,  int r);
int ncr(int n, int r);
void toh(int n,  int A, int B, int C);

#endif /* recursion_hpp */
