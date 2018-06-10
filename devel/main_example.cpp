#include <iostream>
#include "ConstexprString.h"


constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = ces::make_string(foo) + " " + bar;

int main_()
{

    const auto copy = foobar;

    for(auto const& c:copy)
        std::cout<<c;



    std::cout << copy << std::endl; //prints "foo bar"
    return 0;
}

