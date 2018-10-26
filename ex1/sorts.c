//
// Created by Lorenzo Tabasso on 24/10/18.
//

#include "sorts.h"

void insertionSort(void ** arrayToSort, int compareArrayAndValue(void* array, int i, void* value)) {
    int i = 0;
    int j = 0;
    void * key;

    for(i = 0; i < ELEMENTS_TO_SCAN; i++){
        key = arrayToSort[i];
        j = i - 1;
        while (j >= 0 && compareArrayAndValue(arrayToSort, j, key)) {
            *(arrayToSort + j + 1) = *(arrayToSort + j);
            j--;
        }
        *(arrayToSort+j+1) = key;
    }
}

void mergeSort(void ** arrayToSort, int leftIndex, int rightIndex, int compareValueAndValue(void * firstValue, void * secondValue), void ** arrayToTest){
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        mergeSort(arrayToSort, leftIndex, center, compareValueAndValue, arrayToTest);
        mergeSort(arrayToSort, center + 1, rightIndex, compareValueAndValue, arrayToTest);
        merge(arrayToSort, leftIndex, center, rightIndex, compareValueAndValue, arrayToTest);
    }
}

void merge(void ** arrayToSort, int left, int center, int right, int compareValueAndValue(void * firstValue, void * secondValue), void ** arrayToTest){
    int n1 = (center - left + 1);
    int n2 = (right - center);
    int i, j, k;

    void ** leftSubArray;
    void ** rightSubArray;
    leftSubArray = malloc((n1+1) * sizeof(void *));
    rightSubArray = malloc((n2+1) * sizeof(void *));

    for(i = 0; i < n1; i++) {
        *(leftSubArray + i) = *(arrayToSort+ left + i);
    }
    for(j = 0; j < n2; j++) {
        *(rightSubArray + j) = *(arrayToSort+ center + j + 1);
    }

    leftSubArray[i] = (void *) ULONG_LONG_MAX;
    rightSubArray[j] = (void *)  ULONG_LONG_MAX;

    i = 0;
    j = 0;
    k = 0;

    for(k = left; k <= right; k++){
        if(compareValueAndValue(leftSubArray[i],rightSubArray[j])){
            *(arrayToSort+ k) = *(leftSubArray + i);
            i++;
        } else {
            *(arrayToSort + k) = *(rightSubArray + j);
            j++;
        }
    }

    free(leftSubArray);
    free(rightSubArray);
}

// TODO: TO FINISH
int sumsInArray(void ** arrayToTest, void ** arrayOfSums, int compareValueAndValue(void * firstValue, void * secondValue), unsigned long long sums((void * firstValue, void * secondValue)) {
    int sizeToTest = sizeof(arrayToTest)/sizeof(*arrayToTest);
    int sizeOfSums = sizeof(arrayOfSums)/sizeof(*arrayOfSums);

    int i1 = 0;
    int i2 = sizeToTest;
    while(i1 < sizeToTest && i2 >= 0 && sizeOfSums > 0) {

        // PRIMA: *(*(arrayToTest + i1))) + *(*(arrayToTest + i2))) < *(arrayOfSums + 0)
        // SECONDA: compareArrayAndValue(arrayOfSums, sizeOfSums, sum(*(arrayToTest + i1), *(arrayToTest + i2)))
        if (compareArrayAndValue(arrayOfSums, sizeOfSums, sum(arrayToTest[i1], arrayToTest[i2]))) {
            i1++;
        }
        else if((unsigned long long) *(leftSubArray + i1) + (unsigned long long) *(rightSubArray + i2) > (unsigned long long) *(arrayToTest + z)) {
            i2--;
        }
        else {
            test = test + 1;
        }
    }
}

// Support functions ---------------------------------------------------------------------------------------------------

void read(char pathToDataset[], void ** arrayToFill, int arrayLength) {
    clock_t start = clock(); // for timing

    FILE* dataset = fopen(pathToDataset, "r");
    if(dataset == NULL ) {
        printf("Error while opening the file.\n");
        exit(0); // exit failure, it closes the program
    }

    int i = 0;

    // TODO: malloc prima, per l'elemento da inserire
    while (i < arrayLength && fscanf(dataset, "%llu", (unsigned long long *) &arrayToFill[i]) != EOF) {
        //printf("line: %d.\n", i);  // ONLY FOR DEBUG, it wil print 20ML of lines!

        // MALLOC di ogni elemento da leggere
        i++;
    }

    // for timing
    clock_t stop = clock();
    double seconds = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Read %d lines in %f seconds.\n", i, seconds);
    fclose(dataset);
}

void printArray(void ** arrayToPrint, int arrayLength){
    printf("[");
    for(int i = 0; i < arrayLength; i++) {
        if (i == arrayLength-1) {
            printf("%llu]\n", (unsigned long long) arrayToPrint[i]);
        }
        else {
            printf("%llu, ", (unsigned long long) arrayToPrint[i]);
        }
    }
}

// COMPARE FUNCTIONS ---------------------------------------------------------------------------------------------------

// It compares 2 elements (array[i] and value). Used in InsertionSort
int compareArrayAndValue(void ** array, int i, void * value) {
    return ((unsigned long long)value) < *((unsigned long long *)array + i);
}

// It compares 2 elements (firstValue and secondValue). Used in MergeSort
int compareValueAndValue(void * firstValue, void * secondValue) {
    return ((unsigned long long*)firstValue) <= (((unsigned long long*)secondValue));
}

unsigned long long sum(void * firstValue, void * secondValue) {
    return *((unsigned long long *)firstValue) + *(((unsigned long long *)secondValue));
}

// Main ----------------------------------------------------------------------------------------------------------------

// int main(int argc, char *argv[]) {
//     clock_t begin = clock();

//     void ** toSort;
//     //toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long)); // funge
//     toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(void *)); // funge

//     void * toTest;
//     toTest = (void **) malloc(ELEMENTS_TO_TEST * sizeof(void *)); // funge

//     read(DATASET_PATH_INTEGERS, toSort, ELEMENTS_TO_SCAN);
//     read(DATASET_PATH_SUMS, toTest, ELEMENTS_TO_TEST);

//     if (strcmp(argv[1], "-print") == 0) {
//         printArray(toSort, ELEMENTS_TO_SCAN);

//         if (strcmp(argv[2], "-insertionSort") == 0) {
//             insertionSort(toSort, compareArrayAndValue);
//             printf("InsertionSort finished\n");
//         }
//         else {
//             mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareValueAndValue, toTest);
//             printf("Merge finished\n");
//             printf("TEST: %d\n", test);
//         }

//         printArray(toSort, ELEMENTS_TO_SCAN);
//     }
//     else {
//         if (strcmp(argv[1], "-insertionSort") == 0) {
//             insertionSort(toSort, compareArrayAndValue);
//             printf("InsertionSort finished\n");
//         }
//         else {
//             mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareValueAndValue, toTest);
//             printf("Merge finished\n");
//             printf("TEST: %d\n", test);
//         }
//     }

//     free(toSort);

//     clock_t end = clock();
//     double seconds_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     printf("Time spent: %f seconds.\n", seconds_spent);

//     return 0;
// }

// ALTRE COSE UTILI ----------------------------------------------------------------------------------------------------

/*
LINK UTILI:
1) MERGESORT CORMEN CORRETTO https://codereview.stackexchange.com/questions/69289/merge-sort-using-sentinels
3) ALGORITMI GENeRICI 1 https://github.com/soupi/3-C-Sorting-Algorithms
4) ALGORITMI GENERICI 2 https://gist.github.com/justinloundagin/5523524
5) https://stackoverflow.com/questions/49336430/algorithm-of-onlogn-to-search-for-sum-of-two-elements-in-two-arrays
*/

// INSERTIONSORT NON GENERICO FUNZIONANTE
// void castedInsertionSort(unsigned long long * arrayToSort){
// 	int i = 0;
//     int j = 0;
//     unsigned long long key;

// 	for(i = 0; i < ELEMENTS_TO_SCAN; i++){
// 		key = *(arrayToSort+i);
// 		j = i - 1;
// 		while (j >= 0 && arrayToSort[j] > key){
// 			arrayToSort[j+1] = arrayToSort[j];
// 			j--;
// 		}
// 		arrayToSort[j+1] = key;
// 	}
// }

// MERGESORT NON GENERICO FUNZIONANTE
//void mergeSort(unsigned long long * arrayToSort, int leftIndex, int rightIndex){
//    if(leftIndex < rightIndex){
//        int center = (leftIndex + rightIndex) / 2;
//        mergeSort(arrayToSort, leftIndex, center);
//        mergeSort(arrayToSort, center + 1, rightIndex);
//        merge(arrayToSort, leftIndex, center, rightIndex);
//    }
//}
//
//void merge(unsigned long long * arrayToSort, int left, int center, int right){
//    int n1 = (center - left + 1);
//    int n2 = (right - center);
//    int i, j, k;
//
//    unsigned long long *leftSubArray;
//    unsigned long long *rightSubArray;
//    leftSubArray = (unsigned long long *) malloc((n1+1) * sizeof(unsigned long long));
//    rightSubArray = (unsigned long long *) malloc((n2+1) * sizeof(unsigned long long));
//
//    for(i = 0; i < n1; i++) {
//        leftSubArray[i] = arrayToSort[left + i];
//    }
//    for(j = 0; j < n2; j++) {
//        rightSubArray[j] = arrayToSort[center + j + 1];
//    }
//
//    leftSubArray[i] = ULONG_LONG_MAX;
//    rightSubArray[j] = ULONG_LONG_MAX;
//
//    i = 0;
//    j = 0;
//    k = 0;
//
//    for(k = left; k <= right; k++){
//        if(leftSubArray[i] <= rightSubArray[j]){
//            arrayToSort[k] = leftSubArray[i];
//            i++;
//        } else {
//            arrayToSort[k] = rightSubArray[j];
//            j++;
//        }
//    }
//
//    free(leftSubArray);
//    free(rightSubArray);
//}

// int usoDue(void ** arrayToTest, void ** sortedArray, int compareValueAndValue(void * firstValue, void * secondValue)) {
//     int j = ELEMENTS_TO_SCAN;

//     for(size_t i = 0; i < ELEMENTS_TO_SCAN && j >=0 ; i++) {
//     //     if ( *(sortedArray+i) + *(sortedArray+j) < x)
//     //     ++i1
//     // else if A1[i1] + A2[i2] > x
//     //     --i2
//     // else
//     //     success!!!!
//     }


// }