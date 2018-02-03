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
    // needs to be start + 1 so that it terminates when start and finish 
    // are adjacent
    while (start + 1 < finish){
        // if start and finish are right next to each other, then middle
        // will be set to start because floor(1/2) = 0
        const int* middle = start + ((finish - start) / 2);    
        if (*middle > val){
            finish = middle;
        // since we want the highest index, we will move start up even when
        // middle is equal to val
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

    
    // what if the whole array is the same number?
    const int DATA_LEN_TC2 = 4;
    const int data_tc2[DATA_LEN_TC2] = {7, 7, 7, 7};

    for (auto search : {1, 7, 11 }) {
        const auto where = highest(search, data_tc2, data_tc2 + DATA_LEN_TC2);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data_tc2) << std::endl;
        }

    }

    // Negatives?
    const int DATA_LEN_TC3 = 9;
    const int data_tc3[DATA_LEN_TC3] = {-3, -3, -2, -2, -2, -1, 0, 1, 1};
    // indexes:                          0,  1,  2,  3,  4,  5, 6, 7, 8

    for (auto search : {-3, -2, -1, 0, 1, 2}) {
        const auto where = highest(search, data_tc3, data_tc3 + DATA_LEN_TC3);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data_tc3) << std::endl;
        }

    }

    return 0;

}

