/*
 * Author: Lorenzo Tabasso, mat: 812499
 * Author: Andrea Malgaroli, mat: 823429
 */

#include "sorts.h"

void insertion_sort(void ** array, int size, int (*compare)(void*,void*)) {
    int i = 0;
    int j = 0;
    void * key;

    for(i = 0; i < size; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && compare(key, array[j])) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void merge_sort(void ** array, int leftIndex, int rightIndex, int (*compare)(void*,void*)) {
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        merge_sort(array, leftIndex, center, compare);
        merge_sort(array, center + 1, rightIndex, compare);
        merge(array, leftIndex, center, rightIndex, compare);
    }
}

void merge(void ** array, int left, int center, int right, int (*compare)(void*,void*)) {
    int n1 = (center - left + 1);
    int n2 = (right - center);
    int i, j, k;

    void ** left_sub_array = malloc((n1) * sizeof(void *));
    void ** right_sub_array = malloc((n2) * sizeof(void *));

    for(i = 0; i < n1; i++) {
        left_sub_array[i] = array[left + i];
    }
    for(j = 0; j < n2; j++) {
        right_sub_array[j] = array[center + j +1];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (compare(left_sub_array[i], right_sub_array[j])){
            array[k] = left_sub_array[i];
            i++;
        } else {
            array[k] = right_sub_array[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_sub_array[], if there are any
    while (i < n1) {
        array[k] = left_sub_array[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_sub_array[], if there are any
    while (j < n2) {
        array[k] = right_sub_array[j];
        j++;
        k++;
    }

    free(left_sub_array);
    free(right_sub_array);
}
