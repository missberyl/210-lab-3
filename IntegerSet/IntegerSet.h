//IntegerSet.h
#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <vector>
using namespace std;
class IntegerSet {
public:
    IntegerSet();
    IntegerSet(int intArray[], int arraySize);
    vector<bool> inputSet();
    IntegerSet unionOfSets(const IntegerSet &set2);
    IntegerSet intersectionOfSets(const IntegerSet &set2);
    bool isEqualTo(const IntegerSet &set2);
    //C#1: A convenient thing about classes, is that we can edit the set vector without needing to pass or return it, making these functions void:
    void insertElement(int k);
    void deleteElement(int m);
    void printSet();
private:
    //C#2: Since vectors can be resized, we don't need to set a size here and can do so with either of the constructors instead.
    vector<bool> set{};
};
#endif //INTEGERSET_H