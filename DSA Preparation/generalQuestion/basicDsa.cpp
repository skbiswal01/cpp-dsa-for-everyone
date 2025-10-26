//
//  basicDsa.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 28/12/24.
//

#include "basicDsa.hpp"
#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

void sumOfDigits(int n) {
    int sum = 0;
    for(int i = n; i > 0; i = i/10){
        sum += i % 10;
    }
    cout << sum << endl;
 }

// check if a number is a prime or not
//bool checkPrime(int n) {
//    // Handle special cases
//    if (n <= 1) return false; // 0 and 1 are not prime
//    if (n == 2) return true;  // 2 is the only even prime number
//    if (n % 2 == 0) return false; // Exclude other even numbers
//
//    // Check odd divisors up to the square root of n
//    for (int i = 3; i * i <= n; i += 2) {
//        if (n % i == 0) {
//            return false; // n is divisible by i, so it's not prime
//        }
//    }
//    return true; // n is prime
//}
bool checkPrime(int n) {
    if (n <= 1) return false;            // Handle numbers <= 1
    if (n == 2 || n == 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Exclude multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false; // Check divisors of form 6k ± 1
    }
    return true;
}

// print all prime number upto n
//void printAllPrimes(int n){
//    for(int i = 1; i <= n; i++){
//        if (checkPrime(i)){
//            cout << i << " ";
//        }
//    }
//    cout << endl;
//}

//efficient Approach for solving printing all primess problem
void printAllPrimes(int n) {
    // Create a boolean array to mark prime numbers
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
    
    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    
    // Print all primes
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
}
  

// print nth fibonacci
void printFibonacci(int n){
    int a  = 0;
    int b = 1, next = 0;
    for(int i = 2; i < n; i++){
        next = a + b;
        a = b;
        b = next;
    }
    
    cout << next << endl;
}

// convert decimal to binary


int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}


// Function to check if opening bracket matches closing one
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


string infixToPostfix(string infix){
    stack<char> st;
    string postfix = "";
    
    for(char c: infix){
        if(isalnum(c)){
            postfix += c;
        }else if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }else if(c == ')' || c == '}' || c == ']'){
            while(!st.empty() && !isMatching(st.top(), c)) {
                    postfix += st.top();
                    st.pop();
                }
            if(!st.empty()) st.pop();
        }else if(isOperator(c)) {
            while(!st.empty() && isOperator(st.top()) &&
                  precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
        
    }
    
    while(!st.empty()) {
            postfix += st.top();
            st.pop();
        }
    
    return postfix;
}
