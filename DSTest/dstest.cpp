#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    ds::Vector<int> vector(34, 222);
    std::cout << vector[32] << std::endl;
    std::cout << vector.size() << std::endl;
    std::cout << vector.capacity() << std::endl;

    std::vector<int> std_vector(333, 333);
    std::cout << std_vector.size() << std::endl;
    std::cout << std_vector.capacity() << std::endl;
    std_vector.reserve(100);
    std::cout << std_vector.capacity() << std::endl;

    return 0;
}
