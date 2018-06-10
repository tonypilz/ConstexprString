#include "ConstexprString.h"


constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = ces::make_string(foo) + " " + bar;


constexpr auto TMP_DIR = ces::make_string("/tmp");
constexpr auto TMP_FILE_1 = TMP_DIR + "/file1";
constexpr auto TMP_FILE_2 = TMP_DIR + "/file2";

int main_()
{
    std::cout << foobar << std::endl; //prints "foo bar"
    return 0;
}

