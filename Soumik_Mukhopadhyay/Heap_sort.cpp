#include<stdio.h> 
#include<time.h>
#include<stdlib.h> 
int temp;  

int *randomNumberGen(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}

void heapify(int *arr, int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heapSort(int *arr, int size)  
{  
    int i;  
    for (i = size / 2 - 1; i >= 0; i--)  
    heapify(arr, size, i);  
    for (i=size-1; i>=0; i--)  
    {  
        temp = arr[0];  
            arr[0]= arr[i];   
            arr[i] = temp;  
        heapify(arr, i, 0);  
    }  
}  
 /* 
void main()  
{  
int arr[] = {1, 10, 2, 3, 4, 1, 2, 100,23, 2};  
int i;  
int size = sizeof(arr)/sizeof(arr[0]);  
  
heapSort(arr, size);  
  
printf("printing sorted elements\n");  
for (i=0; i<size; ++i)  
printf("%d\n",arr[i]);  
} */ 
int main()  
{
    int *arr;
    arr = randomNumberGen(50000);
    clock_t start,end;
    double total=0.0; 
    start=clock();
    heapSort(arr, 50000);
    end=clock();
    total+=(double)(end-start)/CLOCKS_PER_SEC;
    printf("  N=100000 ");
    printf("printing sorted elements\n");  
    printf("\nTime elpased is %f seconds\n", total);    
}
