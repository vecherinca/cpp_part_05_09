#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const char *Date::InvalidFormat::what() const throw()
{
    return ("Not a valid format");
}


const char *Date::InvalidDate::what() const throw()
{
	return ("Is not a valide date");
}

std::map<std::string, double> initparser (std::string filePath)
{

    std::ifstream file(filePath.c_str());
    std::cout << "File open: " << file.is_open() << std::endl;
    std::map<std::string, double> datePriceMap;
    std::string line;
    bool firstLine = true;
    //add here that text verif is needed
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
        
        double price = std::atof(priceStr.c_str());

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

int main(int argc, char **argv) {

    (void) argc;
    (void)argv;

    std::map<std::string, double> datePriceMap = initparser("src/data.csv");
    
    std::cout << "Number of elements in map: " << datePriceMap.size() << std::endl;

    std::map<Date, double> datePrice = parse_to_date(datePriceMap);

    std::cout << "Number of elements in map/upd: " << datePriceMap.size() << std::endl;
    // for (std::map<Date, double>::iterator it = datePrice.begin(); it != datePrice.end(); ++it) {
    //     std::cout << it->first << ":" << it -> second <<  std::endl;
    // }
//    for (std::map<std::string, double>::iterator it = datePriceMap.begin(); it != datePriceMap.end() ; ++it) {
//        std::cout << it->first << ": " << it->second << std::endl;
//    }
    //std::cout << "LOL: " <<std::prev(datePriceMap.end()) -> first << std::endl;


    
    return 0;
}
