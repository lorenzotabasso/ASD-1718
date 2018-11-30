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

    void ** left_sub_array = malloc((n1+1) * sizeof(void *));
    void ** right_sub_array = malloc((n2+1) * sizeof(void *));

    for(i = 0; i < n1; i++) {
        left_sub_array[i] = array[left + i];
    }
    for(j = 0; j < n2; j++) {
        right_sub_array[j] = array[center + j +1];
    }

    /*
     * ATTENZIONE: Usando questa implementazione del mergeSort (dal Cormen)
     * ci sono da tenere in mente 2 accorgimenti sul cambio di int (*compare)!
     *
     * nel caso di int (*compare) con <= usare LLONG_MAX
     * nel caso di int (*compare) con >= usare LLONG_MIN
     *
     * Bisogna fare questo cambiamento poichè il cormen utilizza,
     * nell'ultima posizione dell'array un "valore sentinella", settato a
     * infinito. Essendo che l'infinito o il -infinito nel caso del minimo
     * non è settabile sui computer, utilizziamo l'header <limits.h>
     * e poniamo come valori più bassi (+ e - infinito) LLONG_MAX e LLONG_MIN.
     */

    left_sub_array[i] = (void *) LLONG_MAX;
    right_sub_array[j] = (void *) LLONG_MAX;

    i = 0;
    j = 0;

    for (k = left; k <= right; k++) {
        if (compare(left_sub_array[i], right_sub_array[j])){
            array[k] = left_sub_array[i];
            i++;
        } else {
            array[k] = right_sub_array[j];
            j++;
        }
    }

    free(left_sub_array);
    free(right_sub_array);
}

int sums_in_array(void ** array_to_test, void ** array_of_sums, int size_to_test, int size_of_sums,
        int (*compare)(void*,void*), long * (sums_support)(void*, void*)) {

    int result = 0;
    int  i = 0;
    int j, k;

    while (i < size_of_sums) {
        j = 0;
        k = size_to_test;
        while (j < size_to_test && k > 0 && result != 1) {
            if (j != k && !compare(array_of_sums[i], sums_support(array_to_test[j], array_to_test[k-1])))
                j++;
            else if (j != k && compare(array_of_sums[i], sums_support(array_to_test[j], array_to_test[k-1])))
                k--;
            else
                result = result + 1;
        }
        i++;
    }

    return result;
}

long * sums_support(void* r1_p, void* r2_p){
    long first = (long) r1_p;
    long second = (long) r2_p;

    return (long *) (first + second);
}
