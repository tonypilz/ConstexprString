#include <iostream>
#include "c_string_concatenate.h"
#include "main_example.cpp"



constexpr char s1[] = "f";
constexpr char s2[] = "b";

constexpr decltype(concatenate(s1,s2)) xt = concatenate("f",s2);
constexpr decltype(concatenate("f",xt,"f")) xta = concatenate("b",xt,"b");

//constexpr decltype(concatenate(x,t)) abxt = concatenate("a","t","x");

constexpr auto textconcatenated1 = concatenate(s2,xt);

void echoIfConditions(){
    for(int i=0;i<256;++i){
        std::cout<< "if (*s1==" << i << ") return Next<" << i << ">::concatenate(s1+1,s2);" << std::endl;
    }
}
void echoIfConditionsC(){
    for(int i=0;i<256;++i){
        std::cout<< "if (*s1=='" << (char)i << "') return Next<'" << (char)i << "'>::concatenate(s1+1,s2);" << std::endl;
    }
}




int main()
{
    main_();
    return 0;

    //echoIfConditionsC();
    std::cout << "Hello World!" << xta << "  " << std::endl;
    return 0;
}
