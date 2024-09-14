#include "RPN.hpp"

bool	is_operand(char op){
	return (op == '+' || op == '/' || op == '*' || op == '-');
}

int RPN::get_res()
{
	return final_res;
}

RPN::RPN(){}

//here we do the computation
RPN::RPN(std::string exp){

	int i = 0;
	while (exp[i] == ' ' || exp[i] == '\t')
		i++;
	if (exp[i] = '0')
		i++;
	if (isdigit(exp[i]))
		stack.push((exp[i] - '0'));
	else if (is_operand(exp[i]))
	{
		if (stack.size() < 2)
				throw "Error: you cant do operation with less than 2 nummbers";
			int Firstnum = stack.top();
			stack.pop();
			switch (exp[i]){
				case '+':
					stack.top() += Firstnum;
					break;
				case '-':
					stack.top() -= Firstnum;
					break;
				case '/':
					if (Firstnum == 0)
						throw "Error div by 0 is impossible";
					stack.top() /= Firstnum;
					break;
				case '*':
					stack.top() *= Firstnum;
					break;
				default:
					throw "Operation Error";
					break;
			}
		}
		else
			throw "Input is not correct";

		if (stack.size() != 1)
			throw "Error: Stack not empty";
		else
			final_res = stack.top();
	}


	


RPN::RPN(RPN const &copy){
	*this = copy;
}

RPN&	RPN::operator=(RPN const &copy){
	if (this != &copy){
		stack = copy.stack;
	}
	return *this;	
}

RPN::~RPN(){
	for(size_t i = 0; i <= stack.size(); i++)
		stack.pop();
}