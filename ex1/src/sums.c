/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#include "sorts.h"
#include "sums.h"

// Support function used in sums_in_array() function.
// It takes as input two void pointers.
// It returns the sum of the two pointed values (used for compare purpose).
long long * sums_support(void* r1_p, void* r2_p);

int sums_in_array(void ** array_to_test, void ** array_of_sums,
        int size_to_test, int size_of_sums, int (*compare)(void*,void*)) {

    int result = 0;
    int  i = 0;
    int j, k;

    while (i < size_of_sums) {
        j = 0;
        k = size_to_test;
        while (j < size_to_test && k > 0 && result != 1) {
            if (j != k && !compare(array_of_sums[i],
                    sums_support(array_to_test[j], array_to_test[k-1]))) {
                // array_of_sums[i] > array_to_test[j] + array_to_test[k-1]
                j++;
            } else if (j != k && compare(array_of_sums[i],
                    sums_support(array_to_test[j], array_to_test[k-1]))) {
                // array_of_sums[i] < array_to_test[j] + array_to_test[k-1]
                k--;
            } else {
                result = result + 1;
            }
        }
        i++;
    }

    return result;
}

// Pay attention: for use sums_in_array function with every other type not
// equal to "long long", you must change all the types of this function,
// in order to perform the sum of the the two elements pointer by r1_p and r2_p.
long long * sums_support(void* r1_p, void* r2_p){
    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    return (long long *) (first + second);
}
