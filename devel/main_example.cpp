#include <iostream>
#include "cstring_concatenation.h"

constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = make_string(foo) + " " + bar;

int main_()
{

    auto copy = foobar;



    std::cout << copy << std::endl; //prints "foo bar"
    return 0;
}

