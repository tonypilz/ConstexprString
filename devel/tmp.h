#pragma once



//// cases with more than 2 args of type ConstexprString (note that array ref cannot be used due to decay to const char* )

//template<template <int> class S1, template<int> class S2, int N, int M, typename... Other>
//constexpr auto concatenate(S1<N> const& s1, S2<M> const& s2, Other... other) {
//    return concatenate( concatenate(s1,s2),other...);
//}
//template<template <int> class S1, int N, int M, typename... Other>
//constexpr auto concatenate(S1<N> const& s1, detail::const_char_array_ref<M> s2, Other... other) {
//    return concatenate( concatenate(s1,s2),other...);
//}

//template<template<int> class S2, int N, int M, typename... Other>
//constexpr auto concatenate(detail::const_char_array_ref<N> s1, S2<M> const& s2, Other... other) {
//    return concatenate( detail::ConstexprStringType<N,M>(s1,s2),other...);
//}

//template<int N, int M, typename... Other>
//constexpr auto concatenate(detail::const_char_array_ref<N> s1,detail::const_char_array_ref<M> s2, Other... other) { //decay to const char* prevents us from creating more elegant
//    return concatenate( concatenate(s1,s2),other...);
//}


//constexpr auto foobar = concatenate(concatenate(foo, " ", bar),"xx");















