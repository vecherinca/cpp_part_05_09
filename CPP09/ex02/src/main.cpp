#include "../headers/PmergeMe.hpp"
//$ ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')


#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if the argument is a valid positive integer
int get_value_or_throw_an_error(const char* arg)
{
    // Check if each character is a digit
    for (int i = 0; arg[i] != '\0'; ++i) {
        if (!isdigit(arg[i])) {
            throw std::invalid_argument("Invalid argument, must be a positive integer.");
        }
    }
    int value = std::atoi(arg);
    if (value <= 0) {
        throw std::invalid_argument("Argument must be a positive integer.");
    }
    return value;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    std::deque<int> myDeque;
    std::vector<int> myVector;

    // Argument verification and conversion to integers
    for (int i = 1; i < argc; ++i) {
        try {
            // Verify if the argument is a valid positive integer
            int value = get_value_or_throw_an_error(argv[i]);

            // Add valid value to deque and vector
            myDeque.push_back(value);
            myVector.push_back(value);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << " Argument: " << argv[i] << std::endl;
            return 1;
        }
    }

    // Print the unsorted sequence
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sort the deque and measure time
    clock_t start = clock();
    PmergeMe::sort(myDeque);
    clock_t end = clock();
    double deque_duration = double(end - start) / CLOCKS_PER_SEC * 1e6;  // Time in microseconds

    // Print the sorted deque
    std::cout << "After: ";
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque: "
              << deque_duration << " us" << std::endl;

    // Sort the vector and measure time
    start = clock();
    PmergeMe::sort(myVector);
    end = clock();
    double vector_duration = double(end - start) / CLOCKS_PER_SEC * 1e6;  // Time in microseconds

    // Print the sorted vector
    std::cout << "After: ";
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector: "
              << vector_duration << " us" << std::endl;

    return 0;
}