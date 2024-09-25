#include<stdio.h>
#include<stdlib.h>

void countingsort(int* arr,int n){

    //find the max element in the array
    int max_ele = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max_ele){
            max_ele = arr[i];
        }
    }
    
    //create array of counts 
    int* count_arr = (int*)calloc(max_ele+1,sizeof(int));
    for(int i=0;i<n;i++){
        count_arr[arr[i]]++;
    }
    
    //store the prefix sums in the count array
    for(int i=1;i<max_ele+1;i++){
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }
    
    //put the elements in output array by iterating from back in count array
    int* output_arr = (int*)calloc(n,sizeof(int));

    for(int i=n-1;i>=0;i--){
        output_arr[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]--;
    }
    
    //move elements from output array to original array
    for(int i=0;i<n;i++){
        arr[i] = output_arr[i];
    }
}

int main(){
    int arr[8] = {4,3,4,5,7,2,2,9};
    countingsort(arr,8);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}