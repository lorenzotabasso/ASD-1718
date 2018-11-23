/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

#ifndef SORTS_TEST_H
#define SORTS_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // for timing, see load_array and tests functions
#include "../../Resources/C/Unity/unity.h"
#include "sorts.h"

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is
// less than the second pointer value (0 otherwise).
int compare_insertionsort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is
// less or equal than the second pointer value (0 otherwise).
int compare_mergesort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value
// is less than the second pointed value (0 otherwise).
int compare_sums(void* r1_p, void* r2_p);

// It takes as input an array of void pointers to test if it's sorted,
// the size of the array, and a pointer to a compare function.
// It returns 1 iff the array is correctly sorted (0 otherwise).
int is_sorted(void ** array, int size, int (* compare)(void *, void *));

// It takes as input an array of void pointers, the size of the array,
// and the array's path. It loads all the contents
// of the dataset inside the array
void load_array(void ** array, int size, char * path);

// It takes as input an array of void pointers, and the size of the array.
// It prints the array to command line. Used for tests and debug.
void print_array(void ** array, int size);

// Test for insertion_sort algorithm.
static void test_insertion_sort(void);

// Test for merge_sort algorithm.
static void test_merge_sort(void);

// Test for sums_in_array algorithm.
static void test_sums_in_array(void);

#endif //EX1_UTILITY_H
