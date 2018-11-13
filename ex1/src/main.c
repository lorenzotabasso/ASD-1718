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

#define INTEGERS_PATH "/Volumes/HDD/Lorenzo/Downloads/ASD Lab PAC/arrayToSort.txt"
#define SUMS_PATH "/Volumes/HDD/Lorenzo/Downloads/ASD Lab PAC/toTest.txt"
#define INTEGERS_ELEMENTS 4
#define SUMS_ELEMENTS 2

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
static long long * sums_support(void* r1_p, void* r2_p);

void load_array(GenericArray* array, char * path);
void print_array(GenericArray* array);
void chooseSorting(const char * algorithm);

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
static long long * sums_support(void* r1_p, void* r2_p){
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


// UTILITY FUNCTIONS ----------------------------------------------------------

void load_array(GenericArray* array, char * path){

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

    while(fgets(buffer, buf_size, dataset_p) != NULL){
        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(read_line_p, buffer);

        char *field_in_read_line_p = strtok(read_line_p, "\n");

        number_in_read_line = strtoull(field_in_read_line_p, (char **) NULL, 10);

        generic_array_add(array, (void *) number_in_read_line);

        free(read_line_p);
    }

    fclose(dataset_p);
    printf("Data loaded\n");
}

void print_array(GenericArray* array){
    long long el_num =  generic_array_size(array);

    long long * to_print_p;

    printf("Array: [");

    for(long long i = 0; i < el_num; i++){
        to_print_p = (long long *) generic_array_get(array, i);
        if (i == el_num-1) {
            printf("%llu]\n", (long long) to_print_p);
        } else {
            printf("%llu, ", (long long) to_print_p);
        }
    }
}

void chooseSorting(const char * algorithm) {
    if (strcmp(algorithm, "-is") == 0) {
        GenericArray* array = generic_array_create(INTEGERS_ELEMENTS, compare_insertionsort);
        load_array(array, INTEGERS_PATH);

        printf("\nBefore insertionSort\t");
        print_array(array);

        insertionSort(array->array, INTEGERS_ELEMENTS, compare_insertionsort);

        printf("After insertionSort \t");
        print_array(array);

        generic_array_free_memory(array);

    } else if (strcmp(algorithm, "-ms") == 0) {
        GenericArray* array = generic_array_create(INTEGERS_ELEMENTS, compare_sums);
        load_array(array, INTEGERS_PATH);

        printf("\nBefore mergeSort\t");
        print_array(array);

        mergeSort(array->array, 0, INTEGERS_ELEMENTS-1, compare_mergesort);

        printf("After mergeSort \t");
        print_array(array);

        generic_array_free_memory(array);

    } else if (strcmp(algorithm, "-sm") == 0) {
        GenericArray* array = generic_array_create(INTEGERS_ELEMENTS, compare_sums);
        load_array(array, INTEGERS_PATH);
        print_array(array);

        GenericArray* sums = generic_array_create(SUMS_ELEMENTS, compare_sums);
        load_array(sums, SUMS_PATH);
        print_array(sums);

        int result = sumsInArray(array->array, sums->array, INTEGERS_ELEMENTS, SUMS_ELEMENTS, compare_sums, sums_support);
        printf("\nRESULT: %d\n", result);

        generic_array_free_memory(sums);
        generic_array_free_memory(array);
    } else {
        fprintf(stderr, "Sort: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }
}

// MAIN -----------------------------------------------------------------------

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./generic_array_main <mode> <algorithm>\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-u1") == 0) {
        if (strcmp(argv[2], "-is") == 0){
            chooseSorting(argv[2]); // insertionSort
        } else if (strcmp(argv[2], "-ms") == 0) {
            chooseSorting(argv[2]); // mergeSort
        } else {
            fprintf(stderr, "Main: Bad usage, one or more flag not correct, retry!");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(argv[1], "-u2") == 0) {
        chooseSorting("-sm");
    } else {
        fprintf(stderr, "Main: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}





