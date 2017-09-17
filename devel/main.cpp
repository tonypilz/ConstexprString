#include <iostream>
#include "cstring_concatenation.h"
#include "main_example.cpp"

#include "tests.h"

constexpr auto x = concatenate("xx","yy");
constexpr auto y = concatenate(x,"zz");
constexpr auto z = concatenate(x,y);

constexpr auto t = concatenate("bla","bla",x,x,x,x,x,x,x);

int main()
{
    test();
    main_();
    return 0;


    std::cout << "Hello World!" << t << "  " << std::endl;
    return 0;
}
