#include <iostream>
#include "cstring_concatenation.h"

constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = concatenate(foo, " ", bar);

int main_()
{
    std::cout << foobar << std::endl; //prints "foo bar"
    return 0;
}

