#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"

#include <iostream>
using namespace std;

class Bubble: public Sort{
public:
    Bubble();
    void sort(int arr[], int max);
};
#endif