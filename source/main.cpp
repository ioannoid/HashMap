#include <iostream>

#include "LinkedList.hpp"

int main() {
    
    LinkedList<int> list;
    list.append(20);
    list.append(50);
    list.append(40);
    list.insert(0, 50);

    std::cout << list.begin() << ", " << list.end() << std::endl;

    return 0;
}