#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

#include<iostream>
using namespace std;

class Quick: public Sort{
public:
    Quick();
    int partition(int arr[], int max);
    void sort(int arr[], int max);
};
#endif