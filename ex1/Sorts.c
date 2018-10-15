#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DATASET_PATH "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define ELEMENTS_TO_SCAN 5

// Functions prototypes ------------------------------------------------------------------------------------------------

void insertionSort(void * arrayToSort, int compare(void* array, int i, void* value), void swap(void* array, int i, int j));
void mergeSort(unsigned long long * arrayToSort, int leftIndex, int rightIndex);
void merge(unsigned long long * arrayToSort, int left, int center, int right);
void read(char pathToDataset[], unsigned long long * arrayToFill);
void printArray(unsigned long long * arrayToPrint, int arrayLength);

void swap(void* array, int i, int j);
int compare(void* array, int i, void* value);
int compareTwoCells(void* array, int i, int j);
int compareTwoCellsInTwoArray(void* array1, void* array2, int i, int j);
void assign(void* toArray, void* fromArray, int i, int j);
void assignValue(void* array, int i, void* value);

// Sorting functions ---------------------------------------------------------------------------------------------------

void insertionSort(void * arrayToSort, int compare(void* array, int i, void* value), void swap(void* array, int i, int j)) {
	int i = 0;
    int j = 0;
    void * key;

	for(i = 0; i < ELEMENTS_TO_SCAN; i++){
		key = (arrayToSort+i);
		j = i - 1;
        printf("KEY: %llu \n", key);
        printArray(arrayToSort, ELEMENTS_TO_SCAN);
		while (j >= 0 && !compare(arrayToSort, j, key)){
            assign(arrayToSort, arrayToSort, j+1, j);
			j--;
		}
        assignValue(arrayToSort, j+1, key);
	}
}

// versione funzionante NON GENERICA
// void insertionSort(unsigned long long * arrayToSort){
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

void mergeSort(unsigned long long * arrayToSort, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        mergeSort(arrayToSort, leftIndex, center);
        mergeSort(arrayToSort, center + 1, rightIndex);
        merge(arrayToSort, leftIndex, center, rightIndex);
    }
}

void merge(unsigned long long * arrayToSort, int left, int center, int right){
    int n1 = (center - left + 1);
    int n2 = (right - center);
    int i, j, k;

    unsigned long long *leftSubArray;
    unsigned long long *rightSubArray;
    leftSubArray = (unsigned long long *) malloc((n1+1) * sizeof(unsigned long long));
    rightSubArray = (unsigned long long *) malloc((n2+1) * sizeof(unsigned long long));

    for(i = 0; i < n1; i++) {
        leftSubArray[i] = arrayToSort[left + i];
    }
    for(j = 0; j < n2; j++) {
        rightSubArray[j] = arrayToSort[center + j + 1];
    }

    leftSubArray[i] = ULONG_LONG_MAX;
    rightSubArray[j] = ULONG_LONG_MAX;

    i = 0;
    j = 0;
    k = 0;

    for(k = left; k <= right; k++){
        if(leftSubArray[i] <= rightSubArray[j]){
            arrayToSort[k] = leftSubArray[i];
            i++;
        } else {
            arrayToSort[k] = rightSubArray[j];
            j++;
        }
    }

    free(leftSubArray);
    free(rightSubArray);
}

// Support functions ---------------------------------------------------------------------------------------------------

void read(char pathToDataset[], unsigned long long * arrayToFill) {
    FILE* dataset = fopen(pathToDataset, "r");
    if(dataset == NULL ) {
        printf("Error while opening the file.\n");
        exit(0); // exit failure, it closes the program
    }

    int i = 0;
    while (i < ELEMENTS_TO_SCAN && fscanf(dataset, "%llu", &arrayToFill[i]) != EOF) {
//        printf("line: %d.\n", i);  // ONLY FOR DEBUG, it wil print 20ML of lines!
        i++;
    }
    printf("Read %d lines.\n", i);
    fclose(dataset);
}

void printArray(unsigned long long * arrayToPrint, int arrayLength){
    printf("[");
    for(int i = 0; i < arrayLength; i++) {
        if (i == arrayLength-1) {
            printf("%llu]\n", arrayToPrint[i]);
        }
        else {
            printf("%llu, ", arrayToPrint[i]);
        }
    }
}

// Main ----------------------------------------------------------------------------------------------------------------

int main() {
    unsigned long long *toSort;
    toSort = (unsigned long long *) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long));

    read(DATASET_PATH, toSort);

    //mergeSort(toSort,0, ELEMENTS_TO_SCAN-1);
    //printf("Merge finished\n");

    //printArray(toSort, ELEMENTS_TO_SCAN);
    insertionSort(toSort, compare, swap);
    printf("InsertionSort finished\n");
    printArray(toSort, ELEMENTS_TO_SCAN);

    free(toSort);
    return 0;
}

// UTILITY---------------------------------------------------------------------------------------------------------------

// Swaps two values in array
void swap(void* array, int i, int j) {
	unsigned long long temp = ((unsigned long long*)array)[i];
	((unsigned long long*)array)[i] = ((unsigned long long*)array)[j];
	((unsigned long long*)array)[j] = temp;
}

// compare 2 cells in array
int compare(void* array, int i, void* value) {
    printf("Risultato Compare: %d,\n", (((unsigned long long*)array)[i] < ((unsigned long long)value)));
	return (((unsigned long long*)array)[i] < ((unsigned long long)value));
}

// compare 2 cells in array
int compareTwoCells(void* array, int i, int j) {
	return (((unsigned long long*)array)[i] < ((unsigned long long*)array)[j]);
}

// compare a cell in 1 array to a cell in another array
int compareTwoCellsInTwoArray(void* array1, void* array2, int i, int j) {
	return (((unsigned long long*)array1)[i] <= ((unsigned long long*)array2)[j]);
}

// assign value from one array to another
void assign(void* toArray, void* fromArray, int i, int j) {
	((unsigned long long*)toArray)[i] = ((unsigned long long*)fromArray)[j];
}

void assignValue(void* array, int i, void* value) {
	((unsigned long long*)array)[i] = (unsigned long long)value;
}

// ALTRE COSE UTILI ----------------------------------------------------------------------------------------------------

/*
LINK UTILI:
1) MERGESORT CORMEN CORRETTO https://codereview.stackexchange.com/questions/69289/merge-sort-using-sentinels
3) ALGORITMI GENeRICI 1 https://github.com/soupi/3-C-Sorting-Algorithms
4) ALGORITMI GENERICI 2 https://gist.github.com/justinloundagin/5523524
*/