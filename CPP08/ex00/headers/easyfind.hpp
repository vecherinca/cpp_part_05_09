#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <iostream>
#include <iterator> 	 	 
#include <stdexcept>
#include <vector>
#include <list>
	
			template<typename T>
					int easyfind(const T& content, int number) {
					typename T::const_iterator it = std::find(content.begin(), content.end(), number);
					if (it == content.end()) {
						throw std::runtime_error("Value not found");
					}
					return static_cast<int>(it - content.begin());
					}
			#endif