#include "../headers/PmergeMe.hpp"


#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

//static u_int32_t get_num(std::string str) {
//    if (str.size() > 10)
//        throw std::runtime_error("Error: " + str + " is not a valid positive integer");
//
//    size_t i = 0;
//
//    while (i < str.size()) {
//        if (!isdigit(str[i]))
//            throw std::runtime_error("Error: " + str + " is not a valid positive integer");
//        i++;
//    }
//
//    u_int64_t res = std::strtoul(str.c_str(), NULL, 10);
//
//    if (res > std::numeric_limits<u_int32_t>::max())
//        throw std::runtime_error("Error: " + str + " is not a valid positive integer");
//
//    return static_cast<u_int32_t>(res);
//}

int main(int argc, char* argv[]) {
    std::deque<int> myDeque;
    std::vector<int> myVector;

   // add verifs
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        myDeque.push_back(value);
        myVector.push_back(value);
    }

    PmergeMe::sort(myDeque);
    PmergeMe::sort(myVector);

    std::cout << "Deque sorted:" << std::endl;
    for (size_t i = 0; i < myDeque.size(); i += 1)
        std::cout << myDeque[i] << " ";

    return 0;
}