#include "vector.hpp"
#include "list.hpp"
#include <list>
#include <iostream>

int main()
{
    ds::List<int> list;
    for (int i = 0; i < 10; ++i)
    {
        list.push_back(rand() % 1000);
    }

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
