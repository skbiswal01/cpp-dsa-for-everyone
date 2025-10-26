//
//  strings.hpp
//  DSA Preparation
//
//  Created by Sk Personal on 01/05/25.
//

#ifndef strings_hpp
#define strings_hpp

#include <stdio.h>

// String manipulation functions
void changingCase(char A[]);           // Changes case of all characters
void countingConsAndVow(char A[]);     // Counts vowels and consonants
void validateString(char A[]);         // Validates if string contains only alphabets
void reverseString(char A[]);          // Reverses the string
void checkingPalindrome(char A[]);     // Checks if string is palindrome
void duplicatesInString(char A[]);     // Finds duplicate characters using hash table
void duplicateCharBitWise(char A[]);   // Finds duplicates using bitwise operations
void anagram(char A[], char B[]);      // Checks if two strings are anagrams
void permutation(char A[], int l, int r); // Generates all permutations

#endif /* strings_hpp */
