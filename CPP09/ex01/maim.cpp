#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Error: bad arguments" << std::endl;
		return 0;
	}
	else{
		try{
			RPN rpn_(av[1]);
			std::cout << rpn_.get_res() << std::endl;
		}
		catch(const char *msg){
			std::cout << msg << std::endl;
		}
	}
}