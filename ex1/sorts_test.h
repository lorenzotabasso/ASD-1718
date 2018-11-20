//
// Created by Lorenzo Tabasso on 15/11/18.
//

#ifndef EX1_UTILITY_H
#define EX1_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // for timing, see load_array and chooseAlgorithm functions
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.h"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.c"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity_internals.h"
#include "sorts.h"

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_insertionsort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_mergesort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointed value (0 otherwise)
int compare_sums(void* r1_p, void* r2_p);

// It takes as input two void pointers.
// It returns the sum of the two pointed values. Used in compare_sums() function.
long * sums_support(void* r1_p, void* r2_p);

// It takes as input an array of void pointers to test if it's sorted, the size of the array,
// and a pointer to a compare function.
// Iff the array is correctly sorted, it returns a confirm string, otherwise it returns
// a string to evince the opposite
int is_sorted(void ** array, int size, int (* compare)(void *, void *));

void load_array(void ** array, int size, char * path);
void print_array(void ** array, int size);

static void test_insertion_sort(void);
static void test_merge_sort(void);
// CIAONE
static void test_sums_in_array(void);

#endif //EX1_UTILITY_H
