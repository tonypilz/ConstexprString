#pragma once

#include "cstring_concatenation.h"

#include <cassert>
#include <cstring>


constexpr char cref1[] = "abcd1";
constexpr char cref2[] = "xabcd2";
constexpr auto cstring1 = detail::makeCString("efg1");
constexpr auto cstring2 = detail::makeCString("yyyefg2");
constexpr char expected_cstring1[]    = "efg1";

constexpr auto cref1_cstring1    = concatenate(cref1,cstring1);
constexpr auto cref1_cref2       = concatenate(cref1,cref2);
constexpr auto cstring1_cref1    = concatenate(cstring1,cref1);
constexpr auto cstring1_cstring2 = concatenate(cstring1,cstring2);



constexpr char expected_cref1_cstring1[]    = "abcd1efg1";
constexpr char expected_cref1_cref2 []      = "abcd1xabcd2";
constexpr char expected_cstring1_cref1[]    = "efg1abcd1";
constexpr char expected_cstring1_cstring2[] = "efg1yyyefg2";


template<int N, int M>
bool isEqual( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2) {
    static_assert(N==M,"");
    return strcmp(s1.str,s2)==0;
}



void test(){

    assert(isEqual(detail::makeCString(""),""));
    assert(isEqual(detail::makeCString("ab"),"ab"));

    assert(isEqual(concatenate(cref1,""),cref1));
    assert(isEqual(concatenate("",""),""));
    assert(isEqual(concatenate("",cref1),cref1));

    assert(isEqual(cref1_cstring1,expected_cref1_cstring1));
    assert(isEqual(cref1_cref2,expected_cref1_cref2));
    assert(isEqual(cstring1_cref1,expected_cstring1_cref1));
    assert(isEqual(cstring1_cstring2,expected_cstring1_cstring2));

    //3er

    assert(isEqual(concatenate("","",""),""));

    assert(isEqual(concatenate("",cref1,cref2),expected_cref1_cref2));
    assert(isEqual(concatenate(cref1,"",cref2),expected_cref1_cref2));
    assert(isEqual(concatenate(cref1,cref2,""),expected_cref1_cref2));

    assert(isEqual(concatenate(cref1,"",""),cref1));
    assert(isEqual(concatenate("",cref1,""),cref1));
    assert(isEqual(concatenate("","",cref1),cref1));


    assert(isEqual(concatenate("",cref1,cstring1),expected_cref1_cstring1));
    assert(isEqual(concatenate(cref1,"",cstring1),expected_cref1_cstring1));
    assert(isEqual(concatenate(cref1,cstring1,""),expected_cref1_cstring1));

    assert(isEqual(concatenate(cstring1,"",""),expected_cstring1));
    assert(isEqual(concatenate("",cstring1,""),expected_cstring1));
    assert(isEqual(concatenate("","",cstring1),expected_cstring1));

    assert(isEqual(concatenate("",cstring1,cref1),expected_cstring1_cref1));
    assert(isEqual(concatenate(cstring1,"",cref1),expected_cstring1_cref1));
    assert(isEqual(concatenate(cstring1,cref1,""),expected_cstring1_cref1));

    assert(isEqual(concatenate(cstring1,cref1,"foo",cstring1,cstring1,cstring1),"efg1abcd1fooefg1efg1efg1"));
}

