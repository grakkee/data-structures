//Grace Meredith
//CS302 Homework #4
//28 March 2021

//The sorting algorithms I chose to compare are bubble, selection and quick

#include <iostream>
#include<string>
#include <ctime>
#include <random>
using namespace std;

#include "bubble.h"
#include "selection.h"
#include "quick.h"

void randomizeArray(int* arr, int max);
void getAverages(int* cpu, int* swaps, int* comparisons, int maxCasees, int* test1, int* test2, int* test3, int max1, int max2, int max3);
void finalizeResults(int* cpu, int* swaps, int* comparisons, int maxCasees, int* test1, int* test2, int* test3, int max1, int max2, int max3);
void displayTable();
void displayGraph();


int main(){
    int test1[1000], test2[10000], test3[100000];
    int averageCPUTimes[9], averageSwaps[9], averageComparisons[9];

    randomizeArray(test1, 1000);
    Bubble test01;
    Quick test02;
    Selection test03;
    test01.sort(test1, 1000);
    test02.sort(test1, 1000);
    test03.sort(test1, 1000);
    //getAverages(averageCPUTimes, averageSwaps, averageComparisons, 9, test1, test2, test3, 1000, 10000, 100000);
    //finalizeResults(averageCPUTimes, averageSwaps, averageComparisons, 9, test1, test2, test3, 1000, 10000, 100000);

    return 0;
}

void randomizArray(int* arr, int max){
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 106);

    for(int i = 0; i < max; i++){
        arr[i] = distribution(generator);
    }
}

void getAverages(int* cpu, int* swaps, int* comparisons, int maxCasees, int* test1, int* test2, int* test3, int max1, int max2, int max3){

}