#include<stdio.h>

void merge(int *arr,int low,int mid,int high){
    int arr_size = high-low+1;
    int temp[arr_size];
    int it=0;
    int left= low;
    int right = mid+1;
    while(left<=mid && right <= high){
        if(arr[left]<=arr[right]){
            temp[it] = arr[left];
            it++;
            left++;
        }
        else{
            temp[it] = arr[right];
            it++;
            right++;
        }
    }
    while(left<=mid){
        temp[it] = arr[left];
        left++;
        it++;
    }
    while(right<=high){
        temp[it] = arr[right];
        right++;
        it++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergesort(int* arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    int arr[7] = {4,2,7,5,9,1,6};
    mergesort(arr,0,6);
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}