#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
std::map<std::string, std::string> initparser (std::string filePath, bool is_input)
{

    std::ifstream file(filePath.c_str());
    std::cout << "File open: " << file.is_open() << std::endl;
    std::map<std::string, std::string> datePriceMap;
    std::string line;
    bool firstLine = true;
    char sep;
    while (getline(file, line)) {
         if (firstLine) {
            firstLine = false;
            continue;
        }
        if (line.empty())
            continue;
        if (!is_input)
            sep=',';
        sep = '|';
        std::size_t commaPos = line.find(sep);
        if (commaPos == std::string::npos) continue;
        std::string date = line.substr(0, commaPos);
        std::string priceStr = line.substr(commaPos + 1);
        datePriceMap[date] = priceStr;
    }
    file.close();

    return datePriceMap;
}

std::map <Date, Value> parse_to_date (std::map<std::string, std::string> datePriceMap, bool is_input)
{

    std::map <Date, Value> output;

     for (std::map<std::string, std::string>::iterator it = datePriceMap.begin(); it != datePriceMap.end(); ++it) {
        std::string date = it->first;
        std::size_t firstDash = date.find('-');
        std::size_t secondDash = std::string::npos;
        if (firstDash != std::string::npos) {
            secondDash = date.find('-', firstDash + 1);
        }
        if (firstDash != std::string::npos && secondDash != std::string::npos) {
            std::string yearStr = date.substr(0, firstDash);
            std::string monthStr = date.substr(firstDash + 1, secondDash - firstDash - 1);
            std::string dayStr = date.substr(secondDash + 1);

            int year = atoi(yearStr.c_str());
            int month = atoi(monthStr.c_str());
            int day = atoi(dayStr.c_str());
            Date date = Date(day, month, year);
            if (!is_input)
                output[date] = Value(it->second);
            else
                output[date] = Value(it->second, is_input);
        } else {
            std::cerr << "Invalid date format." << std::endl;
        }
    }
    return output;

}

std::map<Date, Value> init(bool is_input)
{
    std::map <Date, Value> dateValue;
    std::map <std::string, std::string> datePriceMap;
    if (!is_input) {
        datePriceMap = initparser("src/data.csv", is_input);
        dateValue = parse_to_date(datePriceMap, is_input);
    }
    else {
        datePriceMap = initparser("src/input.txt", is_input);
        dateValue = parse_to_date(datePriceMap, is_input);
    }
    return (dateValue);
}
void printMap(const std::map<Date, Value>& map) {
    // Use iterator explicitly
    for (std::map<Date, Value>::const_iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
}

int main() {
    // Initialize the maps
    //std::map<Date, Value> database = init(false);
    std::map <Date, Value> input = init(true);
    std::cout << "Input Map:" << std::endl;
    printMap(input);
    // Print the maps
//    std::cout << "Database Map:" << std::endl;
//    printMap(database);


    return 0;
}