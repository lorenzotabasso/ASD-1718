#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// riscriverlo con il path relativo
#define DATASET_PATH "/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex1/integers.csv"
#define ELEMENTS_TO_SCAN 20000000

void insertionSort(unsigned long long a[]);
void mergeSort(unsigned long long toOrder[], int left, int right);
void merge(unsigned long long toOrder[], int left, int center, int right);
void read();
void printArray();


void insertionSort(unsigned long long a[]) {
    int i, j;
    unsigned long long key;
    
    for(i = 1; i < ELEMENTS_TO_SCAN; i++) {
        key = a[i];
        j = i-1;

        while(j > 0 && a[j] > key) {
            a[j+1] = a[j]; 
            j--;
        }
        a[j+1] = key;
    }
}

void mergeSort(unsigned long long * arrayToSort, int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int center = (leftIndex + rightIndex) / 2;
        mergeSort(arrayToSort, leftIndex, center);
        mergeSort(arrayToSort, center + 1, rightIndex);
        merge(arrayToSort, leftIndex, center, rightIndex);
    }
}

void merge(unsigned long long * arrayToSort, int left, int center, int right){
    int n1 = center - left + 1;
    int n2 = right - center; 

    unsigned long long leftSubArray[n1+1];
    unsigned long long rightSubArray[n2+1];
    
    leftSubArray[n1] = ULLONG_MAX; // here Cormen use infinite
    rightSubArray[n2] = ULLONG_MAX; // here Cormen use infinite
    
    for(int i = 0; i < n1; i++)
        leftSubArray[i] = arrayToSort[left + i];
    for(int j = 0; j < n2; j++)
        rightSubArray[j] = arrayToSort[center + j + 1];

    int i = 0;
    int j = 0;
    int k = 0;
    
    for(k = left; k <= right; k++){
        if(leftSubArray[i] <= rightSubArray[j]){
            arrayToSort[k] = leftSubArray[i];
            i++;
        } else {
            arrayToSort[k] = rightSubArray[j];
            j++;
        }
    }
}

void read(char pathToDataset[], unsigned long long arrayToFill[]) {
    FILE* dataset = fopen(pathToDataset, "r");
    if(dataset == NULL ) { 
        printf("Error while opening the file.\n");
        exit(0); // exit failure, it closes the program
    }
    int i = 0;
    int millionCount = 0;
    int millionDisplay = 1;
    while (i < ELEMENTS_TO_SCAN && fscanf(dataset, "%llu", &arrayToFill[i])!=EOF) { 
        //printf("%llu\n", arrayToFill[i]); // ONLY FOR DEBUG, it wil print 20ML of lines!
        
        if (millionCount == 1000000) {
            printf("%dM, ", millionDisplay);
            millionDisplay++;
            millionCount = 0;
        }
        
        i++;
    }
    printf("\nRead %d lines.\n", i); 
    fclose(dataset);
}

void printArray(unsigned long long * arrayToPrint, int arrayLength){
    printf("[");
    for(int i = 0; i < arrayLength; i++) {
        if (i == arrayLength-1) {
          printf("%llu]", arrayToPrint[i]);
        }
        else {
            printf("%llu, ", arrayToPrint[i]);
        }
    }
}

int main() {
    //unsigned long long toSort [5] = {53,42,11,24,10};
    unsigned long long toSort [ELEMENTS_TO_SCAN] = {};

    read(DATASET_PATH, toSort);

    //printf("PRIMA: ");
    //printArray(toSort, ELEMENTS_TO_SCAN);
    
    //insertionSort(toSort);
    
    mergeSort(toSort,0,ELEMENTS_TO_SCAN-1);
    printf("Merge terminato\n");

    //printf("DOPO: ");
    //printArray(toSort, ELEMENTS_TO_SCAN);

    return 0;
}

// ALTRE COSE UTILI -----------------------------------------------------------

/*
LINK UTILI:
0) MERGESORT CORMEN CORRETTO https://stackoverflow.com/questions/12056912/how-to-implement-merge-sort-from-the-introduction-to-algorithms-by-cormen-and
1) MERGESORT INTERNET https://www.geeksforgeeks.org/merge-sort/
2) ALGORITMI VARI 1 https://github.com/soupi/3-C-Sorting-Algorithms
3) ALGORITMI VARI 2 https://gist.github.com/justinloundagin/5523524
*/

// PRIMO PROGRAMMA UTILE ------------------------------------------------------

// void mergesort(int a[],int i,int j);
// void merge(int a[],int i1,int j1,int i2,int j2);
 
// int main() {
//     int a[30],n,i;
//     printf("Enter no of elements:");
//     scanf("%d",&n);
//     printf("Enter array elements:");
    
//     for(i=0;i<n;i++)
//         scanf("%d",&a[i]);
        
//     mergesort(a,0,n-1);
    
//     printf("\nSorted array is :");
//     for(i=0;i<n;i++)
//         printf("%d ",a[i]);
        
//     return 0;
// }
 
// void mergesort(int a[],int i,int j) {
//     int mid;
        
//     if(i<j) {
//         mid=(i+j)/2;
//         mergesort(a,i,mid);        //left recursion
//         mergesort(a,mid+1,j);    //right recursion
//         merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
//     }
// }
 
// void merge(int a[],int i1,int j1,int i2,int j2) {
//     int temp[50];    //array used for merging
//     int i,j,k;
//     i=i1;    //beginning of the first list
//     j=i2;    //beginning of the second list
//     k=0;
    
//     //while elements in both lists
//     while(i<=j1 && j<=j2) {
//         if(a[i]<a[j])
//             temp[k++]=a[i++];
//         else
//             temp[k++]=a[j++];
//     }
    
//     while(i<=j1)    //copy remaining elements of the first list
//         temp[k++]=a[i++];
        
//     while(j<=j2)    //copy remaining elements of the second list
//         temp[k++]=a[j++];
        
//     //Transfer elements from temp[] back to a[]
//     for(i=i1,j=0;i<=j2;i++,j++)
//         a[i]=temp[j];
// }

// SECONDO PROGRAMMA UTILE ----------------------------------------------------

// Merge di internet
// void merge(unsigned long long toOrder[], int left, int center, int right) {
//     int i = left;
//     int j = center + 1;
//     int k = 0;
//     unsigned long long temp [(right-left)+1];

//     while(i <= center && j <= right) {
//         if (toOrder[i] <= toOrder[j]) {
//             temp[k] = toOrder[i];
//             i++;
//         }
//         else {
//             temp[k] = toOrder[j];
//             j++;
//         }
//         k++;
//     }
    
//     while(i <= center){
//         temp[k] = toOrder[i];
//         i++;
//         k++;
//     }
    
//     while(j <= right){
//         temp[k] = toOrder[j];
//         j++;
//         k++;
//     }
    
//     for(int k = left; k < right; k++){
//         toOrder[k] = temp[k-left];
//     }
// }


// TERZO PROGRAMMA UTILE (GENERICO) -------------------------------------------
// // C program for insertion sort 
// #include <stdio.h> 
// #include <math.h> 
  
// // Function to sort an array using insertion sort
// void insertionSort(int arr[], int n) 
// { 
//    int i, key, j; 
//    for (i = 1; i < n; i++) 
//    { 
//        key = arr[i]; 
//        j = i-1; 
  
//        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
//        while (j >= 0 && arr[j] > key) 
//        { 
//            arr[j+1] = arr[j]; 
//            j = j-1; 
//        } 
//        arr[j+1] = key; 
//    } 
// } 
  
// // A utility function to print an array of size n 
// void printArray(int arr[], int n) 
// { 
//    int i; 
//    for (i=0; i < n; i++) 
//        printf("%d ", arr[i]); 
//    printf("\n"); 
// } 
  
  
  
// // Driver program to test insertion sort
// int main() 
// { 
//     int arr[] = {12, 11, 13, 5, 6}; 
//     int n = sizeof(arr)/sizeof(arr[0]); 
  
//     insertionSort(arr, n); 
//     printArray(arr, n); 
  
//     return 0; 
// }