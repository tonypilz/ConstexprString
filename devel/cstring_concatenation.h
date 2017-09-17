#pragma once


namespace detail {


template<int n>
using char_array = char[n];


template<int n>
using const_char_array_ref = const char(&)[n];


template<int N, int M>
struct CStringSize {
    static constexpr int value = N + M -1;
};


template<int Size>
struct CString{

    static constexpr int size = Size;

    char_array<size> str = {};

    template<int N, int M>
    constexpr CString(const_char_array_ref<N> s1,const_char_array_ref<M> s2){

        static_assert(size == CStringSize<N,M>::value, "string size mismatch, use CStringType to compute actual size of CString");

        constexpr auto n = N-1; //-1 for ommitting '\0' on the first string

        for(int i=0;i<n;++i) str[i] = s1[i];
        for(int i=0;i<M;++i) str[i+n] = s2[i];
    }

    constexpr operator const_char_array_ref<size>() const{ return str; }

};


template<int N, int M>
using CStringType = CString<CStringSize<N,M>::value>;


template<int N>
constexpr auto makeCString(detail::const_char_array_ref<N> s) {
    return CStringType<N,1>(s,"");
}


}




// *** concatenation functions ***


// base cases with 2 args

template<int N, int M>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::const_char_array_ref<M> s2) {
    return detail::CStringType<N,M>(s1,s2);
}

template<int N, int M>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::CString<M> const& s2) {
    return concatenate(s1.str,s2.str);
}


template<int N, int M>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2) {
    return concatenate(s1.str,s2);
}

template<int N, int M>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::CString<M> const& s2) {
    return concatenate(s1,s2.str);
}


// cases with 3 args

template<int N, int M, int P>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::const_char_array_ref<M> s2,  detail::const_char_array_ref<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}

template<int N, int M, int P>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::CString<M> const& s2,        detail::const_char_array_ref<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}


template<int N, int M, int P>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2,  detail::const_char_array_ref<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}

template<int N, int M, int P>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::CString<M> const& s2,        detail::const_char_array_ref<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}



template<int N, int M, int P>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::const_char_array_ref<M> s2,  detail::CString<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}

template<int N, int M, int P>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::CString<M> const& s2,        detail::CString<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}


template<int N, int M, int P>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2,  detail::CString<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}

template<int N, int M, int P>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::CString<M> const& s2,        detail::CString<P> s3) {
    return concatenate(concatenate(s1,s2),s3);
}



// cases with more than 3 args of type CString (note that const_char_array_ref cannot be used due to decay to const char* in variadic template)

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::CString<M> const& s2,        detail::CString<P> s3,               TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}


template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2,  detail::CString<P> s3,               TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::CString<M> const& s2,        detail::CString<P> s3,               TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::const_char_array_ref<M> s2,  detail::CString<P> s3,               TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}


template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::CString<M> const& s2,        detail::const_char_array_ref<P> s3,  TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::CString<N> const& s1,         detail::const_char_array_ref<M> s2,  detail::const_char_array_ref<P> s3,  TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::CString<M> const& s2,        detail::const_char_array_ref<P> s3,  TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}

template<int N, int M, int P, typename... TCStrings>
constexpr auto concatenate( detail::const_char_array_ref<N> s1,   detail::const_char_array_ref<M> s2,  detail::const_char_array_ref<P> s3,  TCStrings const&... other) {
    return concatenate(concatenate(s1,s2,s3),other...);
}




