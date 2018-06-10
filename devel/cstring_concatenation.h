#pragma once

#include <array>


// char als template

//deducation guides ersetzt die make funktion

// compiler explorer checken

// leerer ctor, assignment , iterators begin end

// für ternäre operatoren brauchen wir assign von kleinerem string


//size sollte zu capacity => neue size variable  => make fixed => das wird zu kompliziert, der nutzen ist gering?

// datei umbenennen


namespace detail {

using Char = char;


template<int n>
using char_array = Char[n];

template<int n>
using const_char_array_ref = const Char(&)[n]; //zu nem eigenen typ machen


template<int N, int M>
struct ConstexprStringSize {
    static constexpr int value = N + M - 1; //-1 for ommitting '\0' on the first string
};



//NtArray
template<int Size>
class ConstexprString{

public:

    static_assert(Size>0,""); //allways 0 terminated

    static constexpr int size = Size; //length including '\0'


    template<int N, int M>
    constexpr ConstexprString(ConstexprString<N> const& s1,ConstexprString<M> const& s2){

        static_assert(size == ConstexprStringSize<N,M>::value, "string size mismatch, use ConstexprStringType to compute actual size of ConstexprString");

        constexpr auto n = N-1; //-1 for ommitting '\0' on the first string

        for(int i=0;i<n;++i) str[i] = s1[i];
        for(int i=0;i<M;++i) str[i+n] = s2[i];
    }

    template<int N>
    constexpr ConstexprString(const_char_array_ref<N> s){
        static_assert(N==Size,"");
        for(int i=0;i<N;++i) str[i] = s[i];
    }

    constexpr Char& operator[](int idx){ return str[idx]; }
    constexpr Char const& operator[](int idx) const{ return str[idx]; }


    constexpr operator const_char_array_ref<size>() const{ return str; }

    constexpr const Char* c_str() const{ return static_cast<const Char*>(str); }
    constexpr int length() const { return size-1;}
    constexpr bool empty() const { return size<=1;}

private:

    char_array<size> str = {}; // '\0' terminated

};


template<int N, int M>
using ConcatenatedString = ConstexprString<ConstexprStringSize<N,M>::value>; //type deduction guide


}

template<int N>
constexpr detail::ConstexprString<N> make_string(detail::const_char_array_ref<N> s) {
    return {s};
}


template<int N, int M>
constexpr auto operator+( detail::ConstexprString<N> const& s1,         detail::ConstexprString<M> const& s2) {
    return detail::ConcatenatedString<N,M>(s1,s2);
}

template<int N, int M>
constexpr auto operator+( detail::ConstexprString<N> const& s1,         detail::const_char_array_ref<M> s2) {
    return detail::ConcatenatedString<N,M>(s1,detail::ConstexprString<M>{s2});
}

template<int N, int M>
constexpr auto operator+( detail::const_char_array_ref<N> s1,   detail::ConstexprString<M> const& s2) {
    return detail::ConcatenatedString<N,M>(detail::ConstexprString<N>{s1},s2);
}


template<int N, int M>
constexpr bool operator==( detail::ConstexprString<N> const& s1,         detail::const_char_array_ref<M> s2) {
    static_assert(N==M,"");

    for(int i=0;i<N;++i)
        if (s1[i]!=s2[i]) return false;

    return true;

}


//template<int N, int M>
//constexpr auto conditional(bool condition, detail::const_char_array_ref<N> s1,   detail::ConstexprString<M> const& s2) {
//    return detail::ConcatenatedString<N,M>(detail::ConstexprString<N>{s1},s2); //return max
//}



