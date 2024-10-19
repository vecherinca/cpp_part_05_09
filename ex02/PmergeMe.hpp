/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:43 by vegret            #+#    #+#             */
/*   Updated: 2024/10/19 17:55:43 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <deque>
# include <vector>
# include <stdlib.h>
# include <iostream>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);

		template <typename T>
		static void sort_pairs(T& container) {
			for (size_t i = 0; i < container.size() - 1; i += 2)
				if (container[i] > container[i + 1])
					std::swap(container[i], container[i + 1]);
		}

		template <typename T>
		static void binary_insert(T& container, size_t element) {

			// 20 79 31 77 72 83 33 59 56 66
			int left = 0;
			int right = container.size() - 1;
			int mid;

			while (left <= right) {
				mid = left + (right - left) / 2;
				if (element < container[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}

			container.insert(container.begin() + left, element);
		}

	public:
		~PmergeMe();

		template <typename T>
		static void sort(T& container) {

			if (container.size() < 2)
				return;
			sort_pairs(container);
			
			T biggests;
			for (size_t i = 1; i < container.size(); i += 2)
				biggests.push_back(container[i]);
		
			sort(biggests);

			std::cout << "biggests before binary" << std::endl;
			for (size_t i = 0 ; i < biggests.size(); i ++)
				std::cout << biggests[i] << " " ;
			std::cout << std::endl;
			std::cout << "end biggests before binary" << std::endl;

			std::cout << "containers before binary" << std::endl;
			for (size_t i = 0 ; i < container.size(); i ++)
				std::cout << container[i] << " " ;
			std::cout << std::endl;
			std::cout << "end containers before binary" << std::endl;
			
			for (size_t i = 0; i < biggests.size(); i += 2)
			{
				binary_insert(biggests, container[i]);
			}
			std::cout << "biggests after binary" << std::endl;
			for (size_t i = 0 ; i < biggests.size(); i ++)
				std::cout << biggests[i] << " " ;
			std::cout << std::endl;
			std::cout << "end biggests after binary" << std::endl << std::endl;
			// std::cout << "containers before binary" << std::endl;
			// for (size_t i = 0 ; i < biggests.size(); i ++)
			// 	std::cout << biggests[i] << " " ;
			// std::cout << std::endl;
			// std::cout << "end containers before binary" << std::endl;
			
			container = biggests;
		}

};

#endif