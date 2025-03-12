/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:48:29 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/12 15:48:36 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _max_size(N) {}

Span::Span(const Span & other) : _numbers(other._numbers), _max_size(other._max_size) {}

Span & Span::operator=(const Span & other) {
    if (this != &other) {
        _max_size = other._max_size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _max_size)
        throw std::runtime_error("Span is full, cannot add more numbers");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    // コピーを作成してソート
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; i++) {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}

const std::vector<int>& Span::getNumbers() const {
    return _numbers;
}
