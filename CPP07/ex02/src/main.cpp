#include <iostream>
#include "../headers/Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "\033[31mError: values at index " << i << " do not match!\033[0m" << std::endl;
            return 1;
        }
    }

    std::cout << "ERROR CASES" << std::endl;
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << "ERROR CASES END" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
        std::cout << "\033[36mUpdated numbers[" << i << "] = " << numbers[i] << "\033[0m" << std::endl;
    }

    delete [] mirror;
    return 0;
}