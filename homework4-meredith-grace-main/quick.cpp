#include "quick.h"

Quick::Quick(){
    numComparisons = 0;
    numSwaps = 0;
}
int Quick::partition(int arr[], int max){
    int pivot = arr[max];
    int i = -1;

    for(int j = 0; j <= max-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[max]);
    return (i+1);
}

void Quick::sort(int arr[], int max){
    if(0 < max){
        int pi = partition(arr, max);
        sort(arr, pi-1);
        sort(arr, pi+1);
    }

    display(arr, max);
}