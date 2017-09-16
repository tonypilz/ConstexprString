#include <iostream>
#include "c_string_concatenate.h"

constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = concatenate(foo, bar);

int main_()
{
    std::cout << foobar << std::endl; //prints "foobar"
    return 0;
}

