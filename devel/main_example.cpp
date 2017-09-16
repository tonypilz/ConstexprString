#include <iostream>
#include "c_string_concatenate.h"

constexpr char foo[] = "f";
constexpr char bar[] = "b";
constexpr auto foobar = concatenate(foo, bar);

int main_()
{
    std::cout << foobar << std::endl;
    return 0;
}
