/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:22 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/12 15:57:53 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Span sp2(10000);
		std::vector<int> numbers;
		for (int i = 0; i < 10000; i++) {
			numbers.push_back(i);
		}
		sp2.addNumbers(numbers.begin(), numbers.end());
		std::cout << "\nFor sp2:" << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception in sp2: " << e.what() << std::endl;
	}

	return 0;
}
