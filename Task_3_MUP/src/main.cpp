#include <iostream>
#include "unique_ptr/Unique_ptr.hpp"

int main() {

    int* f = new int(1);
    Unique_ptr<int> g(f);
    std::cout << *g << std::endl;
    std::cout << *g.release() << std::endl;

    return 0;
} 