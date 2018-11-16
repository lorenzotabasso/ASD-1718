/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

#ifndef GENERIC_ARRAY_H_
#define GENERIC_ARRAY_H_

#include <stdlib.h>
#include <stdio.h>

// An array of any number of elements of any kind, generic.
typedef struct {
    void ** array;
    long long el_num;
    long long array_capacity;
    int (*compare)(void *, void *);
} GenericArray;

// It creates an empty generic array and returns the created generic array.
// It accepts as input a number which specify the capacity fo the array
// and a compare function which takes as input two void pointes and
// returns 1 iff the first pointed value is less than the second pointed value (0 otherwise)
GenericArray * generic_array_create(long long capacity, int (*compare)(void*,void*));

// It accepts as input a pointer to a generic array and it returns 1 iff
//the generic array is empty (0 otherwise)
int generic_array_is_empty(GenericArray *generic_array);

// It accepts as input a pointer to a generic array and it
// returns the number of elements (size) of the array.
long long generic_array_size(GenericArray * generic_array);

// It accepts as input a pointer to a generic array and a pointer to an element. It adds
// the element to the generic array. The pointer to the element cannot be NULL.
void generic_array_add(GenericArray * generic_array, void* element);

//It accepts as input a pointer to a generic array and a long "i" and
// it returns the pointer to the i-th element of the generic array
void * generic_array_get(GenericArray * generic_array, long long i);

// It accepts as input a pointer to a generic array and
// it frees the memory allocated to store the generic array.
// It does not free the memory allocated to store the array elements,
// since freing that memory is responsibility of the function where
// the generic array was created
void generic_array_free_memory(GenericArray * generic_array);

#endif /* GENERIC_ARRAY_H_ */
