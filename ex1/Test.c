#include "../../laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.h"

void test_InsertionSort() {
    void * toTest;
    //toTest = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long)); // funge
    toTest = (void **) malloc(20 * sizeof(void *)); // funge

    void * toExpect;
    //toTest = (void **) malloc(ELEMENTS_TO_SCAN * sizeof(unsigned long long)); // funge
    toExpect = (void **) malloc(20 * sizeof(void *)); // funge
    
    TEST_ASSERT_EQUAL_INT64_ARRAY(toExpect, toTest, 20);
}

