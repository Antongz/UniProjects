/*prac8
 a1711972
 Yongxin HU
 */
//child sorting class-bubble sort

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"
#include <iostream>
#include <vector>


class BubbleSort: public Sort
{
public:
    BubbleSort();
    void Sorting(std::vector<int> &bs);//virtual function with pointer variable
    
};
#endif

