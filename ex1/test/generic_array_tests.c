/* 
 * Author: Tabasso, Malgaroli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.h"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity.c"
#include "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Resources/C/Unity/unity_internals.h"
#include "../include/generic_array.h"
#include "../src/generic_array.c"

/*
 * Test suite for generic array data structure and algorithms
 */


//compare used in tests
static int compare_int(void* i1_p,void* i2_p){
  int* int1_p = (int*)i1_p;
  int* int2_p = (int*)i2_p;
  if((*int1_p) < (*int2_p))
    return(1);
  return(0);
}

//Data elements that must be initialized once, before all tests
static int i1,i2,i3;

//Data element that must be created before each test
GenericArray *generic_array_int;

void mySetUp(void){
  i1 = -12;
  i2 = 0;
  i3 = 4;
  generic_array_int = generic_array_create(3, compare_int);
}



void myTearDown(void){
  generic_array_free_memory(generic_array_int);
}


static void test_generic_array_is_empty_zero_el(void){
    mySetUp();
    TEST_ASSERT_TRUE(generic_array_is_empty(generic_array_int));
    myTearDown();
}



static void test_generic_array_is_empty_one_el(void){
    mySetUp();
    generic_array_add(generic_array_int,&i1);
    TEST_ASSERT_FALSE(generic_array_is_empty(generic_array_int));
    myTearDown();
}
  
  
static void test_generic_array_size_zero_el(void){
    mySetUp();
    TEST_ASSERT_EQUAL_INT(0,generic_array_size(generic_array_int));
    myTearDown();
}

  
static void test_generic_array_size_one_el(void){
    mySetUp();
    generic_array_add(generic_array_int,&i1);
    TEST_ASSERT_EQUAL_INT(1,generic_array_size(generic_array_int));
    myTearDown();
}

  
static void test_generic_array_size_two_el(void){
    mySetUp();
    generic_array_add(generic_array_int,&i1);
    generic_array_add(generic_array_int,&i2);
    TEST_ASSERT_EQUAL_INT(2,generic_array_size(generic_array_int));
    myTearDown();
}

static void test_generic_array_add_get_one_el(void){
    mySetUp();
    generic_array_add(generic_array_int,&i1);
    TEST_ASSERT_EQUAL_PTR(&i1,generic_array_get(generic_array_int,0));
    myTearDown();
}

  
static void test_generic_array_array_three_el(void){
    mySetUp();
    int* exp_arr[] = {&i1,&i2,&i3};
    generic_array_add(generic_array_int,&i1);
    generic_array_add(generic_array_int,&i2);
    generic_array_add(generic_array_int,&i3);
    int** act_arr = malloc(3*sizeof(int*));
    for(unsigned long i=0;i<3;i++)
        act_arr[i] = (int*)generic_array_get(generic_array_int,i);
    TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr,act_arr,3);
    myTearDown();
}

int main(void) {

  //test session
  UNITY_BEGIN();
  
  RUN_TEST(test_generic_array_is_empty_zero_el);
  RUN_TEST(test_generic_array_is_empty_one_el);
  RUN_TEST(test_generic_array_size_zero_el);
  RUN_TEST(test_generic_array_size_one_el);
  RUN_TEST(test_generic_array_size_two_el);
  RUN_TEST(test_generic_array_add_get_one_el);
  RUN_TEST(test_generic_array_array_three_el);
  
  return UNITY_END();
}

