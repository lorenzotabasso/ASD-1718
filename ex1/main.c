#include "sorts.h"

int main(int argc, char *argv[]) {
    clock_t begin = clock();

    void ** toSort;
    //toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long)); // funge
    toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(void *)); // funge

    read(DATASET_PATH_INTEGERS, toSort, ELEMENTS_TO_SCAN);
    //read(DATASET_PATH_SUMS, toTest, ELEMENTS_TO_TEST);

    if (strcmp(argv[1], "-print") == 0) {
        printArray(toSort, ELEMENTS_TO_SCAN);

        if (strcmp(argv[2], "-insertionSort") == 0) {
            insertionSort(toSort, compareInsertSort);
            printf("InsertionSort finished\n");
        }
        else {
            mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareMergeSort, toTest);
            printf("Merge finished\n");
            printf("TEST: %d\n", test);
        }

        printArray(toSort, ELEMENTS_TO_SCAN);
    }
    else {
        if (strcmp(argv[1], "-insertionSort") == 0) {
            insertionSort(toSort, compareInsertSort);
            printf("InsertionSort finished\n");
        }
        else {
            mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareMergeSort, toTest);
            printf("Merge finished\n");
            printf("TEST: %d\n", test);
        }
    }

    free(toSort);

    clock_t end = clock();
    double seconds_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds.\n", seconds_spent);

    return 0;
}