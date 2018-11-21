/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

#include "sorts_test.h"

#define INTEGERS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define SUMS_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/sums.txt"

/*
 * Test suite insertion_sort and merge_sort algorithms
 */

// COMPARE FUNCTIONS -----------------------------------------------------------

// It takes as input two void pointers.
// It returns 1 iff the first pointed value is less than the second pointer
// value (0 otherwise)
int compare_insertionsort(void* r1_p,void* r2_p){
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
    // TODO: Attenzione, se usiamo il > da errore! controllare!
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
    long long first = (long long) r1_p;
    long long second = (long long) r2_p;

    if(first < second){
        return(1);
    }
    return(0);
}

// It takes as input two void pointers.
// It returns the sum of the two pointed values. Used in compare_sums() function.
long * sums_support(void* r1_p, void* r2_p){
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

int is_sorted(void ** array, int size, int (* compare)(void *, void *)) {
    int test = 1;
    for (int i = 0; i < size-1; i++) {
        test = compare(array[i], array[i+1]);
    }
    if (test == 1) return (1);
    else return (0);
}

// UTILITY FUNCTIONS -----------------------------------------------------------

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

    while(fgets(buffer, buf_size, dataset_p) != NULL && i < size){
        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(read_line_p, buffer);

        char *field_in_read_line_p = strtok(read_line_p, "\n");

        number_in_read_line = strtoull(field_in_read_line_p, (char **) NULL, 10);

        number_in_read_line_p = (void *) number_in_read_line;

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
    long long * to_print_p = NULL;
    long long to_print = 0;

    printf("Array: [");

    for(int i = 0; i < size; i++){
        to_print_p = (long long *) array[i];
        to_print = (long long) to_print_p;

        if (i == size-1) {
            printf("%lld", to_print);
        } else {
            printf("%lld, ", to_print);
        }
    }

    printf("]\n");
}

// TESTS FUNCTIONS -------------------------------------------------------------

static void test_insertion_sort(void){
    /* Begin Setup */
    void ** array0 = malloc(sizeof(int *)); // empty array
    void ** array1 = malloc(10 * sizeof(int *));
    void ** array2 = malloc(10 * sizeof(int *));
    void ** array3 = malloc(10 * sizeof(int *));
    void ** array_integers = malloc(10 * sizeof(void *));

    long long a1[10] = {1,2,3,4,5,6,7,8,9,10};
    long long a2[10] = {6,1,2,7,9,8,3,5,10,4};
    long long a3[10] = {10,9,8,7,6,5,4,3,2,1};

    void * a1_ptr;
    void * a2_ptr;
    void * a3_ptr;

    for (int i = 0; i < 10; ++i) {
        a1_ptr = (void *) a1[i];
        array1[i] = a1_ptr;

        a2_ptr = (void *) a2[i];
        array2[i] = a2_ptr;

        a3_ptr = (void *) a3[i];
        array3[i] = a3_ptr;
    }

    load_array(array_integers, 10, INTEGERS_PATH);
    /* End Setup */

    clock_t start = clock();

    printf("\nBefore insertionSort\n");
    print_array(array0, 0);
    print_array(array1,10);
    print_array(array2,10);
    print_array(array3,10);
    print_array(array_integers, 10);

    printf("\nStarting insertionSort, timer set to 0 seconds.\n");
    insertion_sort(array0, 0, compare_insertionsort);
    insertion_sort(array1, 10, compare_insertionsort);
    insertion_sort(array2, 10, compare_insertionsort);
    insertion_sort(array3, 10, compare_insertionsort);
    insertion_sort(array_integers, 10, compare_insertionsort);

    clock_t stop = clock();
    double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("InsertionSort finished, time elapsed: %f seconds\n", seconds);

    printf("\nAfter insertionSort:\n");
    print_array(array0,0);
    print_array(array1,10);
    print_array(array2,10);
    print_array(array3,10);
    print_array(array_integers, 10);

    TEST_ASSERT_TRUE(is_sorted(array0, 0, compare_insertionsort));
    TEST_ASSERT_TRUE(is_sorted(array1, 10, compare_insertionsort));
    TEST_ASSERT_TRUE(is_sorted(array2, 10, compare_insertionsort));
    TEST_ASSERT_TRUE(is_sorted(array3, 10, compare_insertionsort));
    TEST_ASSERT_TRUE(is_sorted(array_integers, 10, compare_insertionsort));

    /* Begin Teardown */
    free(array0);
    free(array1);
    free(array2);
    free(array3);
    free(array_integers);
    /* End Teardown */

} /* End test_insertion_sort */

static void test_merge_sort(void){
    /* Begin Setup */
    void ** array0 = malloc(sizeof(int *));
    void ** array1 = malloc(10 * sizeof(int *));
    void ** array2 = malloc(10 * sizeof(int *));
    void ** array3 = malloc(10 * sizeof(int *));
    void ** array_integers = malloc(20000000 * sizeof(void *));

    long long a1[10] = {1,2,3,4,5,6,7,8,9,10};
    long long a2[10] = {6,1,2,7,9,8,3,5,10,4};
    long long a3[10] = {10,9,8,7,6,5,4,3,2,1};

    void * a1_ptr;
    void * a2_ptr;
    void * a3_ptr;

    for (int i = 0; i < 10; ++i) {
        a1_ptr = (void *) a1[i];
        array1[i] = a1_ptr;

        a2_ptr = (void *) a2[i];
        array2[i] = a2_ptr;

        a3_ptr = (void *) a3[i];
        array3[i] = a3_ptr;
    }

    load_array(array_integers, 20000000, INTEGERS_PATH);
    /* End Setup */

    clock_t start1 = clock();

    printf("\nBefore mergeSort:\n");
    print_array(array1,0);
    print_array(array1,10);
    print_array(array2,10);
    print_array(array3,10);

    printf("\nStarting mergeSort, timer set to 0 seconds.\n");
    merge_sort(array0, 0, 0, compare_mergesort);
    merge_sort(array1, 0, 10-1, compare_mergesort);
    merge_sort(array2, 0, 10-1, compare_mergesort);
    merge_sort(array3, 0, 10-1, compare_mergesort);

    clock_t stop1 = clock();
    double seconds1 = (double)(stop1 - start1) / CLOCKS_PER_SEC;

    printf("MergeSort finished, time elapsed: %f seconds\n", seconds1);

    printf("\nAfter mergeSort:\n");
    print_array(array0,0);
    print_array(array1,10);
    print_array(array2,10);
    print_array(array3,10);

    printf("\nRestarting mergeSort on array_integers. Timer reset to 0 seconds.\n");

    clock_t start2 = clock();
    merge_sort(array_integers, 0, 20000000-1, compare_mergesort);

    clock_t stop2 = clock();
    double seconds2 = (double)(stop2 - start2) / CLOCKS_PER_SEC;

    printf("MergeSort of array_integers finished, time elapsed: %f seconds\n", seconds2);

    TEST_ASSERT_TRUE(is_sorted(array0, 0, compare_mergesort));
    TEST_ASSERT_TRUE(is_sorted(array1, 10, compare_mergesort));
    TEST_ASSERT_TRUE(is_sorted(array2, 10, compare_mergesort));
    TEST_ASSERT_TRUE(is_sorted(array3, 10, compare_mergesort));
    TEST_ASSERT_TRUE(is_sorted(array_integers, 20000000, compare_mergesort));

    /* Begin Teardown */
    free(array1);
    free(array2);
    free(array3);
    free(array_integers);
    /* End Teardown */

} /* End test_merge_sort */

static void test_sums_in_array(void){
    /* Begin Setup */
    void ** array0 = malloc(sizeof(int *));
    void ** array1 = malloc(10 * sizeof(int *));
    void ** array2 = malloc(5 * sizeof(int *));
    void ** array_integers = malloc(20000000 * sizeof(void *));
    void ** array_sums = malloc(11 * sizeof(void *));

    long long a1[10] = {10,9,8,7,6,5,4,3,2,1};
    long long a2[5] = {4,7,6,1,9};

    void * a1_ptr;
    void * a2_ptr;

    for (int i = 0; i < 10; ++i) {
        a1_ptr = (void *) a1[i];
        array1[i] = a1_ptr;
    }

    for (int j = 0; j < 5; ++j) {
        a2_ptr = (void *) a2[j];
        array2[j] = a2_ptr;
    }

    load_array(array_integers, 20000000, INTEGERS_PATH);
    load_array(array_sums, 11, SUMS_PATH);
    /* End Setup */

    clock_t start1 = clock();

    printf("\nBefore mergeSort\n");
    print_array(array0, 0);
    print_array(array1, 10);

    printf("\nStarting mergeSort, timer set to 0 seconds.\n");
    merge_sort(array0, 0, 0, compare_mergesort);
    merge_sort(array1, 0, 10-1, compare_mergesort);

    clock_t stop1 = clock();
    double seconds1 = (double)(stop1 - start1) / CLOCKS_PER_SEC;

    printf("MergeSort finished, time elapsed: %f seconds\n", seconds1);

    printf("\nAfter mergeSort\n");
    print_array(array0, 0);
    print_array(array1, 10);

    printf("Applying sums_in_array function. ");
    int result1 = sums_in_array(array1, array2, 10, 5, compare_sums, sums_support);
    printf("Result: %d\n", result1);

    TEST_ASSERT_TRUE(is_sorted(array0, 0, compare_mergesort));
    TEST_ASSERT_TRUE(is_sorted(array1, 10, compare_mergesort));
    TEST_ASSERT_TRUE(result1 == 1);

    /* Restart with array_integers of 20000000 elements */

    printf("\nRestarting mergeSort on array_integers. Timer reset to 0 seconds.\n");

    clock_t start2 = clock();
    merge_sort(array_integers, 0, 20000000-1, compare_mergesort);

    clock_t stop2 = clock();
    double seconds2 = (double)(stop2 - start2) / CLOCKS_PER_SEC;

    printf("MergeSort finished, time elapsed: %f seconds\n", seconds2);

    printf("Applying sums_in_array function. ");
    int result2 = sums_in_array(array_integers, array_sums, 20000000, 11, compare_sums, sums_support);
    printf("Result: %d\n", result2);

    TEST_ASSERT_TRUE(is_sorted(array_integers, 20000000, compare_mergesort));
    TEST_ASSERT_TRUE(result2 == 1);

    /* Begin Teardown*/
    free(array0);
    free(array1);
    free(array2);
    free(array_integers);
    free(array_sums);
    /* End Teardown */

} /* End test_sums_in_array */

int main(void) {

    UNITY_BEGIN();
    RUN_TEST(test_insertion_sort);
    RUN_TEST(test_merge_sort);
    RUN_TEST(test_sums_in_array);

    return UNITY_END();
}
