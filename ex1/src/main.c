/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

// TODO: ELiminare librerie già usate

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sorts.h"
#include "../include/sorts_test.h"

#define INTEGERS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define SUMS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/sums.txt"
#define INTEGERS_ELEMENTS 5
#define SUMS_ELEMENTS 11

void chooseSorting(const char * algorithm, const char * extra_args);

void chooseSorting(const char * algorithm, const char * extra_args) {
    clock_t start = clock();

    void ** array_integers = malloc(INTEGERS_ELEMENTS * sizeof(void*));
    void ** array_sums = malloc(SUMS_ELEMENTS * sizeof(void *));

    if (strcmp(algorithm, "-is") == 0) {
        load_array(array_integers, INTEGERS_ELEMENTS, INTEGERS_PATH);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nBefore insertionSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        printf("\nStarting insertionSort, timer set to 0 seconds.\n");
        insertion_sort(array_integers, INTEGERS_ELEMENTS, compare_insertionsort);

        clock_t stop = clock();
        double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("InsertionSort finished, time elapsed: %f seconds\n", seconds);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nAfter insertionSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        // test is_sorted
        printf("\n%s", is_sorted(array_integers, INTEGERS_ELEMENTS, compare_mergesort));

        free(array_integers);

    } else if (strcmp(algorithm, "-ms") == 0) {
        load_array(array_integers, INTEGERS_ELEMENTS, INTEGERS_PATH);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nBefore mergeSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        printf("\nStarting mergeSort, timer set to 0 seconds.\n");
        merge_sort(array_integers, 0, INTEGERS_ELEMENTS-1, compare_mergesort);

        clock_t stop = clock();
        double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("MergeSort finished, time elapsed: %f seconds\n", seconds);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nAfter mergeSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        // test is_sorted
        printf("\n%s", is_sorted(array_integers, INTEGERS_ELEMENTS, compare_mergesort));

        free(array_integers);

    } else if (strcmp(algorithm, "-sm") == 0) {
        load_array(array_integers, INTEGERS_ELEMENTS, INTEGERS_PATH);
        print_array(array_integers, INTEGERS_ELEMENTS);

        load_array(array_sums, SUMS_ELEMENTS, SUMS_PATH);
        print_array(array_sums, SUMS_ELEMENTS);

        int result = sums_in_array(array_integers, array_sums, INTEGERS_ELEMENTS, SUMS_ELEMENTS, compare_sums, sums_support);
        printf("\nRESULT: %d\n", result);

        free(array_sums);
        free(array_integers);
    } else {
        fprintf(stderr, "Sort: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }
}

// MAIN -----------------------------------------------------------------------

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./generic_array_main <mode> <algorithm> <extra_args>\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-u1") == 0) {
        if (strcmp(argv[2], "-is") == 0){
            if (argv[3] != NULL && strcmp(argv[3], "-p") == 0){
                chooseSorting(argv[2], argv[3]); // insertionSort and print
            } else if (argv[3] == NULL) {
                chooseSorting(argv[2], ""); // only insertionSort
            } else {
                fprintf(stderr, "Main: Bad usage, third flag not correct, retry!");
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(argv[2], "-ms") == 0) {
            if (argv[3] != NULL && strcmp(argv[3], "-p") == 0){
                chooseSorting(argv[2], argv[3]); // mergeSort and print
            } else if (argv[3] == NULL){
                chooseSorting(argv[2], ""); // only mergeSort
            } else {
                fprintf(stderr, "Main: Bad usage, third flag not correct, retry!");
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Main: Bad usage, first flag not correct, retry!");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(argv[1], "-u2") == 0) {
        chooseSorting("-sm", "");
    } else {
        fprintf(stderr, "Main: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}





