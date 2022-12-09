#ifndef SELECTION_H
#define SELECTION_H

#include "sort.h"

#include <iostream>
using namespace std;

class Selection: public Sort{
public:
    Selection();
    void sort(int arr[], int max);
};
#endif