/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Implementation (according to "Introduction to algorithm and data structure"
// by T.H. Cormen) of insertion_sort algorithm.
// It takes as input an array of void pointers, the size of the array, and a
// pointer fo a compare function.
// It orders the given array using the insertion_sort algorithm.
void insertion_sort(void ** array, int size, int (*compare)(void*,void*));

// Implementation (according to "Introduction to algorithm and data structure"
// by T.H. Cormen) of merge_sort algorithm.
// It takes as input an array of void pointers, the left index of the array,
// the right index of the array, and a pointer to a compare function.
// It orders the given array using the merge_sort algorithm.
void merge_sort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*));

// Implementation (according to "Introduction to algorithm and data structure"
// by T.H. Cormen) of merge function, used in merge_sort algorithm.
// It takes as input an array of void pointers, the left index of the array,
// the center index of the array, the right index of the array,
// and a pointer fo a compare function.
// Used in merge_sort function defined previously.
void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*));

// It takes as input an array to test made of void pointers,
// an array of void pointers to check if contains at least one element that
// is the sum of two others elements in array_to_test, the size of
// array_to_test, the size of array_of_sums, a pointer to a 
// compare function and a pointer to a function called sums_support, 
// which sums two numbers pointed by two void pointers (used for compare purpose).
int sums_in_array(void ** array_to_test, void ** array_of_sums, int size_to_test, int size_of_sums,
        int (*compare)(void*,void*), long long * (sums_support)(void*, void*));

// It takes as input two void pointers.
// It returns the sum of the two pointed values.
// Used in sums_in_array() function.
long long * sums_support(void* r1_p, void* r2_p);

#endif /* SORTS_H_ */
