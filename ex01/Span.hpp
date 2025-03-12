/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:45:56 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/12 15:57:25 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span {
private:
	std::vector<int> _numbers;
	unsigned int _max_size;
public:
	Span(unsigned int N);
	Span(const Span & other);
	Span & operator=(const Span & other);
	~Span();

	void addNumber(int number);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
	int shortestSpan() const;
	int longestSpan() const;
	const std::vector<int>& getNumbers() const;
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	for (Iterator it = begin; it != end; ++it) {
		if (_numbers.size() >= _max_size)
			throw std::runtime_error("Span is full, cannot add more numbers from range");
		_numbers.push_back(*it);
	}
}

