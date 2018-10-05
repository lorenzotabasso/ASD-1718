#include <stdio.h>
#include <string.h>

// riscriverlo con il path relativo
#define DATASET_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define ELEMENTS_TO_SCAN 100

unsigned long long toOrder [ELEMENTS_TO_SCAN] = {};

void insertionSort(unsigned long long a[]) 
{
    int i, j;
    unsigned long long key;
    
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

void read(char [300] path) {
    FILE* dataset = fopen(DATASET_PATH, "r");
    if( dataset == NULL ) { 
    perror("Error while opening the file.\n");
    exit(0); // exit failure
    }

    int i = 0;
    while (i < ELEMENTS_TO_SCAN && fscanf(dataset, "%lld", &i)!=EOF) { 
        toOrder[i] // finireeeee
        i++;
    }
    fclose(dataset);
    exit(1); // exit success
}

void printArray(unsigned long long toPrint[]) {
    printf("Conetnuto dell' array:\n");
    for(int i = 0; i < sizeof[toPrint]; i++) 
    {
        printf("%llu,\n", toPrint[i]);
    }
    printf("\n");
}

int main() {
    unsigned long long c [] = {40000000000LL, 10000000000LL, 20000000000LL, 30000000000LL};

    printf("Prima: \n");
    printArray(c)
    
    insertionSort(a);
    
    printf("Dopo: \n");
    printArray(c);

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