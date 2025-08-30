//IntegerSet.cpp
#include <iostream>
#include "IntegerSet.h"
#include <vector>
using namespace std;

IntegerSet::IntegerSet() {
//C#3: Have to initialize the set with 101 elements to represent integers 0-100, as elements are indexed by (size - 1).  All set to false as well to represent the set as "empty".
    set.resize(101, false);
}
IntegerSet::IntegerSet(int intArray[], int arraySize)
{
    set.resize(101, false);
//C#4: When creating a set from a user-inputted array, we can loop and just check for the valid inputs to set to false:
    for (int i = 0; i < arraySize; i++) {
        if (intArray[i] >= 0 && intArray[i] <= 100) {
            set[intArray[i]] = true;
}
}
}
vector<bool> IntegerSet::inputSet() {
    int i;
    cout << "Enter and Element (-1 to End): ";
    cin >> i;
    while (i != -1) {
        if (i < 0 || i > 100) {
            cout << "Invalid Input!\n" << endl;
            cout << "Enter and Element (-1 to End): ";
            cin >> i;
            continue; // Skip to next iteration if invalid input
}
        set[i] = true;
        cout << "Enter and Element (-1 to End): ";
        cin >> i;
}
    return set;
}
IntegerSet IntegerSet::unionOfSets(const IntegerSet &set2) {
//C#5: Since this function is a union, joining the two sets, it uses || as the i value only needs to be present in either of the sets to be added to the combined set3.
    IntegerSet set3;
    for (int i = 0; i < set.size(); i++) {
//C#6: This line of code, and the others like it, threw me for a loop for ages on how to properly format and call the different sets so that I can change the values. But the .set[i] is necessary to access the parameter's (set2) member variable.
        if (set[i] == true || set2.set[i] == true) {
            set3.set[i] = true;
}
}
    return set3;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &set2) {
//C#7: As opposed to above, since this is checking which i values overlap, and thus present in BOTH sets, && needs to be used to determined if the i value should be added to set3.
    IntegerSet set3;
    for (int i = 0; i < set.size(); i++) {
        if (set[i] == true && set2.set[i] == true) {
            set3.set[i] = true;
}
}
    return set3;
}
bool IntegerSet::isEqualTo(const IntegerSet &set2) {
//C#8: Looped this way so that as soon as any 2 values don't match, the function will return false, and thus portentially doesn't have to iterate through the entire set.
    for (int i = 0; i < set.size(); i++) {
        if (set[i] != set2.set[i]) {
            return false;
}
}
    return true;
}
void IntegerSet::insertElement(const int k) {
//C#9: This checks if the k value is valid before attempting to insert it.  I could add and loops to validate the input but, since the k value was passed from main already, there was no need.
    if (k >= 0 && k <= 100) {
        set[k] = true;
}
}
void IntegerSet::deleteElement(const int m) {
//C#9.2: Same as above, but false instead of true:
    if (m >= 0 && m <= 100) {
        set[m] = false;
}
}
void IntegerSet::printSet() {
    bool isEmpty = true;
//C#10: As a space is printed before (and after) each i value, this first { printed doesn't need a space:
    cout << "{";
    for (int i = 0; i < set.size(); i++) {
        if (set[i] == true) {
            cout << " " << i << " ";
            isEmpty = false;
}
}
//C#10.2: And since the first cout statement doesn't have a space after {, this has to have a space around the string to printed as if the set is empty, it will never have the opportunity to print a space:
    if (isEmpty) {
        cout << " --- ";
}
//C#10.3: Same idea as the first bracket, the space before } is taken care of by the previous cout statement, having a space either after the i value or the cout statement following the isEmpty():
    cout << "}" << endl;
};