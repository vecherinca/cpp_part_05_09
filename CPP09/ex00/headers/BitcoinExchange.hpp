#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stdexcept>
#include <vector>
#include <string>
#include <fcntl.h>
#include "Date.hpp"
class BitcoinExchange
{
  private:
	std::map <std::string, std::string> history;
	std::map <Date, std::string> history_parsed;
	std::map <std::string, std::string> input;
	std::map <std::string, std::string> result;

	public:

};