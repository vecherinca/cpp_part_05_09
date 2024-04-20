#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// Define color codes for terminal output
#define RED "\033[31m"       // Red color for errors
#define GREEN "\033[32m"     // Green color for success
#define YELLOW "\033[33m"    // Yellow color for warnings
#define RESET "\033[0m"      // Reset to default terminal color

void testBureaucratCreation() {
    std::cout << YELLOW << "Testing Bureaucrat creation..." << RESET << std::endl;
    try {
        Bureaucrat high("High Rank", 1);
        Bureaucrat low("Low Rank", 150);
        std::cout << GREEN << "Success: Created high and low rank bureaucrats." << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testFormCreation() {
    std::cout << YELLOW << "Testing Form creation..." << RESET << std::endl;
    try {
        Form important("Important", 50, 25);
        Form trivial("Trivial", 149, 150);
        std::cout << GREEN << "Success: Created important and trivial forms." << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testSigningForm() {
    std::cout << YELLOW << "Testing Form signing..." << RESET << std::endl;
    Bureaucrat bureaucrat("Official", 75);
    Form form("Classified", 100, 50);
    try {
        bureaucrat.signForm(form);
        std::cout << GREEN << "Success: Form signed by the bureaucrat." << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testInvalidBureaucratCreation() {
    std::cout << YELLOW << "Testing invalid Bureaucrat creation (should fail)..." << RESET << std::endl;
    try {
        Bureaucrat tooHigh("Too High", 0);  // Invalid grade, too high
    } catch (std::exception& e) {
        std::cout << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat tooLow("Too Low", 151);  // Invalid grade, too low
    } catch (std::exception& e) {
        std::cout << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }
}

void testInvalidFormCreation() {
    std::cout << YELLOW << "Testing invalid Form creation (should fail)..." << RESET << std::endl;
    try {
        Form tooTough("Too Tough", 0, 50);  // Invalid sign grade, too high
    } catch (std::exception& e) {
        std::cout << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }

    try {
        Form tooEasy("Too Easy", 200, 151);  // Invalid sign grade, too low
    } catch (std::exception& e) {
        std::cout << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }
}

void testFormSigningFailure() {
    std::cout << YELLOW << "Testing Form signing failure (Bureaucrat grade too low)..." << RESET << std::endl;
    Bureaucrat lowLevel("Low Level", 130);
    Form highRequirement("High Requirement", 50, 50);
    try {
        lowLevel.signForm(highRequirement);
    } catch (std::exception& e) {
        std::cout << RED << "Expected Error: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << YELLOW << "Starting tests for Bureaucrat and Form classes...\n" << RESET;

    testBureaucratCreation();
    testFormCreation();
    testSigningForm();

    testInvalidBureaucratCreation();
    testInvalidFormCreation();
    testFormSigningFailure();

    std::cout << YELLOW << "All tests completed." << RESET << std::endl;
    return 0;
}
