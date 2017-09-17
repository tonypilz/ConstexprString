# CompileTimeCStringConcatenation
A small single header file, macro-free, tested c++14 library without dependencies for concatenating c-strings at compile-time.

 - tested under MinGW32 GCC 5.4.
 - Compiles under GCC 5.1-7.2, ICC 17, Clang 3.5-3.9 (higher clang compiler complain!)
 - The abstraction (CString) will be fully optimized out starting at optimization Level 1 (-O1)

## Motivation
On the crusade against preprocessor macros one regularly comes across c-string definitions like

```cpp
#define TMP_DIR "/tmp"
#define TMP_FILE_1 TMP_DIR "/file1"
#define TMP_FILE_2 TMP_DIR "/file2"
``` 

In the example above one can see that c-string definitions have the nice property of forming new c-strings if they stand
next to each other which usually prevents people from replacing the macro definitions by constexpr ie

```cpp
constexpr auto TMP_DIR  = "/tmp"; //ok
constexpr auto TMP_FILE_1 = TMP_DIR "/file1"; //compile error
``` 

To still avoid these macros one needs a method to concatenate c-strings at compile time which is provided
by this library. The library defines the function ```concatenate()``` which can be used to replace the macros:

```cpp
constexpr char TMP_DIR[] = "/tmp";
constexpr auto TMP_FILE_1 = concatenate(TMP_DIR,"/file1");
constexpr auto TMP_FILE_2 = concatenate(TMP_DIR,"/file2");
``` 

## Working Example

```cpp
#include <iostream>
#include "cstring_concatenation.h"

constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = concatenate(foo, " ", bar);

int main()
{
    std::cout << foobar << std::endl; //prints "foo bar"
    return 0;
}
``` 

Try it out on [ideone](https://ideone.com/r18SX2)).

## Known Issues

Due to c++ language limitations a general definition of ```concatenate()``` which allows an arbitrary number of c-string arguments ie
```cpp
constexpr auto str = concatenate("a","b","c","d","e","f","g",...);
``` 
cannot be provided. Thus the library implementation will alyways be restricted. The current implementation allows for 3 leading c-strings and an unlimited amount of concatenation results. To concatenate more c-string use the following workarounds:

```cpp
constexpr auto str = concatenate("a","b","c",concatenate("d","e","f",concatenate("g",...)));
constexpr auto str = concatenate("a","b","c",detail::makeCString("d"), detail::makeCString("e"),...);
``` 

