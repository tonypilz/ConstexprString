# ConstexprString
The library consists of a small string class which allows for compile time string manipulations like eg concatenation. 

The library
 - comes in a single header file, is 
 - macro-free, 
 - depency-free,
 - tested under GCC 7.2.0
 - Compiles under GCC 5.1-8.1, ICC 17-18, Clang 3.5-6.0
 - The abstraction will be fully optimized out at optimization Level 2 (-O2)

## Motivation
On the day to day work one often comes across definitions like

```cpp
#define TMP_DIR "/tmp"
#define TMP_FILE_1 TMP_DIR "/file1"
#define TMP_FILE_2 TMP_DIR "/file2"
``` 

where macro based string definitions allow the user to combine c-strings to form new ones. Since macros are best to be avoided one needs a comparable mechanism on the c++ language level.

 This library provides such a mechanism which allows us to rewrite the example above without macros: 

```cpp
constexpr auto TMP_DIR = ces::make_string("/tmp");
constexpr auto TMP_FILE_1 = TMP_DIR + "/file1";
constexpr auto TMP_FILE_2 = TMP_DIR + "/file2";
``` 

## Working Example

```cpp
#include "ConstexprString.h"


constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = ces::make_string(foo) + " " + bar;

int main_()
{
    std::cout << foobar << std::endl; //prints "foo bar"
    return 0;
}
``` 

Try it out on [ideone](https://ideone.com/ynF07x).

### How the example works

The call to function `ces::make_string(foo)` returns an instance of `ces::ConstexprString` which contains a copy of the argument `foo` and for which an appropriate `operator+()` is provided for the subequent calls `+" " + bar`.

# Note

This library provides only a limited set of compile time string operations. For a more complete set one can use other compile-time libraries like [sprout](https://github.com/bolero-MURAKAMI/Sprout). 