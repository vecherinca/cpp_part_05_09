#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

template<typename MapType,typename InputMapType>
MapType parse_to_date(const InputMapType& datePriceMap, bool is_input) {
    MapType output;

    for (typename InputMapType::const_iterator it = datePriceMap.begin(); it != datePriceMap.end(); ++it) {
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

            try {
                Date date_parsed(day, month, year);
                Value val;
                if (!is_input)
                    val = Value(it->second);
                else
                    val = Value(it->second, is_input);

                output.insert(std::make_pair(date_parsed, val));
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Invalid format." << std::endl;
        }
    }
    return output;
}

template<typename MapType>
MapType initparser(const std::string& filePath, bool is_input) {
    std::ifstream file(filePath.c_str());
    MapType datePriceMap;
    std::string line;
    bool firstLine = true;
    char sep;

    while (getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        if (line.empty()) continue;

        sep = is_input ? '|' : ',';
        std::size_t separatorPos = line.find(sep);
        if (separatorPos == std::string::npos) continue;

        std::string date = line.substr(0, separatorPos);
        std::string priceStr = line.substr(separatorPos + 1);

        datePriceMap.insert(std::make_pair(date, priceStr));
    }
    file.close();

    return datePriceMap;
}

template<typename MapType>
void printMap(const MapType& map) {
    for (typename MapType::const_iterator it = map.begin(); it != map.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
}

std::map<Date, Value> return_data() {
    std::map<std::string, std::string> myMap = initparser<std::map<std::string, std::string> >("src/data.csv", false);
    return parse_to_date<std::map<Date, Value>, std::map<std::string, std::string> >(myMap, false);
}

std::multimap<Date, Value> return_input() {
    std::multimap<std::string, std::string> myMap = initparser<std::multimap<std::string, std::string> >("src/input.txt", true);
    return parse_to_date<std::multimap<Date, Value>, std::multimap<std::string, std::string> >(myMap, false);
}


int main() {
    // Initialize the maps
    // std::map<Date, Value> database = init(false);
    std::multimap<Date, Value> input = return_input();
    for (std::multimap<Date, Value>::const_iterator it = input.begin(); it != input.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
    return 0;
}