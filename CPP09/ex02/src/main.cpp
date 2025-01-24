#include "../headers/PmergeMe.hpp"


#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_value_or_throw_an_error(char arg)
{
    if (isdigit(arg))
    {
        int value = std::atoi(argv[i]);
    }
    else
        throw
}

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