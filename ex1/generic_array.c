/*
 * Author: Lorenzo Tabasso,
 * Author: Andrea Malgaroli
 *
 */

#include "generic_array.h"

// FUNCTIONS PROTOTYPES ------------------------------------------------------------------------------------------------

static long long get_index_to_insert(GenericArray *array, void* element);
static void insert_element(GenericArray *array, void* element,long long index);

// FUNCTIONS OF GENERIC_ARRAY ------------------------------------------------------------------------------------------

GenericArray *generic_array_create(long long capacity, int (*compare)(void*,void*)){
    GenericArray *array = malloc(sizeof(GenericArray));
    if(array == NULL){
        fprintf(stderr, "generic_array_create: unable to allocate memory for the generic array");
        exit(EXIT_FAILURE);
    }

    array->array = malloc(capacity * sizeof(void*));
    array->el_num = 0;
    array->array_capacity = capacity;
    array->compare = compare;

    return(array);
}

int generic_array_is_empty(GenericArray *array){
    if(array->el_num == 0)
        return(1); // true
    return(0); // false
}

long long generic_array_size(GenericArray *array){
    return(array->el_num);
}

void generic_array_add(GenericArray *array, void* element){
    if(element == NULL){
        fprintf(stderr,"generic_array_add: element parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }

    if(array->el_num >= array->array_capacity){
        array->array = realloc(array->array, 2*(array->array_capacity) * sizeof(void*));
        if(array->array == NULL){
            fprintf(stderr,"generic_array_add: unable to reallocate memory to host the new element");
            exit(EXIT_FAILURE);
        }
        array->array_capacity = 2 * array->array_capacity;
    }

    long long index = get_index_to_insert(array, element); // TODO: rimuoverlo ??

    insert_element(array,element,index);

    (array->el_num)++;

}

void* generic_array_get(GenericArray *array, long long i){
    if(i >= array->el_num){
        fprintf(stderr,"generic_array_get: Index %llu is out of the array bounds",i);
        exit(EXIT_FAILURE);
    }
    return(array->array)[i];
}

void generic_array_free_memory(GenericArray *array){
    free(array->array);
    free(array);
}

// SUPPORT FUNCTIONS ---------------------------------------------------------------------------------------------------

// returns the position where the new element must be inserted
static long long get_index_to_insert(GenericArray *array, void* element){
    long long i = 0;
    while (i < array->el_num) {
        i++;
    }

    return(i);
}

// inserts the specified element in the specified ordered array at the specified
// index position
static void insert_element(GenericArray *array, void* element, long long index){
    for(long long i = array->el_num; i > index; i--){
        (array->array)[i] = (array->array)[i-1];
    }
    (array->array)[index] = element;
}
