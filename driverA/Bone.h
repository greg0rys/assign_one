/**
* this class will use random number generator 1-9
 * no data structure is needed here
*/
#pragma once
#include <iostream>
#include <cstdlib>

class Bone
{
public:
    Bone();
    ~Bone();
    Bone(const Bone &);
    Bone& operator=(const Bone &);
    void generateNumbers(int *&);

private:
    int * sideA, * sideB;

};