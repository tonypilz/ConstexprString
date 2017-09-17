# CompileTimeCStringConcatenation
A single header file, c++11 library with no dependencies for concatenating c-strings at compile-time.

## Motivation
On the crusade against preprocessor macros one regularly comes across c-string definitions like

```cpp
#define TMP_DIR "/tmp"
#define TMP_FILE_1 TMP_DIR "/file1"
#define TMP_FILE_2 TMP_DIR "/file2"
``` 

In the example above one can see that c-string definitions have the nice property of forming new c-strings if they stand
next to each other which usually prevents us from replacing the macro definitions by constexpr eg

```cpp
constexpr auto TMP_DIR  = "/tmp"; //ok
constexpr auto TMP_FILE_1 = TMP_DIR "/file1"; //compile error
``` 

To still avoid the macros one needs a method to concatenate c-strings at compile time which is provided
by this library. The library defines the function ```concatenate()``` alowing us to avoid using the evil macros:


```cpp
constexpr char TMP_DIR[] = "/tmp";
constexpr auto TMP_FILE_1 = concatenate(TMP_DIR,"/file1");
constexpr auto TMP_FILE_2 = concatenate(TMP_DIR,"/file2");
``` 

## Working Example

```cpp
#include <iostream>
#include "c_string_concatenate.h"

constexpr char foo[] = "foo";
constexpr char bar[] = "bar";
constexpr auto foobar = concatenate(foo, bar);

int main()
{
    std::cout << foobar << std::endl; //prints "foobar"
    return 0;
}
``` 

## Known Issues / Current State

![#f03c15](https://placehold.it/15/f03c15/000000?text=+) The library is currently very limited due to the combinatorial explosion coming with the present implementation. So compiling with longer c-strings or more than a couple of chars wont finish! (The foo bar example is at the limit with a mingw32 compiler due to memory exhaustion). There no known solution to this problem at the moment - sugestions are welcome ('if constexpr' doesnt work).
