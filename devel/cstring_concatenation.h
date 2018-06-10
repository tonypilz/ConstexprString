#pragma once

#include <array>


// char als template

// deducation guides ersetzt die make funktion

// compiler explorer checken

// datei umbenennen

// eigene namespace

// iteratoren

// algos

// substr(s1, 4) + "foo"


namespace detail {

using Char = char;
using Size = int;

template<Size n>
using char_array = Char[n];

template<Size n>
using const_char_array_ref = const Char(&)[n]; //zu nem eigenen typ machen => in den implizit gecastet wird , der ConstexprStringView;


template<Size capacity>
class ConstexprString{

    template<Size> friend class ConstexprString;

public:


    using Classtype = ConstexprString<capacity>;
    static constexpr Size StorageArraySize = capacity+1;
    using StorageArray = char_array<StorageArraySize>;  // the + 1 asserts '\0' terminatability

    static_assert(capacity>=0,"");

    constexpr ConstexprString() : _length(0) { updateNullTerminator();}

    template<Size N>
    constexpr ConstexprString(ConstexprString<N> const& other) : _length(other._length){
        static_assert(N <= capacity, "invalid size");
        for(Size i=0;i<other._length;++i) str[i] = other.str[i]; //todo std copy
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
        for(Size i=0;i<other._length;++i) str[i] = other.str[i]; //todo std copy
        updateNullTerminator();
    }

    template<Size N>
    constexpr Classtype operator=(const_char_array_ref<N> s) {
        static_assert(N <= capacity+1, "invalid size");
        _length = N-1;
        for(Size i=0;i<_length;++i) str[i] = s[i]; //todo std copy
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

private:

    constexpr void updateNullTerminator(){  str[_length] = '\0'; }

    Size _length;

    StorageArray str = {};

};


} //namespace

template<detail::Size N>
constexpr detail::ConstexprString<N-1> make_string(detail::const_char_array_ref<N> s) {
    return {s};
}


template<typename T>
constexpr detail::Size length( T const& t) {
    return t.length();
}

template<detail::Size M>
constexpr detail::Size length(detail::const_char_array_ref<M>) {
    return M-1;
}

template<detail::Size N, typename T>
constexpr detail::ConstexprString<N> & append( detail::ConstexprString<N> & s1,         T const& s2) {

    const auto start =length(s1);

    s1.resize(length(s1) + length(s2));

    for(detail::Size i=0;i<length(s2);++i) //0 termination already set
        s1[start + i] = s2[i];

    return s1;
}


template<detail::Size N, detail::Size M>
constexpr auto operator+( detail::ConstexprString<N> const& s1,         detail::ConstexprString<M> const& s2) {
    auto r = detail::ConstexprString<N+M>(s1);
    return append(r,s2);
}

template<detail::Size N, detail::Size M>
constexpr auto operator+( detail::ConstexprString<N> const& s1,         detail::const_char_array_ref<M> s2) {
    auto r = detail::ConstexprString<N+M-1>(s1);
    return append(r,s2);
}

template<detail::Size N, detail::Size M>
constexpr auto operator+( detail::const_char_array_ref<N> s1,   detail::ConstexprString<M> const& s2) {
    auto r = detail::ConstexprString<N+M-1>(s1);
    return append(r,s2);
}


template<detail::Size N, detail::Size M>
constexpr bool operator==( detail::ConstexprString<N> const& s1,        detail::const_char_array_ref<M> s2) {

    if(s1.length()+1 != M) return false; //length does not include '\0'

    for(detail::Size i=0;i<s1.length();++i)
        if (s1[i]!=s2[i]) return false;

    return true;

}


template<detail::Size N, detail::Size M>
constexpr auto conditional(bool condition, detail::const_char_array_ref<N> s1,   detail::ConstexprString<M> const& s2) {
    constexpr auto OutSize = length(s1) > length(s2) ? length(s1) : length(s2);
    return condition ?
                detail::ConstexprString<OutSize>(s1) :
                detail::ConstexprString<OutSize>(s2) ;
}



