
# include <iostream> 
# include <stack>
# include <iterator>
# include <algorithm>

class RPN{
	private:
		std::stack<int> stack;
		int final_res;
	public:
		RPN();
		int get_res();
		RPN(std::string input);
		RPN(RPN const &copy);
		RPN&	operator=(RPN const &copy);
		~RPN();
};