#include "../headers/Span.hpp"
#include <cstdlib> 
#include <ctime>  
#include <iostream>
#include <vector>

const std::string red("\033[31m");
const std::string green("\033[32m");
const std::string yellow("\033[33m");
const std::string cyan("\033[36m");
const std::string reset("\033[0m");

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Span spEmpty = Span(5);
    try
    {
        spEmpty.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << red << "Test 1 (Empty Span): " << e.what() << reset << '\n';
    }

    spEmpty.addNumber(5);
    try
    {
        spEmpty.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << red << "Test 2 (Single Element): " << e.what() << reset << '\n';
    }

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << cyan << "\nTest 3 (Small Span):\n" << reset;
    std::cout << green << "Shortest Span: " << sp.shortestSpan() << reset << std::endl;
    std::cout << green << "Longest Span: " << sp.longestSpan() << reset << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << yellow << "Test 4 (Adding beyond capacity): " << e.what() << reset << '\n';
    }

    unsigned int largeSize = 10000;
    Span spLarge = Span(largeSize);

    for (unsigned int i = 0; i < largeSize; ++i)
    {
        spLarge.addNumber(std::rand());
    }
    std::cout << cyan << "\nTest 5 (Large Span with addNumber):\n" << reset;
    std::cout << green << "Shortest Span: " << spLarge.shortestSpan() << reset << std::endl;
    std::cout << green << "Longest Span: " << spLarge.longestSpan() << reset << std::endl;

    Span spRange = Span(largeSize);
    std::vector<int> randomNumbers;
    for (unsigned int i = 0; i < largeSize; ++i)
    {
        randomNumbers.push_back(std::rand());
    }

    try
    {
        spRange.addRange(randomNumbers.begin(), randomNumbers.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << yellow << "Test 6 (addRange exception): " << e.what() << reset << '\n';
    }

    std::cout << cyan << "\nTest 6 (Large Span with addRange):\n" << reset;
    std::cout << green << "Shortest Span: " << spRange.shortestSpan() << reset << std::endl;
    std::cout << green << "Longest Span: " << spRange.longestSpan() << reset << std::endl;

    Span spOverflow = Span(largeSize - 1); 
    try
    {
        spOverflow.addRange(randomNumbers.begin(), randomNumbers.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << red << "Test 7 (addRange beyond capacity): " << e.what() << reset << '\n';
    }

    return 0;
}
