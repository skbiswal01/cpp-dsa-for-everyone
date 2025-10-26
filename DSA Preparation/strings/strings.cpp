//
//  strings.cpp
//  DSA Preparation
//
//  Created by Sk Personal on 01/05/25.
//

#include "strings.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void ChangingCase(char A[]){
    int i;
    for(i=0; A[i] != '\0'; i++){
        if(A[i] >= 65 && A[i] <= 90){
            A[i] += 32;
        }else if(A[i] >= 'a' && A[i] <= 122){
            A[i] -= 32;
        }
    }
    cout << A << endl;
}

void countingConsAndVow(char A[]){
    int countVow = 0;
    int countConst = 0;
    for(int i = 0;  A[i] != '\0'; i++){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' ||  A[i] == 'o'||  A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' ||  A[i] == 'O'||  A[i] == 'U'){
            countVow++;
        }else if((A[i] >= 65 && A[i] <= 90 ) || (A[i] >= 97 && A[i] <= 122) ){
            countConst++;
        };
    }
    cout << "number of vowels " << countVow << endl;
    cout << "number of consonents " << countConst << endl;
}

void validateString(char A[]){
    int i;
    for(i = 0;  A[i] !='\0'; i++){
        if(!(A[i] >= 65 && A[i] <= 90 ) && !(A[i] >= 97 && A[i] <= 122) ){
            cout << "Invalid String" << endl;
            break;
        }
    }
    
    if(A[i] == '\0'){
        cout << "valid String" << endl;
    }
    
}

void reverseString(char A[]){
    int i, j;
    for (j = 0; A[j] != '\0'; j++) {
        // just finding the length
    }
    j = j - 1;
    
    for (i = 0; i < j; i++, j--) {
            char temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    
    cout << A << endl;
}

void checkingPalindrome(char A[]){
    int i=0, j = 0;
    for (j = 0; A[j] != '\0'; j++) {
        // just finding the length
    }
    j = j - 1;
    while(i < j){
        if(A[i] != A[j]){
            cout << "not a palindrome" << endl;
            return;
        }
        i++;
        j--;
    }
    
    cout << "It's a palindrome" << endl;
}

void DuplicatesInString(char A[]){
    int hash[26] = {0}; // assuming lowercase a-z only
    for(int i = 0; A[i] != '\0'; i++){
            hash[A[i] - 'a']++;
    }
    
    for(int i = 0;  i <  26; i++){
        if(hash[i] > 1){ // should check for count > 1, not > 0
                char ch = i + 'a'; // convert index back to char
                cout << "found duplicate character: " << ch << endl;
            }
    }
}

void DuplicateCharBitWise(char A[]){
    int bitmask = 0;
        for(int i = 0; A[i] != '\0'; i++) {
            int bit = 1 << (A[i] - 'a');
            if ((bitmask & bit) > 0) {
                cout << "Duplicate character found: " << A[i] << endl;
            } else {
                bitmask |= bit;
            }
        }
}

void Anagram(char A[], char B[]){
    int hash[26] = {0};
    for(int i = 0; A[i] != '\0'; i++){
            hash[A[i] - 'a']++;
    }
    for(int i = 0; B[i] != '\0'; i++){
            hash[B[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(hash[i] != 0){
            cout << "Not an Anagram" << endl;
            return;
        }
    }
    cout << "its an anagram" << endl;
    
}

void Permutation(char A[], int l, int r){
    if(l == r){
        cout << A << endl;
        return;
    }
    for(int i = l; i <=  r; i++){
        swap( A[l], A[i] );
        Permutation(A, l+1, r);
        swap(A[l],  A[i]);
    }
}


//bool isBalanced(const string &exp){
//    Stack <char> st;
//
//    for(char ch:  exp){
//        if (ch == '(' || ch == '[' || ch == '{') {
//            st.push(ch);
//        }else if (ch == ')' || ch == ']' || ch == '}') {
//            if(st.isEmpty()) return false;
//
//            char topChar = st.pop();
//            if ((ch == ')' && topChar != '(') ||
//                            (ch == ']' && topChar != '[') ||
//                            (ch == '}' && topChar != '{'))
//                            return false;
//        }
//    }
//
//    return st.isEmpty();
//}
