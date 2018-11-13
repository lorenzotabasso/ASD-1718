/*
 * Author: Tabasso, Malgaroli
 *
 */

#ifndef SORTS_H_
#define SORTS_H_

// TODO: ELiminare librerie già usate

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "generic_array.h"

// TODO: 3 parametri: void** array, int size, int (* compare)(void*, void*)

void insertionSort(void ** array, int size, int (*compare)(void*,void*));
void mergeSort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*));
void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*));
int sumsInArray(void ** array_to_test, void ** array_of_sums, int size_to_test, int size_of_sums,
        int (*compare)(void*,void*), long long * (sums_support)(void*, void*));

#endif //SORTS_H_