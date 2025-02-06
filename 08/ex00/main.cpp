#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testEasyFind() {
    std::vector<float> vec;
    std::list<int> lst;
    std::deque<int> deq;

    // Test verileri ekleyelim
    for (int i = -1; i <= 5; ++i) {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
    }

    int searchValue = 3; // Aranacak değer
    int notFoundValue = 10; // Bulunamayacak değer

    try {
        std::cout << "Searching in vector: ";
        std::vector<float>::const_iterator it = easyfind(vec, -1);
        std::cout << "Found " << *it << " at position "  << std::endl;
    } catch (const std::exception& e) {
        
        std::cout << e.what() << std::endl;
    }

}

int main() {
    testEasyFind();
    return 0;
}
