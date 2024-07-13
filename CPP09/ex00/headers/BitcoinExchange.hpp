
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stdexcept>
#include <vector>
#include <string>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <cstdlib>  // For std::atof
#include <stdexcept>  // For std::invalid_argument and std::out_of_range
class Value {
private:
    double value;

    bool isValidValue(double val) {
        return val >= 0.0;
    }
    bool isValidValueInput(double val) {
        return val >= 0.0 and val < 1000.0;
    }

public:
    Value() {
    }
    Value(const std::string& str) {
        double val;
        if (convertStringToDouble(str, val) && isValidValue(val)) {
            value = val;
        } else {
            std::cerr << "Invalid value provided.:" << str << std::endl;
        }
    }
    Value(const std::string& str, bool verbose) {
        double value;
        (void) verbose;
        if (convertStringToDouble(str, value) && isValidValue(value))
            this -> value = value;
        else
            std::cerr << "Invalid value provided." << value << std::endl;
        }

    // Helper method to convert string to double and check for a valid number
    bool convertStringToDouble(const std::string& str, double& val) {
        try {
            val = std::stod(str);
            return true;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: Could not convert the string to a double." << std::endl;
            return false;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range: The string is too large to convert to a double." << std::endl;
            return false;
        }
    }

    void setValue(const std::string& str) {
        double val;
        if (convertStringToDouble(str, val) && isValidValueInput(val)) {
            value = val;
        } else {
            std::cerr << "Invalid value provided. Value not updated. Put an error here" << std::endl;
        }
    }
    double getValue() const {
        return value;
    }
};


class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true; 
                }
                return false;
            }
            return true; 
        }
        return false;
    }

    bool isValidDate(int day, int month, int year) {
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;

        if (month == 2) { 
            if (isLeapYear(year)) {
                if (day > 29) return false;
            } else {
                if (day > 28) return false;
            }
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                return false;
            }
        }

        return true;
    }

public:
    Date() : day(1), month(1), year(1900) {}

    Date(int day, int month, int year) {
        if (isValidDate(day, month, year)) {

            this->day = day;
            this->month = month;
            this->year = year;
        } else {
            this -> day = 0;
            this -> month = 0;
            this -> year = 0;
            std::cerr << "Invalid date entered for the following entry." << "Day: " << day<< " Month: " <<  month<< " Year: " << year<< std::endl;
//            std::cerr << "Error value is set to zero as atof was performed before. Go check your csv to debug :) " << std::endl;
        }
    }

    void printDate() const {
        std::cout << "Date: " << day << "-" << month << "-" << year << std::endl;
    }
	
    bool operator<(const Date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

	int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

};

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    if (dt.getYear() == 0 || dt.getMonth() == 0|| dt.getDay() == 0)
    {
        std::cerr << "seems to be an error" <<std::endl;
    }
    else {
        os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Value& dt) {
    os <<  dt.getValue();
    return os;
}

class BitcoinExchange
{
  private:
	std::map <std::string, std::string> history;
	std::map <Date, std::string> history_parsed;
	std::map <std::string, std::string> input;
	std::map <std::string, std::string> result;

	public:

};