/*
 * Author: Tabasso, Malgaroli
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "sorts.h"

// COMPARE FUNCTIONS ---------------------------------------------------------------------------------------------------

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_insertionsort(void* r1_p,void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_record_int_field: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_record_int_field: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    if(first < second){
        return(1);
    }
    return(0);
}

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
int compare_mergesort(void* r1_p,void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_mergesort: the first parameter is a null pointer\n");
        fprintf(stderr,"compare_mergesort: second parameter: %lld", (long long) r2_p);
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_mergesort: the second parameter is a null pointer\n");
        fprintf(stderr,"compare_mergesort: first parameter: %lld\n", (long long) r1_p);
        exit(EXIT_FAILURE);
    }

    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    if(first <= second){
        return(1);
    }
    return(0);
}

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointed value (0 otherwise)
int compare_sums(void* r1_p, void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_record_int_field: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_record_int_field: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    if(first < second){
        return(1);
    }
    return(0);
}

// It takes as input two void pointers.
// It returns the sum of the two pointed values. Used in compare_sums() function.
long long * sums_support(void* r1_p, void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"sums_support: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"sums_support: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    return (long long *) (first + second);
}

// SORTING FUNCTIONS ---------------------------------------------------------------------------------------------------

void insertionSort(GenericArray *array, long long size, int (*compare)(void*,void*)) {
    int i = 0;
    int j = 0;
    void * key;

    for(i = 0; i < size; i++){
        key = generic_array_get(array, (long long) i);
        j = i - 1;
        while (j >= 0 && compare(key, array->array[j])) {
            array->array[j+1] = array->array[j];
            j--;
        }
        array->array[j+1] = key;
    }
}

void mergeSort(GenericArray *array, int leftIndex, int rightIndex, int (*compare)(void*,void*)) {
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        mergeSort(array, leftIndex, center, compare);
        mergeSort(array, center + 1, rightIndex, compare);
        merge(array, leftIndex, center, rightIndex, compare);
    }
}

void merge(GenericArray *array, int left, int center, int right, int (*compare)(void*,void*)) {
    int n1 = (center - left + 1);
    int n2 = (right - center);
    int i, j, k;

    GenericArray * left_sub_array = generic_array_create((long long) n1+1, compare);
    GenericArray * right_sub_array = generic_array_create((long long) n2+1, compare);

    for(i = 0; i < n1; i++) {
        left_sub_array->array[i] = array->array[left + i];
    }
    for(j = 0; j < n2; j++) {
        right_sub_array->array[j] = array->array[center + j +1];
    }

    left_sub_array->array[i] = (void *) LLONG_MAX;
    right_sub_array->array[j] = (void *) LLONG_MAX;

    i = 0;
    j = 0;

    for (k = left; k <= right; k++) {
        if (compare(left_sub_array->array[i], right_sub_array->array[j])){
            array->array[k] = left_sub_array->array[i];
            i++;
        } else {
            array->array[k] = right_sub_array->array[j];
            j++;
        }
    }

    generic_array_free_memory(left_sub_array);
    generic_array_free_memory(right_sub_array);
}

int sumsInArray(GenericArray *array_to_test, GenericArray *array_of_sums, int (*compare)(void*,void*), long long * (sums_support)(void*, void*)) {
    int result = 0;

    long long  i = 0;
    long long j, k;

    while (i < array_of_sums->array_capacity) {
        j = 0;
        k = array_to_test->array_capacity;

        while (j < array_to_test->array_capacity && k > 0 && result != 1) {
            if (j != k && !compare(array_of_sums->array[i], sums_support(array_to_test->array[j], array_to_test->array[k-1]))){
                j++;
            }
            else if (j != k && compare(array_of_sums->array[i], sums_support(array_to_test->array[j], array_to_test->array[k-1]))){
                k--;
            }
            else {
                result = result + 1;
            }
        }
        i++;
    }

    return result;
}