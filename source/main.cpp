#include <iostream>

#include "LinkedList.hpp"

int main() {
    
    LinkedList<int> list = {1, 2, 3, 4, 5};

    std::cout << list.begin() << ", " << list.end() << ", " << list.length() << std::endl;

    return 0;
}