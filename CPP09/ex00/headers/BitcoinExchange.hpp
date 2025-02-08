
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stdexcept>
#include <vector>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>  // For std::atof
#include <stdexcept>  // For std::invalid_argument and std::out_of_range

#include "Value.hpp"
#include "Date.hpp"

class BitcoinExchange
{
private:
public:
        BitcoinExchange() ;
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &cls); 

        BitcoinExchange &operator=(BitcoinExchange const &obj); 
        template<typename MapType>
        MapType initparser(const std::string& filePath, bool is_input);
        template<typename MapType,typename InputMapType>
        MapType parse_to_date(const InputMapType& datePriceMap, bool is_input);
        std::multimap<Date, Value> return_input();
        std::map<Date, Value> return_data();
};