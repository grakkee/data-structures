#include "selection.h"

Selection::Selection(){
    numComparisons = 0;
    numSwaps = 0;
}

void Selection::sort(int arr[], int max){
    int i, j, min_idx;

    for(i = 0; i < max-1; i++){
        min_idx = i;
        for(j = i+1; j < max; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
            numComparisons++;
        }
        swap(&arr[min_idx], &arr[i]);
    }

    display(arr, max);
}
