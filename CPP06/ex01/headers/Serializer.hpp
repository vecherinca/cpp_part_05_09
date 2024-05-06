# include <iostream>
# include "stdint.h"
#include "Data.hpp"
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";


class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &cls);
		Serializer &operator=(const Serializer &cls);
	public:
		static uintptr_t	serialize(Data* ptr){
			return (reinterpret_cast<uintptr_t>(ptr));
		}
		static Data			*deserialize(uintptr_t raw){
			return (reinterpret_cast<Data*>(raw));
		}
};