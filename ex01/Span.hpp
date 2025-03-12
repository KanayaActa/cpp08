/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:45:56 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/12 15:47:42 by miwasa           ###   ########.fr       */
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
    // コンストラクタ：最大要素数を指定
    Span(unsigned int N);

    // コピーコンストラクタ／代入演算子／デストラクタ
    Span(const Span & other);
    Span & operator=(const Span & other);
    ~Span();

    // 単一の数値を追加する
    void addNumber(int number);

    // 範囲（イテレータ）で複数の数値を一括追加する
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    // 最短のスパン（隣接要素の最小差）を返す
    int shortestSpan() const;

    // 最長のスパン（最大値と最小値の差）を返す
    int longestSpan() const;

    // オプション: 内部データを取得するための getter
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

