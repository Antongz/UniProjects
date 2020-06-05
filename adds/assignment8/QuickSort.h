/*prac8
 a1711972
 Yongxin HU
 */
//child sorting class-qucicksort 
#include <iostream>
#include <vector>
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort: public Sort
{
public:
    QuickSort();
    void Sorting(std::vector<int> &qs, int first, int last);
};
#endif
