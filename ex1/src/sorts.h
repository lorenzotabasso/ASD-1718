/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdio.h>

// Implementation (according to "Introduction to algorithm and data structure"
// by T.H. Cormen) of insertion_sort algorithm.
// It takes as input an array of void pointers, the size of the array, and a
// pointer fo a compare function.
// It orders the given array using the insertion_sort algorithm.
void insertion_sort(void ** array, int size, int (*compare)(void*,void*));

// Implementation of merge_sort algorithm.
// It takes as input an array of void pointers, the left index of the array,
// the right index of the array, and a pointer to a compare function.
// It orders the given array using the merge_sort algorithm.
void merge_sort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*));

// Implementation of merge function, used in merge_sort algorithm.
// It takes as input an array of void pointers, the left index of the array,
// the center index of the array, the right index of the array,
// and a pointer fo a compare function.
// Used in merge_sort function defined previously.
void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*));

#endif /* SORTS_H */
