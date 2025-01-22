#include "../headers/BitcoinExchange.hpp"
#include "../src/BitcoinExchange.cpp"

void return_computed_values(std::multimap<Date, Value> input, std::map<Date, Value> db)
{
    for (std::multimap<Date, Value>::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        std::map<Date, Value>::const_iterator db_it = db.find(it->first);
        if (db_it != db.end()) {
            std::cout << "Key: " << db_it->first << " -> Output: " << db_it->second.getValue() * it->second.getValue() << std::endl;
        } else {
            db_it = db.lower_bound(it->first);
            if (db_it == db.begin()) {
                std::cout << "No lower date available for key " << it->first << std::endl;
            } else {
                --db_it; 
                std::cout << "Closest lower date for key " << it->first << " -> Key: " << db_it->first << " -> Output: " << db_it->second.getValue() * it->second.getValue() << std::endl;
            }
        }
    }
}

int main() {
    BitcoinExchange btc;
    std::map<Date, Value> databse = btc.return_data();
    std::multimap<Date, Value> input = btc.return_input();
    return_computed_values(input, databse);

    return 0;
}