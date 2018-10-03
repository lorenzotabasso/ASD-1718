#include <stdio.h>
#include <math.h> 

void insertionSort(long long a[]) 
{
    int i, j;
    int key;
    
    for(i = 1; i < 11; i++) 
    {
        key = a[i];
        j = i-1;

        
        while(j >= 0 && a[j] > key) 
        {
            a[j+1] = a[j]; 
            j = j-1; 
        }
        a[j+1] = key;
    }   
}

int main() 
{
    long long a [] = {178045131, 154266748, 93573006, 191011796, 63744743, 139183879, 102116441, 166015103, 100000000, 100, 40000000000};
    int b [] = {22,45,67,34,10,1,5,7,3,6,256};

    printf("Prima: \n");
    for(int i = 0; i < 11; i++) 
    {
        printf("%llu,\n", a[i]);
        //printf("%d, ", b[i]);
    }
    printf("\n\n");
    
    insertionSort(a);
    
    printf("Dopo: \n");
    for(int i = 0; i < 11; i++) 
    {
        printf("%llu,\n", a[i]);
        //printf("%d, ", b[i]);
    }
    printf("\n\n");

    return 0;
}


// LINK UTILI: 
// https://github.com/soupi/3-C-Sorting-Algorithms
// https://gist.github.com/justinloundagin/5523524

/*
// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 
  
// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 
  
// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
   int i; 
   for (i=0; i < n; i++) 
       printf("%d ", arr[i]); 
   printf("\n"); 
} 
  
  
  
// Driver program to test insertion sort
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    insertionSort(arr, n); 
    printArray(arr, n); 
  
    return 0; 
}  
*/