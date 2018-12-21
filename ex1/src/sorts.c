/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#include "sorts.h"

void insertion_sort(void ** array, int size, int (*compare)(void*,void*)) {
    int i = 0;
    int j = 0;
    void * key;

    for(i = 0; i < size; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && compare(key, array[j])) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void merge_sort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*)) {
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        merge_sort(array, leftIndex, center, compare);
        merge_sort(array, center + 1, rightIndex, compare);
        merge(array, leftIndex, center, rightIndex, compare);
    }
}

void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*)) {
    int n1 = (center - left + 1);
    int n2 = (right - center);
    int i, j, k;

    void ** left_sub_array = malloc((n1+1) * sizeof(void *));
    void ** right_sub_array = malloc((n2+1) * sizeof(void *));

    for(i = 0; i < n1; i++) {
        left_sub_array[i] = array[left + i];
    }
    for(j = 0; j < n2; j++) {
        right_sub_array[j] = array[center + j +1];
    }

    /*
    From "Introduction to algorithm and Data Structures
    by T.H. Cormen, 3rd edition", page 31, 2nd paragraph (English edition)
    (Italian edition: page 27, 2nd paragrah):

    "The following pseudocode implements the above idea, but with an additional
    twist that avoids having to check whether either pile is empty in each 
    basic step. We place on the bottom of each pile a sentinel card, which 
    contains a special value that we use to simplify our code. ..."
    
    *** BEGIN NOTE **
    In our implementation, the sentinel values are these assignement
    
    left_sub_array[i] = (void *) LLONG_MAX;
    right_sub_array[j] = (void *) LLONG_MAX; 
    
    Pay attention: when "int (*compare)" change from <= to >= and viceversa,
    the previous values MUST be changed in the following way:

    int (*compare) using <= ---> (void *) LLONG_MAX;
    int (*compare) using >= ---> (void *) LLONG_MIN;

    where LLONG_MAX and LLONG_MIN are defined in <limits.h>
    *** END NOTE **

    " ... Here, we use "infinite" as the sentinel value, so that whenever a card 
    with "infinite" is exposed, it cannot be the smaller card unless both piles 
    have their sentinel cards exposed. But once that happens, all the 
    non-sentinel cards have already been placed onto the output pile. 
    Since we know in advance that exactly (r - p + 1) cards .."
    
    *** BEGIN NOTE **
    In our implementation, (r - p + 1) = (right - left + 1)
    *** END NOTE ***
    
    " ... will be placed onto the output pile, we can stop once we have 
    performed that many basic steps."
    */

    left_sub_array[i] = (void *) LLONG_MAX;
    right_sub_array[j] = (void *) LLONG_MAX;

    i = 0;
    j = 0;

    for (k = left; k <= right; k++) {
        if (compare(left_sub_array[i], right_sub_array[j])){
            array[k] = left_sub_array[i];
            i++;
        } else {
            array[k] = right_sub_array[j];
            j++;
        }
    }

    free(left_sub_array);
    free(right_sub_array);
}

int sums_in_array(void ** array_to_test, void ** array_of_sums, int size_to_test, int size_of_sums,
        int (*compare)(void*,void*), long long * (sums_support)(void*, void*)) {

    int result = 0;
    int  i = 0;
    int j, k;

    while (i < size_of_sums) {
        j = 0;
        k = size_to_test;
        while (j < size_to_test && k > 0 && result != 1) {
            if (j != k && !compare(array_of_sums[i], sums_support(array_to_test[j], array_to_test[k-1])))
                j++; // array_of_sums[i] > array_to_test[j] + array_to_test[k-1]
            else if (j != k && compare(array_of_sums[i], sums_support(array_to_test[j], array_to_test[k-1])))
                k--; // array_of_sums[i] < array_to_test[j] + array_to_test[k-1]
            else
                result = result + 1;
        }
        i++;
    }

    return result;
}

long long * sums_support(void* r1_p, void* r2_p){
    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    return (long long *) (first + second);
}
