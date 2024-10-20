#include "../headers/PmergeMe.hpp"


#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::deque<int> myDeque;
    std::vector<int> myVector;

    //check doubles
    //check is it okay
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        myDeque.push_back(value);
        myVector.push_back(value);
    }


//    std::cout << "Deque contains:" << std::endl;
//    for (size_t i = 0; i < myDeque.size(); ++i) {
//        std::cout << myDeque[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Vector contains:" << std::endl;
//    for (size_t i = 0; i < myVector.size(); ++i) {
//        std::cout << myVector[i] << " ";
//    }
//    std::cout << std::endl;

    return 0;
}