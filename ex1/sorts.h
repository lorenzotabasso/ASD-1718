#ifndef EX1_SORTS_H
    #define EX1_SORTS_H
#endif //EX1_SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

// path completo "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
// path relativo "../../laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"

//#define DATASET_PATH_INTEGERS "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
//#define DATASET_PATH_SUMS "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/sums.txt"
#define DATASET_PATH_INTEGERS "/Volumes/HDD/Lorenzo/Downloads/arrayToSort.txt"
#define DATASET_PATH_SUMS "/Volumes/HDD/Lorenzo/Downloads/toTest.txt"
#define ELEMENTS_INTEGERS 9
#define ELEMENTS_SUMS 1

void insertionSort(void ** arrayToSort, int size, int compareArrayAndValue(void** array, int i, void* value));
void mergeSort(void ** arrayToSort, int leftIndex, int rightIndex, int compareValueAndValue(void * firstValue, void * secondValue));
void merge(void** arrayToSort, int left, int center, int right, int compareValueAndValue(void * firstValue, void * secondValue));
int sumsInArray(void ** arrayToTest, void ** arrayOfSums, int compareValueAndValue(void * firstValue, void * secondValue), unsigned long long sums(void * firstValue, void * secondValue));

void read(char pathToDataset[], void ** arrayToFill, int arrayLength);
void printArray(void ** arrayToPrint, int arrayLength);

int compareArrayAndValue(void ** array, int i, void * value);
int compareValueAndValue(void * firstValue, void * secondValue);
unsigned long long sum(void * firstValue, void * secondValue);