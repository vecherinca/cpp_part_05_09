#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
std::map<std::string, double> initparser (std::string filePath)
{

    std::ifstream file(filePath.c_str());
    std::cout << "File open: " << file.is_open() << std::endl;
    std::map<std::string, double> datePriceMap;
    std::string line;
    bool firstLine = true;
    while (getline(file, line)) {
        
         if (firstLine) {
            firstLine = false;
            continue;
        }

        if (line.empty())
            continue;
        std::size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) continue;
        std::string date = line.substr(0, commaPos);
        std::string priceStr = line.substr(commaPos + 1);
        double price = std::strtod(priceStr.c_str(), nullptr);
        datePriceMap[date] = price;
    }
    file.close();

    return datePriceMap;
}

std::map <Date, double> parse_to_date (std::map<std::string, double> datePriceMap)
{

    std::map <Date, double> output;


     for (std::map<std::string, double>::iterator it = datePriceMap.begin(); it != datePriceMap.end(); ++it) {
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
            output[date] = it->second;
        } else {
            std::cerr << "Invalid date format." << std::endl;
        }
    }

    return output;

}

int main() {
    
    std::map<std::string, double> datePriceMap = initparser("src/data.csv");
    std::cout << "Number of elements in map: " << datePriceMap.size() << std::endl;

    std::map<Date, double> datePrice = parse_to_date(datePriceMap);

    for (std::map<Date, double>::iterator it = datePrice.begin(); it != datePrice.end(); ++it) {
        std::cout << it->first << ":" << it -> second <<  std::endl;
    }
//    for (std::map<std::string, double>::iterator it = datePriceMap.begin(); it != datePriceMap.end() ; ++it) {
//        std::cout << it->first << ": " << it->second << std::endl;
//    }
    //std::cout << "LOL: " <<std::prev(datePriceMap.end()) -> first << std::endl;


    
    return 0;
}
