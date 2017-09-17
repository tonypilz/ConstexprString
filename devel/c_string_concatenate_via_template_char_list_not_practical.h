#pragma once

namespace  {
namespace detail {

template<char... T>
struct as_array{
    static constexpr auto strlen = sizeof...(T)+1;
    static constexpr char str[strlen] = {T..., '\0'};
};

template<char... T>
constexpr char as_array<T...>::str[as_array<T...>::strlen];

template<char... T>
struct CharList{

    static constexpr auto length = sizeof...(T);

    template<char i>
    using append = CharList<T...,i>;

    template<template<char...> class S>
    using makeType = S<T...>;

};


template<int s1_size, int s2_size, typename List>
struct ConcatenatorRes{
    typedef const char(&type)[s1_size + s2_size + List::template makeType<as_array>::strlen];
};


template<int s1_size, int s2_size, typename List>
struct Concatenator{

    template<char c>
    using Next = Concatenator<s1_size-1,s2_size, typename List::template append<c>>;

    using Res = typename ConcatenatorRes<s1_size, s2_size, List>::type;

    static constexpr Res concatenate(const char* s1, const char* s2){
        return
           *s1=='f' ? Next<'f'>::concatenate(s1+1,s2) :
           *s1=='o' ? Next<'o'>::concatenate(s1+1,s2) :
           *s1=='b' ? Next<'b'>::concatenate(s1+1,s2) :
           *s1=='a' ? Next<'a'>::concatenate(s1+1,s2) :
                      Next<'r'>::concatenate(s1+1,s2) ;
    }


    static constexpr Res concatenate_small_letters_only_still_overflow(const char* s1, const char* s2){
        return
            *s1=='a' ? Next<'a'>::concatenate(s1+1,s2):
            *s1=='b' ? Next<'b'>::concatenate(s1+1,s2):
            *s1=='c' ? Next<'c'>::concatenate(s1+1,s2):
            *s1=='d' ? Next<'d'>::concatenate(s1+1,s2):
            *s1=='e' ? Next<'e'>::concatenate(s1+1,s2):
            *s1=='f' ? Next<'f'>::concatenate(s1+1,s2):
            *s1=='g' ? Next<'g'>::concatenate(s1+1,s2):
            *s1=='h' ? Next<'h'>::concatenate(s1+1,s2):
            *s1=='i' ? Next<'i'>::concatenate(s1+1,s2):
            *s1=='j' ? Next<'j'>::concatenate(s1+1,s2):
            *s1=='k' ? Next<'k'>::concatenate(s1+1,s2):
            *s1=='l' ? Next<'l'>::concatenate(s1+1,s2):
            *s1=='m' ? Next<'m'>::concatenate(s1+1,s2):
            *s1=='n' ? Next<'n'>::concatenate(s1+1,s2):
            *s1=='o' ? Next<'o'>::concatenate(s1+1,s2):
            *s1=='p' ? Next<'p'>::concatenate(s1+1,s2):
            *s1=='q' ? Next<'q'>::concatenate(s1+1,s2):
            *s1=='r' ? Next<'r'>::concatenate(s1+1,s2):
            *s1=='s' ? Next<'s'>::concatenate(s1+1,s2):
            *s1=='t' ? Next<'t'>::concatenate(s1+1,s2):
            *s1=='u' ? Next<'u'>::concatenate(s1+1,s2):
            *s1=='v' ? Next<'v'>::concatenate(s1+1,s2):
            *s1=='w' ? Next<'w'>::concatenate(s1+1,s2):
            *s1=='x' ? Next<'x'>::concatenate(s1+1,s2):
            *s1=='y' ? Next<'y'>::concatenate(s1+1,s2):
            *s1=='z' ? Next<'z'>::concatenate(s1+1,s2):
                       Next<'\0'>::concatenate(s1+1,s2);
    }


    static constexpr Res concatenate_actual_but_overflow(const char* s1, const char* s2){
         return
            *s1==0 ? Next<0>::concatenate(s1+1,s2):
            *s1==1 ? Next<1>::concatenate(s1+1,s2):
            *s1==2 ? Next<2>::concatenate(s1+1,s2):
            *s1==3 ? Next<3>::concatenate(s1+1,s2):
            *s1==4 ? Next<4>::concatenate(s1+1,s2):
            *s1==5 ? Next<5>::concatenate(s1+1,s2):
            *s1==6 ? Next<6>::concatenate(s1+1,s2):
            *s1==7 ? Next<7>::concatenate(s1+1,s2):
            *s1==8 ? Next<8>::concatenate(s1+1,s2):
            *s1==9 ? Next<9>::concatenate(s1+1,s2):
            *s1==10 ? Next<10>::concatenate(s1+1,s2):
            *s1==11 ? Next<11>::concatenate(s1+1,s2):
            *s1==12 ? Next<12>::concatenate(s1+1,s2):
            *s1==13 ? Next<13>::concatenate(s1+1,s2):
            *s1==14 ? Next<14>::concatenate(s1+1,s2):
            *s1==15 ? Next<15>::concatenate(s1+1,s2):
            *s1==16 ? Next<16>::concatenate(s1+1,s2):
            *s1==17 ? Next<17>::concatenate(s1+1,s2):
            *s1==18 ? Next<18>::concatenate(s1+1,s2):
            *s1==19 ? Next<19>::concatenate(s1+1,s2):
            *s1==20 ? Next<20>::concatenate(s1+1,s2):
            *s1==21 ? Next<21>::concatenate(s1+1,s2):
            *s1==22 ? Next<22>::concatenate(s1+1,s2):
            *s1==23 ? Next<23>::concatenate(s1+1,s2):
            *s1==24 ? Next<24>::concatenate(s1+1,s2):
            *s1==25 ? Next<25>::concatenate(s1+1,s2):
            *s1==26 ? Next<26>::concatenate(s1+1,s2):
            *s1==27 ? Next<27>::concatenate(s1+1,s2):
            *s1==28 ? Next<28>::concatenate(s1+1,s2):
            *s1==29 ? Next<29>::concatenate(s1+1,s2):
            *s1==30 ? Next<30>::concatenate(s1+1,s2):
            *s1==31 ? Next<31>::concatenate(s1+1,s2):
            *s1==32 ? Next<32>::concatenate(s1+1,s2):
            *s1==33 ? Next<33>::concatenate(s1+1,s2):
            *s1==34 ? Next<34>::concatenate(s1+1,s2):
            *s1==35 ? Next<35>::concatenate(s1+1,s2):
            *s1==36 ? Next<36>::concatenate(s1+1,s2):
            *s1==37 ? Next<37>::concatenate(s1+1,s2):
            *s1==38 ? Next<38>::concatenate(s1+1,s2):
            *s1==39 ? Next<39>::concatenate(s1+1,s2):
            *s1==40 ? Next<40>::concatenate(s1+1,s2):
            *s1==41 ? Next<41>::concatenate(s1+1,s2):
            *s1==42 ? Next<42>::concatenate(s1+1,s2):
            *s1==43 ? Next<43>::concatenate(s1+1,s2):
            *s1==44 ? Next<44>::concatenate(s1+1,s2):
            *s1==45 ? Next<45>::concatenate(s1+1,s2):
            *s1==46 ? Next<46>::concatenate(s1+1,s2):
            *s1==47 ? Next<47>::concatenate(s1+1,s2):
            *s1==48 ? Next<48>::concatenate(s1+1,s2):
            *s1==49 ? Next<49>::concatenate(s1+1,s2):
            *s1==50 ? Next<50>::concatenate(s1+1,s2):
            *s1==51 ? Next<51>::concatenate(s1+1,s2):
            *s1==52 ? Next<52>::concatenate(s1+1,s2):
            *s1==53 ? Next<53>::concatenate(s1+1,s2):
            *s1==54 ? Next<54>::concatenate(s1+1,s2):
            *s1==55 ? Next<55>::concatenate(s1+1,s2):
            *s1==56 ? Next<56>::concatenate(s1+1,s2):
            *s1==57 ? Next<57>::concatenate(s1+1,s2):
            *s1==58 ? Next<58>::concatenate(s1+1,s2):
            *s1==59 ? Next<59>::concatenate(s1+1,s2):
            *s1==60 ? Next<60>::concatenate(s1+1,s2):
            *s1==61 ? Next<61>::concatenate(s1+1,s2):
            *s1==62 ? Next<62>::concatenate(s1+1,s2):
            *s1==63 ? Next<63>::concatenate(s1+1,s2):
            *s1==64 ? Next<64>::concatenate(s1+1,s2):
            *s1==65 ? Next<65>::concatenate(s1+1,s2):
            *s1==66 ? Next<66>::concatenate(s1+1,s2):
            *s1==67 ? Next<67>::concatenate(s1+1,s2):
            *s1==68 ? Next<68>::concatenate(s1+1,s2):
            *s1==69 ? Next<69>::concatenate(s1+1,s2):
            *s1==70 ? Next<70>::concatenate(s1+1,s2):
            *s1==71 ? Next<71>::concatenate(s1+1,s2):
            *s1==72 ? Next<72>::concatenate(s1+1,s2):
            *s1==73 ? Next<73>::concatenate(s1+1,s2):
            *s1==74 ? Next<74>::concatenate(s1+1,s2):
            *s1==75 ? Next<75>::concatenate(s1+1,s2):
            *s1==76 ? Next<76>::concatenate(s1+1,s2):
            *s1==77 ? Next<77>::concatenate(s1+1,s2):
            *s1==78 ? Next<78>::concatenate(s1+1,s2):
            *s1==79 ? Next<79>::concatenate(s1+1,s2):
            *s1==80 ? Next<80>::concatenate(s1+1,s2):
            *s1==81 ? Next<81>::concatenate(s1+1,s2):
            *s1==82 ? Next<82>::concatenate(s1+1,s2):
            *s1==83 ? Next<83>::concatenate(s1+1,s2):
            *s1==84 ? Next<84>::concatenate(s1+1,s2):
            *s1==85 ? Next<85>::concatenate(s1+1,s2):
            *s1==86 ? Next<86>::concatenate(s1+1,s2):
            *s1==87 ? Next<87>::concatenate(s1+1,s2):
            *s1==88 ? Next<88>::concatenate(s1+1,s2):
            *s1==89 ? Next<89>::concatenate(s1+1,s2):
            *s1==90 ? Next<90>::concatenate(s1+1,s2):
            *s1==91 ? Next<91>::concatenate(s1+1,s2):
            *s1==92 ? Next<92>::concatenate(s1+1,s2):
            *s1==93 ? Next<93>::concatenate(s1+1,s2):
            *s1==94 ? Next<94>::concatenate(s1+1,s2):
            *s1==95 ? Next<95>::concatenate(s1+1,s2):
            *s1==96 ? Next<96>::concatenate(s1+1,s2):
            *s1==97 ? Next<97>::concatenate(s1+1,s2):
            *s1==98 ? Next<98>::concatenate(s1+1,s2):
            *s1==99 ? Next<99>::concatenate(s1+1,s2):
            *s1==100 ? Next<100>::concatenate(s1+1,s2):
            *s1==101 ? Next<101>::concatenate(s1+1,s2):
            *s1==102 ? Next<102>::concatenate(s1+1,s2):
            *s1==103 ? Next<103>::concatenate(s1+1,s2):
            *s1==104 ? Next<104>::concatenate(s1+1,s2):
            *s1==105 ? Next<105>::concatenate(s1+1,s2):
            *s1==106 ? Next<106>::concatenate(s1+1,s2):
            *s1==107 ? Next<107>::concatenate(s1+1,s2):
            *s1==108 ? Next<108>::concatenate(s1+1,s2):
            *s1==109 ? Next<109>::concatenate(s1+1,s2):
            *s1==110 ? Next<110>::concatenate(s1+1,s2):
            *s1==111 ? Next<111>::concatenate(s1+1,s2):
            *s1==112 ? Next<112>::concatenate(s1+1,s2):
            *s1==113 ? Next<113>::concatenate(s1+1,s2):
            *s1==114 ? Next<114>::concatenate(s1+1,s2):
            *s1==115 ? Next<115>::concatenate(s1+1,s2):
            *s1==116 ? Next<116>::concatenate(s1+1,s2):
            *s1==117 ? Next<117>::concatenate(s1+1,s2):
            *s1==118 ? Next<118>::concatenate(s1+1,s2):
            *s1==119 ? Next<119>::concatenate(s1+1,s2):
            *s1==120 ? Next<120>::concatenate(s1+1,s2):
            *s1==121 ? Next<121>::concatenate(s1+1,s2):
            *s1==122 ? Next<122>::concatenate(s1+1,s2):
            *s1==123 ? Next<123>::concatenate(s1+1,s2):
            *s1==124 ? Next<124>::concatenate(s1+1,s2):
            *s1==125 ? Next<125>::concatenate(s1+1,s2):
            *s1==126 ? Next<126>::concatenate(s1+1,s2):
            *s1==127 ? Next<127>::concatenate(s1+1,s2):
            *s1==128 ? Next<128>::concatenate(s1+1,s2):
            *s1==129 ? Next<129>::concatenate(s1+1,s2):
            *s1==130 ? Next<130>::concatenate(s1+1,s2):
            *s1==131 ? Next<131>::concatenate(s1+1,s2):
            *s1==132 ? Next<132>::concatenate(s1+1,s2):
            *s1==133 ? Next<133>::concatenate(s1+1,s2):
            *s1==134 ? Next<134>::concatenate(s1+1,s2):
            *s1==135 ? Next<135>::concatenate(s1+1,s2):
            *s1==136 ? Next<136>::concatenate(s1+1,s2):
            *s1==137 ? Next<137>::concatenate(s1+1,s2):
            *s1==138 ? Next<138>::concatenate(s1+1,s2):
            *s1==139 ? Next<139>::concatenate(s1+1,s2):
            *s1==140 ? Next<140>::concatenate(s1+1,s2):
            *s1==141 ? Next<141>::concatenate(s1+1,s2):
            *s1==142 ? Next<142>::concatenate(s1+1,s2):
            *s1==143 ? Next<143>::concatenate(s1+1,s2):
            *s1==144 ? Next<144>::concatenate(s1+1,s2):
            *s1==145 ? Next<145>::concatenate(s1+1,s2):
            *s1==146 ? Next<146>::concatenate(s1+1,s2):
            *s1==147 ? Next<147>::concatenate(s1+1,s2):
            *s1==148 ? Next<148>::concatenate(s1+1,s2):
            *s1==149 ? Next<149>::concatenate(s1+1,s2):
            *s1==150 ? Next<150>::concatenate(s1+1,s2):
            *s1==151 ? Next<151>::concatenate(s1+1,s2):
            *s1==152 ? Next<152>::concatenate(s1+1,s2):
            *s1==153 ? Next<153>::concatenate(s1+1,s2):
            *s1==154 ? Next<154>::concatenate(s1+1,s2):
            *s1==155 ? Next<155>::concatenate(s1+1,s2):
            *s1==156 ? Next<156>::concatenate(s1+1,s2):
            *s1==157 ? Next<157>::concatenate(s1+1,s2):
            *s1==158 ? Next<158>::concatenate(s1+1,s2):
            *s1==159 ? Next<159>::concatenate(s1+1,s2):
            *s1==160 ? Next<160>::concatenate(s1+1,s2):
            *s1==161 ? Next<161>::concatenate(s1+1,s2):
            *s1==162 ? Next<162>::concatenate(s1+1,s2):
            *s1==163 ? Next<163>::concatenate(s1+1,s2):
            *s1==164 ? Next<164>::concatenate(s1+1,s2):
            *s1==165 ? Next<165>::concatenate(s1+1,s2):
            *s1==166 ? Next<166>::concatenate(s1+1,s2):
            *s1==167 ? Next<167>::concatenate(s1+1,s2):
            *s1==168 ? Next<168>::concatenate(s1+1,s2):
            *s1==169 ? Next<169>::concatenate(s1+1,s2):
            *s1==170 ? Next<170>::concatenate(s1+1,s2):
            *s1==171 ? Next<171>::concatenate(s1+1,s2):
            *s1==172 ? Next<172>::concatenate(s1+1,s2):
            *s1==173 ? Next<173>::concatenate(s1+1,s2):
            *s1==174 ? Next<174>::concatenate(s1+1,s2):
            *s1==175 ? Next<175>::concatenate(s1+1,s2):
            *s1==176 ? Next<176>::concatenate(s1+1,s2):
            *s1==177 ? Next<177>::concatenate(s1+1,s2):
            *s1==178 ? Next<178>::concatenate(s1+1,s2):
            *s1==179 ? Next<179>::concatenate(s1+1,s2):
            *s1==180 ? Next<180>::concatenate(s1+1,s2):
            *s1==181 ? Next<181>::concatenate(s1+1,s2):
            *s1==182 ? Next<182>::concatenate(s1+1,s2):
            *s1==183 ? Next<183>::concatenate(s1+1,s2):
            *s1==184 ? Next<184>::concatenate(s1+1,s2):
            *s1==185 ? Next<185>::concatenate(s1+1,s2):
            *s1==186 ? Next<186>::concatenate(s1+1,s2):
            *s1==187 ? Next<187>::concatenate(s1+1,s2):
            *s1==188 ? Next<188>::concatenate(s1+1,s2):
            *s1==189 ? Next<189>::concatenate(s1+1,s2):
            *s1==190 ? Next<190>::concatenate(s1+1,s2):
            *s1==191 ? Next<191>::concatenate(s1+1,s2):
            *s1==192 ? Next<192>::concatenate(s1+1,s2):
            *s1==193 ? Next<193>::concatenate(s1+1,s2):
            *s1==194 ? Next<194>::concatenate(s1+1,s2):
            *s1==195 ? Next<195>::concatenate(s1+1,s2):
            *s1==196 ? Next<196>::concatenate(s1+1,s2):
            *s1==197 ? Next<197>::concatenate(s1+1,s2):
            *s1==198 ? Next<198>::concatenate(s1+1,s2):
            *s1==199 ? Next<199>::concatenate(s1+1,s2):
            *s1==200 ? Next<200>::concatenate(s1+1,s2):
            *s1==201 ? Next<201>::concatenate(s1+1,s2):
            *s1==202 ? Next<202>::concatenate(s1+1,s2):
            *s1==203 ? Next<203>::concatenate(s1+1,s2):
            *s1==204 ? Next<204>::concatenate(s1+1,s2):
            *s1==205 ? Next<205>::concatenate(s1+1,s2):
            *s1==206 ? Next<206>::concatenate(s1+1,s2):
            *s1==207 ? Next<207>::concatenate(s1+1,s2):
            *s1==208 ? Next<208>::concatenate(s1+1,s2):
            *s1==209 ? Next<209>::concatenate(s1+1,s2):
            *s1==210 ? Next<210>::concatenate(s1+1,s2):
            *s1==211 ? Next<211>::concatenate(s1+1,s2):
            *s1==212 ? Next<212>::concatenate(s1+1,s2):
            *s1==213 ? Next<213>::concatenate(s1+1,s2):
            *s1==214 ? Next<214>::concatenate(s1+1,s2):
            *s1==215 ? Next<215>::concatenate(s1+1,s2):
            *s1==216 ? Next<216>::concatenate(s1+1,s2):
            *s1==217 ? Next<217>::concatenate(s1+1,s2):
            *s1==218 ? Next<218>::concatenate(s1+1,s2):
            *s1==219 ? Next<219>::concatenate(s1+1,s2):
            *s1==220 ? Next<220>::concatenate(s1+1,s2):
            *s1==221 ? Next<221>::concatenate(s1+1,s2):
            *s1==222 ? Next<222>::concatenate(s1+1,s2):
            *s1==223 ? Next<223>::concatenate(s1+1,s2):
            *s1==224 ? Next<224>::concatenate(s1+1,s2):
            *s1==225 ? Next<225>::concatenate(s1+1,s2):
            *s1==226 ? Next<226>::concatenate(s1+1,s2):
            *s1==227 ? Next<227>::concatenate(s1+1,s2):
            *s1==228 ? Next<228>::concatenate(s1+1,s2):
            *s1==229 ? Next<229>::concatenate(s1+1,s2):
            *s1==230 ? Next<230>::concatenate(s1+1,s2):
            *s1==231 ? Next<231>::concatenate(s1+1,s2):
            *s1==232 ? Next<232>::concatenate(s1+1,s2):
            *s1==233 ? Next<233>::concatenate(s1+1,s2):
            *s1==234 ? Next<234>::concatenate(s1+1,s2):
            *s1==235 ? Next<235>::concatenate(s1+1,s2):
            *s1==236 ? Next<236>::concatenate(s1+1,s2):
            *s1==237 ? Next<237>::concatenate(s1+1,s2):
            *s1==238 ? Next<238>::concatenate(s1+1,s2):
            *s1==239 ? Next<239>::concatenate(s1+1,s2):
            *s1==240 ? Next<240>::concatenate(s1+1,s2):
            *s1==241 ? Next<241>::concatenate(s1+1,s2):
            *s1==242 ? Next<242>::concatenate(s1+1,s2):
            *s1==243 ? Next<243>::concatenate(s1+1,s2):
            *s1==244 ? Next<244>::concatenate(s1+1,s2):
            *s1==245 ? Next<245>::concatenate(s1+1,s2):
            *s1==246 ? Next<246>::concatenate(s1+1,s2):
            *s1==247 ? Next<247>::concatenate(s1+1,s2):
            *s1==248 ? Next<248>::concatenate(s1+1,s2):
            *s1==249 ? Next<249>::concatenate(s1+1,s2):
            *s1==250 ? Next<250>::concatenate(s1+1,s2):
            *s1==251 ? Next<251>::concatenate(s1+1,s2):
            *s1==252 ? Next<252>::concatenate(s1+1,s2):
            *s1==253 ? Next<253>::concatenate(s1+1,s2):
            *s1==254 ? Next<254>::concatenate(s1+1,s2):
                       Next<255>::concatenate(s1+1,s2);
    }



};

template<int s2_size, typename List>
struct Concatenator<0,s2_size,List>{

    using Res = typename ConcatenatorRes<0, s2_size, List>::type;

    static constexpr Res concatenate(const char*s1, const char*s2){
        return Concatenator<s2_size,0,List>::concatenate(s2,s1);
    }
};

template<typename List>
struct Concatenator<0,0,List>{

    using Res = typename ConcatenatorRes<0, 0, List>::type;

    static constexpr Res concatenate(const char*, const char*){
         return List::template makeType<as_array>::str;
    }
};



}
}





template<int s1_size, int s2_size>
constexpr auto concatenate(
        const char(&s1)[s1_size],
        const char(&s2)[s2_size])

-> decltype(detail::Concatenator<s1_size-1,s2_size-1, detail::CharList<>>::concatenate(s1,s2))
{
     return detail::Concatenator<s1_size-1,s2_size-1, detail::CharList<>>::concatenate(s1,s2);
}

template<int s1_size, int s2_size, int s3_size>
constexpr auto concatenate(
        const char(&s1)[s1_size],
        const char(&s2)[s2_size],
        const char(&s3)[s3_size])
-> decltype(concatenate(concatenate(s1,s2),s3))
{
     return concatenate(concatenate(s1,s2),s3);
}















//constexpr char s1[] = "f";
//constexpr char s2[] = "b";

//constexpr decltype(concatenate(s1,s2)) xt = concatenate("f",s2);
//constexpr decltype(concatenate("f",xt,"f")) xta = concatenate("b",xt,"b");

////constexpr decltype(concatenate(x,t)) abxt = concatenate("a","t","x");

//constexpr auto textconcatenated1 = concatenate(s2,xt);

//void echoIfConditions(){
//    for(int i=0;i<256;++i){
//        std::cout<< "if (*s1==" << i << ") return Next<" << i << ">::concatenate(s1+1,s2);" << std::endl;
//    }
//}
//void echoIfConditionsC(){
//    for(int i=0;i<256;++i){
//        std::cout<< "if (*s1=='" << (char)i << "') return Next<'" << (char)i << "'>::concatenate(s1+1,s2);" << std::endl;
//    }
//}
