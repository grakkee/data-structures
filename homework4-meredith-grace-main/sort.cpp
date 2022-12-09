#include "sort.h"

int Sort::getNumComparisons(){
    return numComparisons;
}
int Sort::getNumSwaps(){
    return numSwaps;
}

void Sort::setNumComparisons(int num){
    numComparisons = num;
}
void Sort::setNumSwaps(int num){
    numSwaps = num;
}
void Sort::reset(){
    numComparisons = 0;
    numSwaps = 0;
} 

void Sort::swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    numSwaps++;
}