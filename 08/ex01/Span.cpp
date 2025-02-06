#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
Span::Span(unsigned int N) : _N(N){
}

Span::~Span(){
}

Span::Span(const Span& other){

    if (this != &other)
    {
        this->_N = other._N;
        this->_numbers = other._numbers; 
    }
}

void Span::addNumber(int num){

    if (_numbers.size() >= _N)
        throw std::out_of_range("error");
    _numbers.push_back(num);
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    while (begin != end) {
        if (_numbers.size() >= _N) {
            throw std::out_of_range("Error: Span is already full, cannot add more numbers.");
        }
        _numbers.push_back(*begin);
        ++begin;
    }
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough elements to find a span!");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];

    for (std::vector<int>::size_type i = 1; i < sortedNumbers.size() - 1; ++i) {
        int diff = sortedNumbers[i + 1] - sortedNumbers[i];
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}

int Span::longestSpan()const {
    if (_numbers.size() < 2)
        throw std::out_of_range("error");
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    int longestSpanInt = *maxIt - *minIt;
    return (longestSpanInt);
}
