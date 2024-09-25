#include<stdio.h>
#include<stdlib.h>

void countingsort(int* arr,int n,int exp){
    int count_arr[10] = {0};
    for(int i=0;i<n;i++){
        count_arr[(arr[i]/exp)%10]++;
    }
    
    for(int i=1;i<10;i++){
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }
    
    int* output_arr = (int*)calloc(n,sizeof(int));
    for(int i=n-1;i>=0;i--){
        output_arr[count_arr[(arr[i]/exp)%10]-1] = arr[i];
        count_arr[(arr[i]/exp)%10]--;
    }
    
    for(int i=0;i<n;i++){
        arr[i] = output_arr[i];
    }
}

void radix_sort(int* arr,int n){
    int max_ele=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max_ele){
            max_ele = arr[i];
        }
    }
    
    for(int exp=1;max_ele/exp>0;exp*=10){
        countingsort(arr,n,exp);
    }
    
}

int main(){
    int arr[8] = {4,3,4,5,7,2,2,9};
    radix_sort(arr,8);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}