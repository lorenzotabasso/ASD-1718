#include "sorts.h"

int main(int argc, char *argv[]);
void printIfNoError(char * cla, int i, void ** array, int size);
void printIfNoError2(char * cla, int i, void ** array1, int size1, void** array2, int size2);

int main(int argc, char *argv[]) {
    clock_t begin = clock();

    void ** toSort;
    //toSort = (void **) malloc(ELEMENTS_INTEGERS * sizeof(unsigned long long)); // funge
    toSort = (void **) malloc(ELEMENTS_INTEGERS * sizeof(void *)); // funge

    void ** ofSums;
    ofSums = (void **) malloc(ELEMENTS_SUMS * sizeof(void *)); // funge

    if (strcmp(argv[1], "-u1") == 0) {

        if (strcmp(argv[2], "-is") == 0) {

            read(DATASET_PATH_INTEGERS, toSort, ELEMENTS_INTEGERS);

            //printIfNoError(argv[3], 3, toSort, ELEMENTS_INTEGERS);

            printArray(toSort, ELEMENTS_INTEGERS);

            insertionSort(toSort, ELEMENTS_INTEGERS, compareArrayAndValue);
            printf("InsertionSort finished\n");

            //printIfNoError(argv[3], 3, toSort, ELEMENTS_INTEGERS);
            printArray(toSort, ELEMENTS_INTEGERS);

        }
        else if (strcmp(argv[2], "-ms") == 0) {

            read(DATASET_PATH_INTEGERS, toSort, ELEMENTS_INTEGERS);

            printIfNoError(argv[3], 3, toSort, ELEMENTS_INTEGERS);

            mergeSort(toSort,0, ELEMENTS_INTEGERS, compareValueAndValue);
            printf("MergeSort finished\n");

            printIfNoError(argv[3], 3, toSort, ELEMENTS_INTEGERS);
        }
        else {
            printf("Error in Command Line Arguments, one or more illegal flags, retry!");
            exit(0);
        }
    }
    else if (strcmp(argv[1], "-u2") == 0) {

        read(DATASET_PATH_INTEGERS, toSort, ELEMENTS_INTEGERS);
        read(DATASET_PATH_SUMS, ofSums, ELEMENTS_SUMS);

        //printIfNoError2(argv[2], 2, toSort, ELEMENTS_INTEGERS, ofSums, ELEMENTS_SUMS);

        printf("ToSort: ");
        printArray(toSort, ELEMENTS_INTEGERS);
        printf("ToTest: ");
        printArray(ofSums, ELEMENTS_SUMS);

        mergeSort(toSort,0, (int) ELEMENTS_INTEGERS-1, compareValueAndValue);
        printf("MergeSort finished\n");

        int result = sumsInArray(toSort, ofSums, compareValueAndValue, sum);
        printf("Result: %d\n", result);

        //printIfNoError2(argv[2], 2, toSort, ELEMENTS_INTEGERS, ofSums, ELEMENTS_SUMS);

        printf("ToSort: ");
        printArray(toSort, ELEMENTS_INTEGERS);
        printf("ToTest: ");
        printArray(ofSums, ELEMENTS_SUMS);
    }
    else {
        printf("Error in Command Line Arguments, one or more illegal flags, retry!");
        exit(0);
    }

    free(toSort);
    free(ofSums);

    clock_t end = clock();
    double seconds_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds.\n", seconds_spent);

    return 0;
}

void printIfNoError(char * cla, int i, void ** array, int size) {
    if (strcmp(cla+i, "-p") == 0) {
        printArray(array, size);
    } else {
        printf("Error in %d° Command Line Argument, illegal flag. Found: %c\n", i-1, (char) cla);
        exit(0);
    }
}

void printIfNoError2(char * cla, int i, void ** array1, int size1, void** array2, int size2) {
//    if (strcmp((cla+i), "-p") == 0) {
//        printf("ToSort: ");
//        printArray(array1, size1);
//        printf("ToTest: ");
//        printArray(array2, size2);
//    } else {
//        printf("Error in %d° Command Line Argument, illegal flag. Found: %c\n", i, *(cla+i));
//        exit(0);
//    }
    printf("ToSort: ");
    printArray(array1, size1);
    printf("ToTest: ");
    printArray(array2, size2);
}