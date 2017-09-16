//#pragma once




//template<char... T>
//struct as_array{
//    static constexpr char str[sizeof...(T) + 1] = {T..., '\0'};
//};


//template<char... T>
//struct List{

//    template<char i>
//    using append = List<T...,i>;

//    template<template<char...> class S>
//    using makeType = S<T...>;

//};

//template<typename charlist, char i>
//struct find_char;

//template<typename charlist, char s>
//struct digest{

//    using charlist_s = typename charlist::template append<s>;

//    static constexpr const char* toSeqA(const char* cseq){
//        //static_assert(*cseq==s,"");
//        return find_char<charlist_s,char(0)>::toSeqA(cseq+1); //find next char
//    }

//};

//template<typename charlist>
//struct digest<charlist,char(0)>{

//    static constexpr const char* toSeqA(const char* cseq){
//        //static_assert(*cseq==char(0),"");
//        return charlist::template makeType<as_array>::str;
//    }
//};

//template<typename charlist, char i>
//struct find_char{

//    static constexpr const char* toSeqA(const char* cseq){
//        return i==*cseq ? digest<charlist,i>::toSeqA(cseq) : find_char<charlist,i+1>::toSeqA(cseq);
//    }

//};

//    template<typename charlist>
//    struct find_char<charlist,char(255)>{

//        static constexpr const char* toSeqA(const char* cseq){
//            return digest<charlist,char(255)>::toSeqA(cseq);
//        }
//    };

//static_assert(find_char<List<>,char(0)>::toSeqA("1")!=nullptr,"");







//template<typename S, typename U, typename... T>
//struct Hlp{

//    using Res = Hlp<decltype(concatenate<S,U>()),T...>;

//    constexpr auto con(S s, U u, T...t) -> decltype(Hlp<decltype(concatenate(s,u)),T...>::con(concatenate(s,u),t...)){
//        return Hlp<decltype(concatenate(s,u)),T...>::con(concatenate(s,u),t...);
//    }
//};

//template<typename S, typename U>
//struct Hlp<S,U>{

//    constexpr auto con(S s, U u) -> decltype(concatenate(s,u)){
//        return concatenate(s,u);
//    }
//};

//template<typename... T>
//constexpr auto concatenate1(T... s){
//    return Hlp<T...>::con(s...);
//}



//template<int s1_size, int s2_size, typename ... T>
//constexpr auto concatenate(
//        const char(&s1)[s1_size],
//        const char(&s2)[s2_size],
//        T... args ) -> decltype(concatenate(Concatenator<s1_size-1,s2_size-1, CharList<>>::concatenate(s1,s2),args...)) {
//    return concatenate(Concatenator<s1_size-1,s2_size-1, CharList<>>::concatenate(s1,s2),args...);
//}


template<int size>
struct ConstCharRef{
    typedef const char(&type)[size];
};

