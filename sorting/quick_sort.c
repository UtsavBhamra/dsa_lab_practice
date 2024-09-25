#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr,int low,int high){
    int p = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= p && i < high) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int* arr,int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}