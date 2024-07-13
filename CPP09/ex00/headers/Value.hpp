
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

    bool convertStringToDouble(const std::string& str, double& val) {
        
        val = std::atof(str.c_str());
		if (val == 0 && str != "0")
				throw std::invalid_argument("Value invalid");
        return true;
        
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
