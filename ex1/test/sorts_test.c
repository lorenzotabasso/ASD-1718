/* 
 * Author: Tabasso, Malgaroli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.h"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.c"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity_internals.h"
#include "../include/sorts.h"
#include "../src/sorts.c"

/*
 * Test suite for generic array data structure and algorithms
 */

int verifySort(void ** array, int size, int (* compare)(void*, void*));

int verifySort(void ** array, int size, int (* compare)(void*, void*)) {
    int test = 1;
    for (int i = 0; i+1 < size && test != 0; i++) {
        if (!compare(array[i],array[i+1])) {
            test = 0;
        }
    }
}

//compare used in tests
static int compare_int(void* first_p, void* second_p){
    int * first_int_p = (int *) first_p;
    int * second_int_p = (int *) second_p;
    if((*first_int_p) < (*second_int_p))
        return(1);
    return(0);
}

int is_sorted(void ** array, int size, int (* compare)(void *, void *)) {
    int i = 0;

    while (i < size-1 && compare(array[i], array[i+1])) {
        i++;
    }

    if (i == size-1) return (1);
    else return (0);
}

//Data elements that must be initialized once, before all tests
static int i1,i2,i3, i4;

//Data element that must be created before each test
void ** array;

void mySetUp(void){
    i1 = -12;
    i2 = 0;
    i3 = 4;
    i4 = 9;

    int * i1_p = &i1;
    int * i2_p = &i2;
    int * i3_p = &i3;
    int * i4_p = &i4;

    array = malloc(3 * sizeof(void *));

    array[0] = (void *) i1_p;
    array[1] = (void *) i2_p;
    array[2] = (void *) i3_p;
    array[3] = (void *) i4_p;
}

void myTearDown(void){
    free(array);
}

static void test_empty_array(void){
    mySetUp();
    insertionSort(array, 3, compare_int);
    TEST_ASSERT_TRUE(is_sorted(array, 3, compare_int));
    myTearDown();
}

int main(void) {

    //test session
    UNITY_BEGIN();

    RUN_TEST(test_empty_array);

    return UNITY_END();
}

