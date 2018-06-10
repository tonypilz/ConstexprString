#pragma once

#include <iostream> //requried by 'operator<<()'

namespace ces { //ces is shorthand for ConstexprString

using Size = int;

template<Size n, typename Char>
using char_array = Char[n];

template<Size n, typename Char>
using const_char_array_ref = const Char(&)[n];

template<typename Char>
using ConstexprString_iterator = Char*;

template<typename Char>
using ConstexprString_const_iterator = const Char*;

template<Size capacity, typename Char>
class ConstexprString{

public:

    using Classtype = ConstexprString<capacity,Char>;
    static constexpr Size StorageArraySize = capacity+1;
    using StorageArray = char_array<StorageArraySize,Char>;  // the + 1 asserts '\0' terminatability

    using iterator = ConstexprString_iterator<Char>;
    using const_iterator = ConstexprString_const_iterator<Char>;

    static_assert(capacity>=0,"");

    constexpr ConstexprString() : _length(0) { updateNullTerminator();}

    template<Size N>
    constexpr ConstexprString(ConstexprString<N, Char> const& other) : _length(other._length){
        static_assert(N <= capacity, "invalid size");
        for(Size i=0;i<other._length;++i) str[i] = other.str[i];
        updateNullTerminator();
    }

    template<Size N>
    constexpr ConstexprString(const_char_array_ref<N, Char> s) : _length(N-1){
        static_assert(N<=capacity+1,"invalid size");
        for(Size i=0;i<_length;++i) str[i] = s[i];
        updateNullTerminator();
    }

    template<Size N>
    constexpr Classtype& operator=(ConstexprString<N, Char> const& other) {
        static_assert(N <= capacity, "invalid size");
        _length = other._length;
        for(Size i=0;i<other._length;++i) str[i] = other.str[i];
        updateNullTerminator();
        return *this;
    }

    template<Size N>
    constexpr Classtype& operator=(const_char_array_ref<N, Char> s) {
        static_assert(N <= capacity+1, "invalid size");
        _length = N-1;
        for(Size i=0;i<_length;++i) str[i] = s[i];
        updateNullTerminator();
        return *this;
    }

    constexpr void resize (Size n){
        _length = n;
        updateNullTerminator();
    }

    constexpr Char& operator[](Size idx){ return str[idx]; }
    constexpr Char const& operator[](Size idx) const{ return str[idx]; }

    using const_char_array_ref_equivalent = const_char_array_ref<StorageArraySize,Char>;

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

    template<Size,typename> friend class ConstexprString;

    Size _length;
    StorageArray str = {};

}; //class




template<Size N, typename Char>
constexpr ConstexprString<N-1,Char> make_string(const_char_array_ref<N,Char> s) {
    return {s};
}

template<Size M, typename Char>
constexpr Size length(ConstexprString<M,Char> const& t) {
    return t.length();
}

template<Size M, typename Char>
constexpr Size length(const_char_array_ref<M,Char>) {
    return M-1;
}

template<Size N, typename T, typename Char>
constexpr ConstexprString<N,Char> & append( ConstexprString<N, Char> & s1,         T const& s2) {

    const auto start =length(s1);

    s1.resize(length(s1) + length(s2)); //adds \0 terminator

    for(Size i=0;i<length(s2);++i)
        s1[start + i] = s2[i];

    return s1;
}

template<Size N, Size M, typename Char>
constexpr auto conditional(bool condition, const_char_array_ref<N,Char> s1,   ConstexprString<M,Char> const& s2) {
    constexpr auto l1 = length(s1);
    constexpr auto l2 = M; //todo - suboptimal
    constexpr auto OutSize = l1 > l2 ? l1 : l2;

    return condition ?
                ConstexprString<OutSize,Char>(s1) :
                ConstexprString<OutSize,Char>(s2) ;
}

template<Size N, Size M, typename Char>
constexpr bool operator==( ConstexprString<N,Char> const& s1,        ConstexprString<M,Char> const& s2) {

    if(length(s1) !=length(s2)) return false; //length does not include '\0'

    for(Size i=0;i<s1.length();++i)
        if (s1[i]!=s2[i]) return false;

    return true;
}

template<Size N, Size M, typename Char>
constexpr bool operator==( ConstexprString<N,Char> const& s1,        const_char_array_ref<M,Char> s2) {
    return s1 == ConstexprString<M,Char> {s2};
}

template<Size N, Size M, typename Char>
constexpr bool operator==(  const_char_array_ref<M,Char> s1,       ConstexprString<N,Char> const& s2) {
    return ConstexprString<N,Char> {s1}==s2;
}


template<Size N, Size M, typename Char>
constexpr auto operator+( ConstexprString<N,Char> const& s1,         ConstexprString<M,Char> const& s2) {
    auto r = ConstexprString<N+M,Char>(s1);
    return append(r,s2);
}

template<Size N, Size M, typename Char>
constexpr auto operator+( ConstexprString<N,Char> const& s1,         const_char_array_ref<M,Char> s2) {
    auto r = ConstexprString<N+length(s2),Char>(s1);
    return append(r,s2);
}

template<Size N, Size M, typename Char>
constexpr auto operator+( const_char_array_ref<N,Char> s1,   ConstexprString<M,Char> const& s2) {
    auto r = ConstexprString<length(s1)+M,Char>(s1);
    return append(r,s2);
}

template<Size N, typename Char>
constexpr std::ostream& operator<<(std::ostream& s, ConstexprString<N,Char> const& a) {
    return s<<a.c_str();
}

} //ns ces





