/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#ifndef SUMS_H
#define SUMS_H

// It takes as input an array to test made of void pointers,
// an array of void pointers to check if contains at least one element that
// is the sum of two others elements in array_to_test, the size of
// array_to_test, the size of array_of_sums, and a pointer to a
// compare function.
int sums_in_array(void ** array_to_test, void ** array_of_sums,
        int size_to_test, int size_of_sums, int (*compare)(void*,void*));

#endif /* SUMS_H */
