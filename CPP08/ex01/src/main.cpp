#include "../headers/easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    int numberToFind = 30;
    try {
        int index = easyfind(vec, numberToFind);
        std::cout << "Number " << numberToFind << " found at index " << index << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        numberToFind = 100;
        int index = easyfind(vec, numberToFind);
        std::cout << "Number " << numberToFind << " found at index " << index << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << " for number " << numberToFind << std::endl;
    }

    return 0;
}