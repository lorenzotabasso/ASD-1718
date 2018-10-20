#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

// path completo "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
// path relativo "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define DATASET_PATH "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define ELEMENTS_TO_SCAN 20

/*
 * Insertionsort (200000 records) = 1:14 min
 */

// Functions prototypes ------------------------------------------------------------------------------------------------

void insertionSort(void ** arrayToSort, int compareInsertSort(void* array, int i, void* value));
void mergeSort(void ** arrayToSort, int leftIndex, int rightIndex, int compareMergeSort(void * firstValue, void * secondValue));
void merge(void** arrayToSort, int left, int center, int right, int compare2(void * firstValue, void * secondValue));

void read(char pathToDataset[], void ** arrayToFill);
void printArray(void ** arrayToPrint, int arrayLength);

int compareInsertSort(void* array, int i, void* value);
int compareMergeSort(void * firstValue, void * secondValue);

// Sorting functions ---------------------------------------------------------------------------------------------------

void insertionSort(void ** arrayToSort, int compareInsertSort(void* array, int i, void* value)) {
    int i = 0;
    int j = 0;
    void * key;

    for(i = 0; i < ELEMENTS_TO_SCAN; i++){
        key = arrayToSort[i];
        j = i - 1;
        while (j >= 0 && compareInsertSort(arrayToSort, j, key)) {
            *(arrayToSort + j + 1) = *(arrayToSort + j);
            j--;
        }
        *(arrayToSort+j+1) = key;
    }
}

void mergeSort(void ** arrayToSort, int leftIndex, int rightIndex, int compareMergeSort(void * firstValue, void * secondValue)){
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        mergeSort(arrayToSort, leftIndex, center, compareMergeSort);
        mergeSort(arrayToSort, center + 1, rightIndex, compareMergeSort);
        merge(arrayToSort, leftIndex, center, rightIndex, compareMergeSort);
    }
}

void merge(void ** arrayToSort, int left, int center, int right, int compareMergeSort(void * firstValue, void * secondValue)){
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
        if(compareMergeSort(leftSubArray[i],rightSubArray[j])){
            *(arrayToSort+ k) = *(leftSubArray + i);
            i++;
        } else {
            *(arrayToSort+ k) = *(rightSubArray+ j);
            j++;
        }
    }

    free(leftSubArray);
    free(rightSubArray);
}

// Support functions ---------------------------------------------------------------------------------------------------

void read(char pathToDataset[], void ** arrayToFill) {
    clock_t start = clock(); // for timing

    FILE* dataset = fopen(pathToDataset, "r");
    if(dataset == NULL ) {
        printf("Error while opening the file.\n");
        exit(0); // exit failure, it closes the program
    }

    int i = 0;

    // TODO: chiedere a Damiani se il cast va bene!!
    while (i < ELEMENTS_TO_SCAN && fscanf(dataset, "%llu", (unsigned long long *) &arrayToFill[i]) != EOF) {
        //printf("line: %d.\n", i);  // ONLY FOR DEBUG, it wil print 20ML of lines!
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

// Main ----------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
    clock_t begin = clock();

    void * toSort;
    //toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long)); // funge
    toSort = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(void *)); // funge

    read(DATASET_PATH, toSort);

    if (strcmp(argv[1], "-print") == 0) {
        printArray(toSort, ELEMENTS_TO_SCAN);

        if (strcmp(argv[2], "-insertionSort") == 0) {
            insertionSort(toSort, compareInsertSort);
            printf("InsertionSort finished\n");
        }
        else {
            mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareMergeSort);
            printf("Merge finished\n");
        }

        printArray(toSort, ELEMENTS_TO_SCAN);
    }
    else {
        if (strcmp(argv[1], "-insertionSort") == 0) {
            insertionSort(toSort, compareInsertSort);
            printf("InsertionSort finished\n");
        }
        else {
            mergeSort(toSort,0, ELEMENTS_TO_SCAN-1, compareMergeSort);
            printf("Merge finished\n");
        }
    }

    free(toSort);

    clock_t end = clock();
    double seconds_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds.\n", seconds_spent);

    return 0;
}



// COMPARE FUNCTIONS ---------------------------------------------------------------------------------------------------

// It compares 2 elements (array[i] and value). Used in InsertionSort
int compareInsertSort(void * array, int i, void * value) {
    return ((unsigned long long)value) < (((unsigned long long*)array)[i]);
}

// It compares 2 elements (firstValue and secondValue). Used in MergeSort
int compareMergeSort(void * firstValue, void * secondValue) {
    return ((unsigned long long*)firstValue) <= (((unsigned long long*)secondValue));
}

// ALTRE COSE UTILI ----------------------------------------------------------------------------------------------------

/*
LINK UTILI:
1) MERGESORT CORMEN CORRETTO https://codereview.stackexchange.com/questions/69289/merge-sort-using-sentinels
3) ALGORITMI GENeRICI 1 https://github.com/soupi/3-C-Sorting-Algorithms
4) ALGORITMI GENERICI 2 https://gist.github.com/justinloundagin/5523524
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