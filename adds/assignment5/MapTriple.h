#ifndef MAPTRIPLE_H
#define MAPTRIPLE_H
#include <vector>

//this class will map a given input N, using the function map(input), to 3 N
class MapTriple: public MapGeneric
{
    
public:
    //overwriting pure virtual function making N -> 3N
    int f(int);
};
#endif
