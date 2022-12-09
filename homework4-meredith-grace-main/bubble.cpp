#include "bubble.h"

Bubble::Bubble(){
    numComparisons = 0;
    numSwaps = 0;
}

void Bubble::sort(int arr[], int max){
    int i, j;
    bool swapped;

    for(i = 0; i < max - 1; i++){
        swapped = false;
        for(j = 0; j < max-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
            numComparisons++;
        }
        if(swapped == false){
            break;
        }
    }
    display(arr, max);
}

