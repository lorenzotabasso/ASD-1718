#include <stdio.h>

void insertionSort(int[] array, int n) {
    int i, j;
    int key;
    
    for(i = 1; i < sizeof(array); i++) {
        key = array[i];
        j = i-1;

        
        while(j >= 0 && array[j]) {
            array[j+1] = array[j]; 
            j = j-1; 
        }
        arr[j+1] = key;
        
    }   
}

// da vedere: https://github.com/soupi/3-C-Sorting-Algorithms