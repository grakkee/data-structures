//Sorting Interface
#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

class Sort {
protected:
    int numComparisons, numSwaps;
public:
    int getNumComparisons();
    int getNumSwaps();

    void setNumComparisons(int num);
    void setNumSwaps(int num);

    void reset();
    void swap(int *xp, int *yp);
    virtual void sort(int arr[], int max) = 0;
};
#endif