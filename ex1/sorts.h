/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// TODO: 3 parametri: void** array, int size, int (* compare)(void*, void*)

void insertion_sort(void ** array, int size, int (*compare)(void*,void*));
void merge_sort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*));
void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*));
int sums_in_array(void ** array_to_test, void ** array_of_sums, int size_to_test, int size_of_sums,
        int (*compare)(void*,void*), long * (sums_support)(void*, void*));

#endif //SORTS_H_