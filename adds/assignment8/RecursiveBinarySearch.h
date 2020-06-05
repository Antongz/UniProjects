#include<vector>
#include <iostream>
#ifndef RECUSIVEBINARYSEARCH_H
#define RECUSIVEBINARYSEARCH_H

//recusive binary search class

class RecursiveBinarySearch
{
public:
     RecursiveBinarySearch();
    int binary_search(std::vector<int> &bins, int start, int end, int key);

};
#endif
