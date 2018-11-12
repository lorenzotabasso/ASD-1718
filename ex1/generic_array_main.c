/* 
 * Author: Tabasso, Malgaroli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_array.h"
#include "sorts.h"

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

void test_with_comparison_function(int (*compare)(void*, void*)) {
    GenericArray* array = generic_array_create(11, compare); // 11 is the capacity
    load_array(array, INTEGERS_PATH);
    print_array(array);
    generic_array_free_memory(array);
}

void choicheSorting(const char * algorithm) {
    if (strcmp(algorithm, "-is") == 0) {
        GenericArray* array = generic_array_create(4, compare_insertionsort); // 11 is the capacity
        load_array(array, INTEGERS_PATH);

        printf("\nBefore insertionSort\t");
        print_array(array);

        insertionSort(array, array->array_capacity, compare_insertionsort);

        printf("After insertionSort \t");
        print_array(array);

        generic_array_free_memory(array);

    } else if (strcmp(algorithm, "-ms") == 0) {
        GenericArray* array = generic_array_create(4, compare_sums); // 11 is the capacity
        load_array(array, INTEGERS_PATH);
        print_array(array);

        mergeSort(array, 0, (int) array->array_capacity-1, compare_mergesort);

        generic_array_free_memory(array);

    } else if (strcmp(algorithm, "-sm") == 0) {
        GenericArray* array = generic_array_create(4, compare_sums); // 11 is the capacity
        load_array(array, INTEGERS_PATH);
        print_array(array);

        GenericArray* sums = generic_array_create(2, compare_sums); // 11 is the capacity
        load_array(sums, SUMS_PATH);
        print_array(sums);

        int result = sumsInArray(array, sums, compare_sums, sums_support);
        printf("\nRESULT: %d\n", result);

        generic_array_free_memory(array);
    } else {
        fprintf(stderr, "Sort: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./generic_array_main <mode> <algorithm>\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-u1") == 0) {
        if (strcmp(argv[2], "-is") == 0){
            choicheSorting(argv[2]); // insertionSort
        } else if (strcmp(argv[2], "-ms") == 0) {
            choicheSorting(argv[2]); // mergeSort
        } else {
            fprintf(stderr, "Main: Bad usage, one or more flag not correct, retry!");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(argv[1], "-u2") == 0) {
        choicheSorting("-sm");
    } else {
        fprintf(stderr, "Main: Bad usage, one or more flag not correct, retry!");
        exit(EXIT_FAILURE);
    }

    // a starring simple test, to delete
    //test_with_comparison_function(compare_record_int_field);

    return (EXIT_SUCCESS);
}





