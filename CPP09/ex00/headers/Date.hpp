
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
#include <cstdlib>  
#include <stdexcept>  

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
            // this -> day = 0;
            // this -> month = 0;
            // this -> year = 0;
            std::cerr << "Invalid date entered for the following entry." << "Day: " << day<< " Month: " <<  month<< " Year: " << year<< std::endl;
			throw std::invalid_argument("Value invalid");

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
