
#include "../headers/iter.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <functional> 
#include <unistd.h> 


void squareAndPrint(int x) {
    std::cout << RED << x * x << " ";
}

void doubleAndPrint(float x) {
    std::cout << RED << x * 2 << " ";
}

int main() {
    srand(time(NULL)); 

    const size_t arraySize = 10;
    int intArray[arraySize];
    float floatArray[arraySize];

    for (size_t i = 0; i < arraySize; i++) {
        intArray[i] = rand() % 10 + 1;     
        floatArray[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    std::cout << "Original integer array: ";
    for (size_t i = 0; i < arraySize; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Original float array: ";
    for (size_t i = 0; i < arraySize; i++) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Square of each integer in the array: ";
    Iter::iter(intArray, arraySize, squareAndPrint);
    std::cout << RESET << std::endl;

    std::cout << "Double of each float in the array: ";
    Iter::iter(floatArray, arraySize, doubleAndPrint);
    std::cout << RESET << std::endl;

    return 0;
}