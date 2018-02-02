#include <iostream>
/**
    CSCI 394
    hw2.cc
    Purpose: finds the highest element of an array with a given value

    @author Alex Grant
    @version 0.1 01/31/18 
*/

/*
    finds the highest element of an array with a given value
    start is a pointer to the first element of the array, finish is the
    element after the last
*/
const int* highest(int val, const int* start, const int* finish) {
    while (start + 1 < finish){
        const int* middle = start + ((finish - start) / 2);    
        if (*middle > val){
            finish = middle;
        } else {
            start = middle;
        }
    }
    if (*start == val){
        return start;
    }
    return nullptr;
}

int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = { 1, 1, 1, 4, 4, 5, 6, 7, 10 };
    // correct responses:        0, 1, 2, 3, 4, 5, 6, 7, 8

    for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) {
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }

    }
    return 0;

}

