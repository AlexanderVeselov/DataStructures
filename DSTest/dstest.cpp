#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    ds::Vector<int> vector;
    for (int i = 0; i < 10; ++i)
    {
        vector.push_back(rand() % 1000);
    }

    for (auto it = vector.begin(); it != vector.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    //std::vector<int> std_vector;
    //std_vector.push_back(333222);
    //std::vector<int>::iterator end = std_vector.end();
    //std::vector<int>::iterator it = end - 1;
    //std::cout << *it << std::endl;

    return 0;
}
