#include <iostream>
#include "State.hpp"

int main()
{
    std::cout << "hello, world!" << std::endl;
    State::Instance().Start();
    return 0;
}