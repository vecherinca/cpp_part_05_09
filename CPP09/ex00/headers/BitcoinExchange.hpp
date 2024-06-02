
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stdexcept>
#include <vector>
#include <string>
#include <fcntl.h>

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

            std::cerr << "Invalid date entered for the following entry." << "Day: " << day<< " Month: " <<  month<< " Year: " << year<< std::endl;
            std::cerr << "Error value is set to zero as atof was performed before. Go check your csv to debug :) " << std::endl;
        }
    }

    void setDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        } else {
            std::cout << "Invalid date. No changes made." << std::endl;
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
    os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
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