/*
 * Author: Tabasso, Malgaroli
 *
 */

#include "generic_array.h"

#ifndef SORTS_H
#define SORTS_H

#endif //SORTS_H

// COMPARE FUNCTIONS ---------------------------------------------------------------------------------------------------

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_insertionsort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_mergesort(void* r1_p,void* r2_p);

// It takes as input three void pointers.
// It returns 1 iff the first pointed value is less than
// the second pointed value summed with the third pointed value(0 otherwise)
int compare_sums(void* r1_p, void* r2_p);

long long * sums_support(void* r1_p, void* r2_p);

// It takes as input two pointers to struct record.
// It returns 1 iff the integer field of the first record is less than
// the integer field of the second one (0 otherwise)
int compare_record_int_field(void* r1_p,void* r2_p);

// SORTING FUNCTIONS ---------------------------------------------------------------------------------------------------

void insertionSort(GenericArray *array, long long size, int (*compare)(void*,void*));
void mergeSort(GenericArray *array, int leftIndex, int rightIndex, int (*compare)(void*,void*));
void merge(GenericArray *array, int left, int center, int right, int (*compare)(void*,void*));
int sumsInArray(GenericArray *array_to_test, GenericArray *array_of_sums, int (*compare)(void*,void*), long long * (sums_support)(void*,void*));
