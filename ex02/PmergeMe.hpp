/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:43 by mklimina            #+#    #+#             */
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
		static void binary_(T& container, size_t element) {

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

            //At each level of recursion,
            // we're assigning container = biggests;.
            // Since container is passed by reference (T& container),
            // any modifications to it, including assignments, affect the original
            // container passed to the function.
            sort_pairs(container);

            T biggests;
            for (size_t i = 1; i < container.size(); i += 2)
                biggests.push_back(container[i]);

            sort(biggests);

            for (size_t i = 0; i < container.size(); i += 2)
                binary(biggests, container[i]);

            container = biggests;
		}

};

#endif