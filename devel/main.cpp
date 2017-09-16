#include <iostream>
#include "c_string_concatenate.h"
#include "main_example.cpp"


//operator+ auf const char(&)[] überladen

constexpr char x[] = "h";
constexpr char t[] = "d";

constexpr decltype(concatenate(x,t)) xt = concatenate("d",t);
constexpr decltype(concatenate("d",xt,"d")) xta = concatenate("d",xt,"d");

//constexpr decltype(concatenate(x,t)) abxt = concatenate("a","t","x");

constexpr auto textconcatenated1 = concatenate(t,xt);

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
    std::cout << "Hello World!" << xta << std::endl;
    return 0;
}
