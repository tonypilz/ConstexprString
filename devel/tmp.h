#pragma once


template<int size>
struct CStringRef {

    const char(&str)[size];

};

template<size_t N>
constexpr auto makeCStringRef(const char (&s)[N]) { return CStringRef<N>{s}; }

