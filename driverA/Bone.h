/**
* this class will use random number generator 1-9
 * no data structure is needed here
*/
#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Bone
{
public:
    Bone();
    ~Bone();
    Bone(const Bone &);
    Bone& operator=(const Bone &);
    void generateNumbers(int &);

    int getSideA() const {
        return sideA;
    }
    int getSideB() const {
        return sideB;
    }

    int getBoneTotal() const {
        return sideA + sideB;
    }

    void printSides()
    {

        cout << " Side A: " << getSideA() << " Side B: " << getSideB() << endl;
    }

private:
    int sideA, sideB;

};