#include <stdio.h>
#include <stdlib.h>

// riscriverlo con il path relativo
#define DATASET_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define ELEMENTS_TO_SCAN 100000

unsigned long long toOrder [ELEMENTS_TO_SCAN] = {};

void insertionSort(unsigned long long a[]) {
    int i, j;
    unsigned long long key;
    
    for(i = 1; i < ELEMENTS_TO_SCAN; i++) {
        key = a[i];
        j = i-1;

        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j]; 
            j = j-1; 
        }
        a[j+1] = key;
    }
    printf("Sorrting terminato\n");
}

void read() {
    FILE* dataset = fopen(DATASET_PATH, "r");
    if(dataset == NULL ) { 
        printf("Error while opening the file.\n");
        exit(0); // exit failure, it closes the program
    }
    int i = 0;
    int millionCount = 0;
    while (i < ELEMENTS_TO_SCAN && fscanf(dataset, "%lld", &toOrder[i])!=EOF) { 
        //printf("%llu", toOrder[i]); // ONLY FOR DEBUG, it wil print 20ML of lines!
        i++;
    }
    printf("Read %d\n", i); 
    fclose(dataset);
}

void printArray() {
    int length = sizeof(toOrder) / sizeof(toOrder[0]);
    
    // printf("length: %d \n", length); // for debug

    printf("Conetnuto dell' array:\n");
    for(int i = 0; i < length; i++) {
        printf("%llu,\n", toOrder[i]);
    }
    printf("\n");
}

int main() {
    read();
    //printf("Prima: \n");
    //printArray();
    
    insertionSort(toOrder);
    
    //printf("Dopo: \n");
    //printArray();

    return 0;
}

/*
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    mergesort(a,0,n-1);
    
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        
    return 0;
}
 
void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
*/

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