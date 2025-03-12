/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:41:11 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/12 15:41:27 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i * 10);
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 55);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	std::list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i * 3);
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << "List error: " << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 7);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << "List error: " << e.what() << std::endl;
	}

	return 0;
}
