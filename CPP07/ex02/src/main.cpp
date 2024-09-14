#include <iostream>
#include "../headers/Array.hpp"

#define MAX_VAL 20

#include <iostream>
#include "../headers/Array.hpp"

#define MAX_VAL 20

int main() {
    std::cout << YELLOW << "Creating an Array of size " << MAX_VAL << RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    std::cout << YELLOW << "Filling the array and its mirror with random values" << RESET << std::endl;
    srand(time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    std::cout << YELLOW << "Testing the copy constructor and assignment operator" << RESET << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    std::cout << YELLOW << "Verifying that mirror and numbers contain the same values" << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << RED << "Error: values at index " << i << " do not match!" << RESET << std::endl;
            return 1;
        }
    }

    std::cout << GREEN << "Success: All values match between mirror and numbers!" << RESET << std::endl;
    
    std::cout << YELLOW << "Testing out-of-bounds access" << RESET << std::endl;
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "Modifying all elements of numbers with new random values" << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
        std::cout << "\033[36mUpdated numbers[" << i << "] = " << numbers[i] << "\033[0m" << std::endl;
    }

    std::cout << YELLOW << "Cleaning up and releasing memory" << RESET << std::endl;
    delete [] mirror;

    std::cout << GREEN << "Program completed successfully!" << RESET << std::endl;
    return 0;
}
