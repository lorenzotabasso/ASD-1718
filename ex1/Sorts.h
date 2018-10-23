#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

// path completo "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
// path relativo "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define DATASET_PATH_INTEGERS "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define DATASET_PATH_SUMS "../../laboratorio-algoritmi-2017-18/Datasets/ex1/sums.txt"
#define ELEMENTS_TO_SCAN 20000000
#define ELEMENTS_TO_TEST 11

void insertionSort(void ** arrayToSort, int compareInsertSort(void* array, int i, void* value));
void mergeSort(void ** arrayToSort, int leftIndex, int rightIndex, int compareMergeSort(void * firstValue, void * secondValue), void ** arrayToTest);
void merge(void** arrayToSort, int left, int center, int right, int compare2(void * firstValue, void * secondValue), void ** arrayToTest);
int usoDue(void ** array, int compareMergeSort(void * firstValue, void * secondValue));

void read(char pathToDataset[], void ** arrayToFill, int arrayLength);
void printArray(void ** arrayToPrint, int arrayLength);

int compareInsertSort(void* array, int i, void* value);
int compareMergeSort(void * firstValue, void * secondValue);