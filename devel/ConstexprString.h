#pragma once

#include <array>


// char als template

// compiler explorer checken

// add tests für wchart

namespace ces { //ConstexprString

using Char = char;
using Size = int;

template<Size n>
using char_array = Char[n];

template<Size n>
using const_char_array_ref = const Char(&)[n]; //zu nem eigenen typ machen => in den implizit gecastet wird , der ConstexprStringView;


using ConstexprString_iterator = Char*;
using ConstexprString_const_iterator = const Char*;

template<Size capacity>
class ConstexprString{

    template<Size> friend class ConstexprString;

public:


    using Classtype = ConstexprString<capacity>;
    static constexpr Size StorageArraySize = capacity+1;
    using StorageArray = char_array<StorageArraySize>;  // the + 1 asserts '\0' terminatability

    using iterator = ConstexprString_iterator;
    using const_iterator = ConstexprString_const_iterator;

    static_assert(capacity>=0,"");

    constexpr ConstexprString() : _length(0) { updateNullTerminator();}

    template<Size N>
    constexpr ConstexprString(ConstexprString<N> const& other) : _length(other._length){
        static_assert(N <= capacity, "invalid size");
        for(Size i=0;i<other._length;++i) str[i] = other.str[i];
        updateNullTerminator();
    }

    template<Size N>
    constexpr ConstexprString(const_char_array_ref<N> s) : _length(N-1){
        static_assert(N<=capacity+1,"invalid size");
        for(Size i=0;i<_length;++i) str[i] = s[i];
        updateNullTerminator();
    }

    template<Size N>
    constexpr Classtype operator=(ConstexprString<N> const& other) {
        static_assert(N <= capacity, "invalid size");
        _length = other._length;
        for(Size i=0;i<other._length;++i) str[i] = other.str[i];
        updateNullTerminator();
    }

    template<Size N>
    constexpr Classtype operator=(const_char_array_ref<N> s) {
        static_assert(N <= capacity+1, "invalid size");
        _length = N-1;
        for(Size i=0;i<_length;++i) str[i] = s[i];
        updateNullTerminator();
    }

    constexpr void resize (Size n){
        _length = n;
        updateNullTerminator();
    }


    constexpr Char& operator[](Size idx){ return str[idx]; }
    constexpr Char const& operator[](Size idx) const{ return str[idx]; }

    using const_char_array_ref_equivalent = const_char_array_ref<StorageArraySize>;

    constexpr operator const_char_array_ref_equivalent() const{ return str; } //decay into array ref for printing

    constexpr const Char* c_str() const{ return static_cast<const Char*>(str); }
    constexpr Size length() const { return _length;}
    constexpr Size size() const { return _length;}
    constexpr bool empty() const { return _length==0;}

    constexpr iterator begin(){ return &str[0];}
    constexpr iterator end(){ return &str[_length];}
    constexpr const_iterator begin() const{ return &str[0];}
    constexpr const_iterator end() const{ return &str[_length];}

private:

    constexpr void updateNullTerminator(){  str[_length] = '\0'; }

    Size _length;
    StorageArray str = {};
};


template<Size N>
constexpr ConstexprString<N-1> make_string(const_char_array_ref<N> s) {
    return {s};
}


template<typename T>
constexpr Size length( T const& t) {
    return t.length();
}

template<Size M>
constexpr Size length(const_char_array_ref<M>) {
    return M-1;
}

template<Size N, typename T>
constexpr ConstexprString<N> & append( ConstexprString<N> & s1,         T const& s2) {

    const auto start =length(s1);

    s1.resize(length(s1) + length(s2));

    for(Size i=0;i<length(s2);++i) //0 termination already set
        s1[start + i] = s2[i];

    return s1;
}



template<Size N, Size M>
constexpr auto conditional(bool condition, const_char_array_ref<N> s1,   ConstexprString<M> const& s2) {
    constexpr auto OutSize = length(s1) > length(s2) ? length(s1) : length(s2);
    return condition ?
                ConstexprString<OutSize>(s1) :
                ConstexprString<OutSize>(s2) ;
}


template<Size N, Size M>
constexpr bool operator==( ConstexprString<N> const& s1,        const_char_array_ref<M> s2) {

    if(s1.length()+1 != M) return false; //length does not include '\0'

    for(Size i=0;i<s1.length();++i)
        if (s1[i]!=s2[i]) return false;

    return true;
}


template<Size N, Size M>
constexpr auto operator+( ConstexprString<N> const& s1,         ConstexprString<M> const& s2) {
    auto r = ConstexprString<N+M>(s1);
    return append(r,s2);
}

template<Size N, Size M>
constexpr auto operator+( ConstexprString<N> const& s1,         const_char_array_ref<M> s2) {
    auto r = ConstexprString<N+M-1>(s1);
    return append(r,s2);
}

template<Size N, Size M>
constexpr auto operator+( const_char_array_ref<N> s1,   ConstexprString<M> const& s2) {
    auto r = ConstexprString<N+M-1>(s1);
    return append(r,s2);
}





} //ns





