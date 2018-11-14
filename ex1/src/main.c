/* 
 * Author: Tabasso, Malgaroli
 *
 */

// TODO: ELiminare librerie già usate

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/generic_array.h"
#include "../include/sorts.h"
#include <time.h> // for timing, see load_array and chooseAlgorithm functions

#define INTEGERS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define SUMS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/sums.txt"
#define INTEGERS_ELEMENTS 20000000
#define SUMS_ELEMENTS 11

// FUNCTIONS PROTOTYPES ------------------------------------------------------------------------------------------------

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
static int compare_insertionsort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
static int compare_mergesort(void* r1_p,void* r2_p);

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointed value (0 otherwise)
static int compare_sums(void* r1_p, void* r2_p);

// It takes as input two void pointers.
// It returns the sum of the two pointed values. Used in compare_sums() function.
static long * sums_support(void* r1_p, void* r2_p);

void load_array(void ** array, int size, char * path);
void print_array(void ** array, int size);
void chooseSorting(const char * algorithm, const char * extra_args);

// COMPARE FUNCTIONS ---------------------------------------------------------------------------------------------------

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer value (0 otherwise)
static int compare_insertionsort(void* r1_p,void* r2_p){
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
static int compare_mergesort(void* r1_p,void* r2_p){
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

    if(first < second){
        return(1);
    }
    return(0);
}

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointed value (0 otherwise)
static int compare_sums(void* r1_p, void* r2_p){
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
static long * sums_support(void* r1_p, void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"sums_support: the first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"sums_support: the second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    long first = (long) r1_p;
    long second = (long) r2_p;

    return (long *) (first + second);
}


// UTILITY FUNCTIONS ----------------------------------------------------------

void load_array(void ** array, int size, char * path){
    clock_t start = clock(); // for timing

    printf("\nLoading data from file...\n");

    FILE * dataset_p = fopen(path, "r");
    if(dataset_p == NULL){
        fprintf(stderr,"Load: unable to open the file");
        exit(EXIT_FAILURE);
    }

    char * read_line_p;
    char buffer[1024];
    int buf_size = 1024;

    long long number_in_read_line = 0;
    void * number_in_read_line_p;
    int i = 0;

    while(fgets(buffer, buf_size, dataset_p) != NULL && i < INTEGERS_ELEMENTS){
        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(read_line_p, buffer);

        char *field_in_read_line_p = strtok(read_line_p, "\n");

        number_in_read_line = strtoull(field_in_read_line_p, (char **) NULL, 10);

        number_in_read_line_p = (void *) number_in_read_line;

        //generic_array_add(array, (void *) number_in_read_line);

        if(number_in_read_line_p == NULL){
            fprintf(stderr,"load_array: number_in_read_line_p parameter cannot be NULL");
            exit(EXIT_FAILURE);
        }
        array[i] = number_in_read_line_p;
        free(read_line_p);
        i++;
    }

    clock_t stop = clock();
    double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

    fclose(dataset_p);
    printf("Data loaded. Read %d lines in %f seconds.\n", i, seconds);
}

void print_array(void ** array, int size){
    long long * to_print_p;
    long long to_print;

    printf("Array: [");

    for(int i = 0; i < size; i++){
        to_print_p = (long long *) array[i];
        to_print = (long long) to_print_p;
        if (i == size-1) {
            printf("%lld]\n", (long long) to_print);
        } else {
            printf("%lld, ", (long long) to_print);
        }
    }
}

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
        insertionSort(array_integers, INTEGERS_ELEMENTS, compare_insertionsort);

        clock_t stop = clock();
        double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("InsertionSort finished, time elapsed: %f seconds\n", seconds);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nAfter insertionSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        free(array_integers);

    } else if (strcmp(algorithm, "-ms") == 0) {
        load_array(array_integers, INTEGERS_ELEMENTS, INTEGERS_PATH);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nBefore mergeSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        printf("\nStarting mergeSort, timer set to 0 seconds.\n");
        mergeSort(array_integers, 0, INTEGERS_ELEMENTS-1, compare_mergesort);

        clock_t stop = clock();
        double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("MergeSort finished, time elapsed: %f seconds\n", seconds);

        if (strcmp(extra_args, "-p") == 0) {
            printf("\nAfter mergeSort\t");
            print_array(array_integers, INTEGERS_ELEMENTS);
        }

        free(array_integers);

    } else if (strcmp(algorithm, "-sm") == 0) {
        load_array(array_integers, INTEGERS_ELEMENTS, INTEGERS_PATH);
        print_array(array_integers, INTEGERS_ELEMENTS);

        load_array(array_sums, SUMS_ELEMENTS, SUMS_PATH);
        print_array(array_sums, SUMS_ELEMENTS);

        int result = sumsInArray(array_integers, array_sums, INTEGERS_ELEMENTS, SUMS_ELEMENTS, compare_sums, sums_support);
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





