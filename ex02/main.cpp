/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vegret <victor.egret.pro@gmail.com>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/16 15:03:21 by vegret			#+#	#+#			 */
/*   Updated: 2023/11/23 19:02:51 by vegret		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <limits>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

typedef unsigned long long u_ll;

static u_int32_t get_num(std::string str) {
	if (str.size() > 10)
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	size_t i = 0;

	while (i < str.size()) {
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: " + str + " is not a valid positive integer");
		i++;
	}

	u_int64_t res = std::strtoul(str.c_str(), NULL, 10);

	if (res > std::numeric_limits<u_int32_t>::max())
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	return static_cast<u_int32_t>(res);
}

// static u_ll current_time_micros() {
// 	struct timeval tv;

// 	gettimeofday(&tv, NULL);
// 	return tv.tv_sec * 1000000UL + tv.tv_usec;
// }

int main(int argc, char** argv) {

	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe <space separated numbers>" << std::endl;
		return 1;
	}

	std::deque<u_int32_t> deque;
	std::vector<u_int32_t> vector;

	try {
		for (int i = 1 ; i < argc ; i++) {
			u_int32_t parsed = get_num(argv[i]);

			deque.push_back(parsed);
			vector.push_back(parsed);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	PmergeMe::sort(vector);

	return 0;
}
