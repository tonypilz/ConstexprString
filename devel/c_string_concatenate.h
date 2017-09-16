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

        if (*s1=='f') return Next<'f'>::concatenate(s1+1,s2);
        if (*s1=='b') return Next<'b'>::concatenate(s1+1,s2);

        return Next<'\0'>::concatenate(s1+1,s2);





//        if (*s1=='a') return Next<'a'>::concatenate(s1+1,s2);
//        if (*s1=='t') return Next<'t'>::concatenate(s1+1,s2);
//        if (*s1=='x') return Next<'x'>::concatenate(s1+1,s2);

//        return Next<'\0'>::concatenate(s1+1,s2);

//        if (*s1=='a') return Next<'a'>::concatenate(s1+1,s2);
////        if (*s1=='b') return Next<'b'>::concatenate(s1+1,s2);
////        if (*s1=='c') return Next<'c'>::concatenate(s1+1,s2);
////        if (*s1=='d') return Next<'d'>::concatenate(s1+1,s2);
////        if (*s1=='e') return Next<'e'>::concatenate(s1+1,s2);
////        if (*s1=='f') return Next<'f'>::concatenate(s1+1,s2);
////        if (*s1=='g') return Next<'g'>::concatenate(s1+1,s2);
////        if (*s1=='h') return Next<'h'>::concatenate(s1+1,s2);
////        if (*s1=='i') return Next<'i'>::concatenate(s1+1,s2);
////        if (*s1=='j') return Next<'j'>::concatenate(s1+1,s2);
////        if (*s1=='k') return Next<'k'>::concatenate(s1+1,s2);
////        if (*s1=='l') return Next<'l'>::concatenate(s1+1,s2);
////        if (*s1=='m') return Next<'m'>::concatenate(s1+1,s2);
////        if (*s1=='n') return Next<'n'>::concatenate(s1+1,s2);
////        if (*s1=='o') return Next<'o'>::concatenate(s1+1,s2);
//        if (*s1=='p') return Next<'p'>::concatenate(s1+1,s2);
//        if (*s1=='q') return Next<'q'>::concatenate(s1+1,s2);
//        if (*s1=='r') return Next<'r'>::concatenate(s1+1,s2);
//        if (*s1=='s') return Next<'s'>::concatenate(s1+1,s2);
//        if (*s1=='t') return Next<'t'>::concatenate(s1+1,s2);
//        if (*s1=='u') return Next<'u'>::concatenate(s1+1,s2);
//        if (*s1=='v') return Next<'v'>::concatenate(s1+1,s2);
//        if (*s1=='w') return Next<'w'>::concatenate(s1+1,s2);
//        if (*s1=='x') return Next<'x'>::concatenate(s1+1,s2);
//        if (*s1=='y') return Next<'y'>::concatenate(s1+1,s2);
//        if (*s1=='z') return Next<'z'>::concatenate(s1+1,s2);

//        return Next<'\0'>::concatenate(s1+1,s2);

//        if (*s1==0) return Next<0>::concatenate(s1+1,s2);
//        if (*s1==1) return Next<1>::concatenate(s1+1,s2);
//        if (*s1==2) return Next<2>::concatenate(s1+1,s2);
//        if (*s1==3) return Next<3>::concatenate(s1+1,s2);
//        if (*s1==4) return Next<4>::concatenate(s1+1,s2);
//        if (*s1==5) return Next<5>::concatenate(s1+1,s2);
//        if (*s1==6) return Next<6>::concatenate(s1+1,s2);
//        if (*s1==7) return Next<7>::concatenate(s1+1,s2);
//        if (*s1==8) return Next<8>::concatenate(s1+1,s2);
//        if (*s1==9) return Next<9>::concatenate(s1+1,s2);
//        if (*s1==10) return Next<10>::concatenate(s1+1,s2);
//        if (*s1==11) return Next<11>::concatenate(s1+1,s2);
//        if (*s1==12) return Next<12>::concatenate(s1+1,s2);
//        if (*s1==13) return Next<13>::concatenate(s1+1,s2);
//        if (*s1==14) return Next<14>::concatenate(s1+1,s2);
//        if (*s1==15) return Next<15>::concatenate(s1+1,s2);
//        if (*s1==16) return Next<16>::concatenate(s1+1,s2);
//        if (*s1==17) return Next<17>::concatenate(s1+1,s2);
//        if (*s1==18) return Next<18>::concatenate(s1+1,s2);
//        if (*s1==19) return Next<19>::concatenate(s1+1,s2);
//        if (*s1==20) return Next<20>::concatenate(s1+1,s2);
//        if (*s1==21) return Next<21>::concatenate(s1+1,s2);
//        if (*s1==22) return Next<22>::concatenate(s1+1,s2);
//        if (*s1==23) return Next<23>::concatenate(s1+1,s2);
//        if (*s1==24) return Next<24>::concatenate(s1+1,s2);
//        if (*s1==25) return Next<25>::concatenate(s1+1,s2);
//        if (*s1==26) return Next<26>::concatenate(s1+1,s2);
//        if (*s1==27) return Next<27>::concatenate(s1+1,s2);
//        if (*s1==28) return Next<28>::concatenate(s1+1,s2);
//        if (*s1==29) return Next<29>::concatenate(s1+1,s2);
//        if (*s1==30) return Next<30>::concatenate(s1+1,s2);
//        if (*s1==31) return Next<31>::concatenate(s1+1,s2);
//        if (*s1==32) return Next<32>::concatenate(s1+1,s2);
//        if (*s1==33) return Next<33>::concatenate(s1+1,s2);
//        if (*s1==34) return Next<34>::concatenate(s1+1,s2);
//        if (*s1==35) return Next<35>::concatenate(s1+1,s2);
//        if (*s1==36) return Next<36>::concatenate(s1+1,s2);
//        if (*s1==37) return Next<37>::concatenate(s1+1,s2);
//        if (*s1==38) return Next<38>::concatenate(s1+1,s2);
//        if (*s1==39) return Next<39>::concatenate(s1+1,s2);
//        if (*s1==40) return Next<40>::concatenate(s1+1,s2);
//        if (*s1==41) return Next<41>::concatenate(s1+1,s2);
//        if (*s1==42) return Next<42>::concatenate(s1+1,s2);
//        if (*s1==43) return Next<43>::concatenate(s1+1,s2);
//        if (*s1==44) return Next<44>::concatenate(s1+1,s2);
//        if (*s1==45) return Next<45>::concatenate(s1+1,s2);
//        if (*s1==46) return Next<46>::concatenate(s1+1,s2);
//        if (*s1==47) return Next<47>::concatenate(s1+1,s2);
//        if (*s1==48) return Next<48>::concatenate(s1+1,s2);
//        if (*s1==49) return Next<49>::concatenate(s1+1,s2);
//        if (*s1==50) return Next<50>::concatenate(s1+1,s2);
//        if (*s1==51) return Next<51>::concatenate(s1+1,s2);
//        if (*s1==52) return Next<52>::concatenate(s1+1,s2);
//        if (*s1==53) return Next<53>::concatenate(s1+1,s2);
//        if (*s1==54) return Next<54>::concatenate(s1+1,s2);
//        if (*s1==55) return Next<55>::concatenate(s1+1,s2);
//        if (*s1==56) return Next<56>::concatenate(s1+1,s2);
//        if (*s1==57) return Next<57>::concatenate(s1+1,s2);
//        if (*s1==58) return Next<58>::concatenate(s1+1,s2);
//        if (*s1==59) return Next<59>::concatenate(s1+1,s2);
//        if (*s1==60) return Next<60>::concatenate(s1+1,s2);
//        if (*s1==61) return Next<61>::concatenate(s1+1,s2);
//        if (*s1==62) return Next<62>::concatenate(s1+1,s2);
//        if (*s1==63) return Next<63>::concatenate(s1+1,s2);
//        if (*s1==64) return Next<64>::concatenate(s1+1,s2);
//        if (*s1==65) return Next<65>::concatenate(s1+1,s2);
//        if (*s1==66) return Next<66>::concatenate(s1+1,s2);
//        if (*s1==67) return Next<67>::concatenate(s1+1,s2);
//        if (*s1==68) return Next<68>::concatenate(s1+1,s2);
//        if (*s1==69) return Next<69>::concatenate(s1+1,s2);
//        if (*s1==70) return Next<70>::concatenate(s1+1,s2);
//        if (*s1==71) return Next<71>::concatenate(s1+1,s2);
//        if (*s1==72) return Next<72>::concatenate(s1+1,s2);
//        if (*s1==73) return Next<73>::concatenate(s1+1,s2);
//        if (*s1==74) return Next<74>::concatenate(s1+1,s2);
//        if (*s1==75) return Next<75>::concatenate(s1+1,s2);
//        if (*s1==76) return Next<76>::concatenate(s1+1,s2);
//        if (*s1==77) return Next<77>::concatenate(s1+1,s2);
//        if (*s1==78) return Next<78>::concatenate(s1+1,s2);
//        if (*s1==79) return Next<79>::concatenate(s1+1,s2);
//        if (*s1==80) return Next<80>::concatenate(s1+1,s2);
//        if (*s1==81) return Next<81>::concatenate(s1+1,s2);
//        if (*s1==82) return Next<82>::concatenate(s1+1,s2);
//        if (*s1==83) return Next<83>::concatenate(s1+1,s2);
//        if (*s1==84) return Next<84>::concatenate(s1+1,s2);
//        if (*s1==85) return Next<85>::concatenate(s1+1,s2);
//        if (*s1==86) return Next<86>::concatenate(s1+1,s2);
//        if (*s1==87) return Next<87>::concatenate(s1+1,s2);
//        if (*s1==88) return Next<88>::concatenate(s1+1,s2);
//        if (*s1==89) return Next<89>::concatenate(s1+1,s2);
//        if (*s1==90) return Next<90>::concatenate(s1+1,s2);
//        if (*s1==91) return Next<91>::concatenate(s1+1,s2);
//        if (*s1==92) return Next<92>::concatenate(s1+1,s2);
//        if (*s1==93) return Next<93>::concatenate(s1+1,s2);
//        if (*s1==94) return Next<94>::concatenate(s1+1,s2);
//        if (*s1==95) return Next<95>::concatenate(s1+1,s2);
//        if (*s1==96) return Next<96>::concatenate(s1+1,s2);
//        if (*s1==97) return Next<97>::concatenate(s1+1,s2);
//        if (*s1==98) return Next<98>::concatenate(s1+1,s2);
//        if (*s1==99) return Next<99>::concatenate(s1+1,s2);
//        if (*s1==100) return Next<100>::concatenate(s1+1,s2);
//        if (*s1==101) return Next<101>::concatenate(s1+1,s2);
//        if (*s1==102) return Next<102>::concatenate(s1+1,s2);
//        if (*s1==103) return Next<103>::concatenate(s1+1,s2);
//        if (*s1==104) return Next<104>::concatenate(s1+1,s2);
//        if (*s1==105) return Next<105>::concatenate(s1+1,s2);
//        if (*s1==106) return Next<106>::concatenate(s1+1,s2);
//        if (*s1==107) return Next<107>::concatenate(s1+1,s2);
//        if (*s1==108) return Next<108>::concatenate(s1+1,s2);
//        if (*s1==109) return Next<109>::concatenate(s1+1,s2);
//        if (*s1==110) return Next<110>::concatenate(s1+1,s2);
//        if (*s1==111) return Next<111>::concatenate(s1+1,s2);
//        if (*s1==112) return Next<112>::concatenate(s1+1,s2);
//        if (*s1==113) return Next<113>::concatenate(s1+1,s2);
//        if (*s1==114) return Next<114>::concatenate(s1+1,s2);
//        if (*s1==115) return Next<115>::concatenate(s1+1,s2);
//        if (*s1==116) return Next<116>::concatenate(s1+1,s2);
//        if (*s1==117) return Next<117>::concatenate(s1+1,s2);
//        if (*s1==118) return Next<118>::concatenate(s1+1,s2);
//        if (*s1==119) return Next<119>::concatenate(s1+1,s2);
//        if (*s1==120) return Next<120>::concatenate(s1+1,s2);
//        if (*s1==121) return Next<121>::concatenate(s1+1,s2);
//        if (*s1==122) return Next<122>::concatenate(s1+1,s2);
//        if (*s1==123) return Next<123>::concatenate(s1+1,s2);
//        if (*s1==124) return Next<124>::concatenate(s1+1,s2);
//        if (*s1==125) return Next<125>::concatenate(s1+1,s2);
//        if (*s1==126) return Next<126>::concatenate(s1+1,s2);
//        if (*s1==127) return Next<127>::concatenate(s1+1,s2);
//        if (*s1==128) return Next<128>::concatenate(s1+1,s2);
//        if (*s1==129) return Next<129>::concatenate(s1+1,s2);
//        if (*s1==130) return Next<130>::concatenate(s1+1,s2);
//        if (*s1==131) return Next<131>::concatenate(s1+1,s2);
//        if (*s1==132) return Next<132>::concatenate(s1+1,s2);
//        if (*s1==133) return Next<133>::concatenate(s1+1,s2);
//        if (*s1==134) return Next<134>::concatenate(s1+1,s2);
//        if (*s1==135) return Next<135>::concatenate(s1+1,s2);
//        if (*s1==136) return Next<136>::concatenate(s1+1,s2);
//        if (*s1==137) return Next<137>::concatenate(s1+1,s2);
//        if (*s1==138) return Next<138>::concatenate(s1+1,s2);
//        if (*s1==139) return Next<139>::concatenate(s1+1,s2);
//        if (*s1==140) return Next<140>::concatenate(s1+1,s2);
//        if (*s1==141) return Next<141>::concatenate(s1+1,s2);
//        if (*s1==142) return Next<142>::concatenate(s1+1,s2);
//        if (*s1==143) return Next<143>::concatenate(s1+1,s2);
//        if (*s1==144) return Next<144>::concatenate(s1+1,s2);
//        if (*s1==145) return Next<145>::concatenate(s1+1,s2);
//        if (*s1==146) return Next<146>::concatenate(s1+1,s2);
//        if (*s1==147) return Next<147>::concatenate(s1+1,s2);
//        if (*s1==148) return Next<148>::concatenate(s1+1,s2);
//        if (*s1==149) return Next<149>::concatenate(s1+1,s2);
//        if (*s1==150) return Next<150>::concatenate(s1+1,s2);
//        if (*s1==151) return Next<151>::concatenate(s1+1,s2);
//        if (*s1==152) return Next<152>::concatenate(s1+1,s2);
//        if (*s1==153) return Next<153>::concatenate(s1+1,s2);
//        if (*s1==154) return Next<154>::concatenate(s1+1,s2);
//        if (*s1==155) return Next<155>::concatenate(s1+1,s2);
//        if (*s1==156) return Next<156>::concatenate(s1+1,s2);
//        if (*s1==157) return Next<157>::concatenate(s1+1,s2);
//        if (*s1==158) return Next<158>::concatenate(s1+1,s2);
//        if (*s1==159) return Next<159>::concatenate(s1+1,s2);
//        if (*s1==160) return Next<160>::concatenate(s1+1,s2);
//        if (*s1==161) return Next<161>::concatenate(s1+1,s2);
//        if (*s1==162) return Next<162>::concatenate(s1+1,s2);
//        if (*s1==163) return Next<163>::concatenate(s1+1,s2);
//        if (*s1==164) return Next<164>::concatenate(s1+1,s2);
//        if (*s1==165) return Next<165>::concatenate(s1+1,s2);
//        if (*s1==166) return Next<166>::concatenate(s1+1,s2);
//        if (*s1==167) return Next<167>::concatenate(s1+1,s2);
//        if (*s1==168) return Next<168>::concatenate(s1+1,s2);
//        if (*s1==169) return Next<169>::concatenate(s1+1,s2);
//        if (*s1==170) return Next<170>::concatenate(s1+1,s2);
//        if (*s1==171) return Next<171>::concatenate(s1+1,s2);
//        if (*s1==172) return Next<172>::concatenate(s1+1,s2);
//        if (*s1==173) return Next<173>::concatenate(s1+1,s2);
//        if (*s1==174) return Next<174>::concatenate(s1+1,s2);
//        if (*s1==175) return Next<175>::concatenate(s1+1,s2);
//        if (*s1==176) return Next<176>::concatenate(s1+1,s2);
//        if (*s1==177) return Next<177>::concatenate(s1+1,s2);
//        if (*s1==178) return Next<178>::concatenate(s1+1,s2);
//        if (*s1==179) return Next<179>::concatenate(s1+1,s2);
//        if (*s1==180) return Next<180>::concatenate(s1+1,s2);
//        if (*s1==181) return Next<181>::concatenate(s1+1,s2);
//        if (*s1==182) return Next<182>::concatenate(s1+1,s2);
//        if (*s1==183) return Next<183>::concatenate(s1+1,s2);
//        if (*s1==184) return Next<184>::concatenate(s1+1,s2);
//        if (*s1==185) return Next<185>::concatenate(s1+1,s2);
//        if (*s1==186) return Next<186>::concatenate(s1+1,s2);
//        if (*s1==187) return Next<187>::concatenate(s1+1,s2);
//        if (*s1==188) return Next<188>::concatenate(s1+1,s2);
//        if (*s1==189) return Next<189>::concatenate(s1+1,s2);
//        if (*s1==190) return Next<190>::concatenate(s1+1,s2);
//        if (*s1==191) return Next<191>::concatenate(s1+1,s2);
//        if (*s1==192) return Next<192>::concatenate(s1+1,s2);
//        if (*s1==193) return Next<193>::concatenate(s1+1,s2);
//        if (*s1==194) return Next<194>::concatenate(s1+1,s2);
//        if (*s1==195) return Next<195>::concatenate(s1+1,s2);
//        if (*s1==196) return Next<196>::concatenate(s1+1,s2);
//        if (*s1==197) return Next<197>::concatenate(s1+1,s2);
//        if (*s1==198) return Next<198>::concatenate(s1+1,s2);
//        if (*s1==199) return Next<199>::concatenate(s1+1,s2);
//        if (*s1==200) return Next<200>::concatenate(s1+1,s2);
//        if (*s1==201) return Next<201>::concatenate(s1+1,s2);
//        if (*s1==202) return Next<202>::concatenate(s1+1,s2);
//        if (*s1==203) return Next<203>::concatenate(s1+1,s2);
//        if (*s1==204) return Next<204>::concatenate(s1+1,s2);
//        if (*s1==205) return Next<205>::concatenate(s1+1,s2);
//        if (*s1==206) return Next<206>::concatenate(s1+1,s2);
//        if (*s1==207) return Next<207>::concatenate(s1+1,s2);
//        if (*s1==208) return Next<208>::concatenate(s1+1,s2);
//        if (*s1==209) return Next<209>::concatenate(s1+1,s2);
//        if (*s1==210) return Next<210>::concatenate(s1+1,s2);
//        if (*s1==211) return Next<211>::concatenate(s1+1,s2);
//        if (*s1==212) return Next<212>::concatenate(s1+1,s2);
//        if (*s1==213) return Next<213>::concatenate(s1+1,s2);
//        if (*s1==214) return Next<214>::concatenate(s1+1,s2);
//        if (*s1==215) return Next<215>::concatenate(s1+1,s2);
//        if (*s1==216) return Next<216>::concatenate(s1+1,s2);
//        if (*s1==217) return Next<217>::concatenate(s1+1,s2);
//        if (*s1==218) return Next<218>::concatenate(s1+1,s2);
//        if (*s1==219) return Next<219>::concatenate(s1+1,s2);
//        if (*s1==220) return Next<220>::concatenate(s1+1,s2);
//        if (*s1==221) return Next<221>::concatenate(s1+1,s2);
//        if (*s1==222) return Next<222>::concatenate(s1+1,s2);
//        if (*s1==223) return Next<223>::concatenate(s1+1,s2);
//        if (*s1==224) return Next<224>::concatenate(s1+1,s2);
//        if (*s1==225) return Next<225>::concatenate(s1+1,s2);
//        if (*s1==226) return Next<226>::concatenate(s1+1,s2);
//        if (*s1==227) return Next<227>::concatenate(s1+1,s2);
//        if (*s1==228) return Next<228>::concatenate(s1+1,s2);
//        if (*s1==229) return Next<229>::concatenate(s1+1,s2);
//        if (*s1==230) return Next<230>::concatenate(s1+1,s2);
//        if (*s1==231) return Next<231>::concatenate(s1+1,s2);
//        if (*s1==232) return Next<232>::concatenate(s1+1,s2);
//        if (*s1==233) return Next<233>::concatenate(s1+1,s2);
//        if (*s1==234) return Next<234>::concatenate(s1+1,s2);
//        if (*s1==235) return Next<235>::concatenate(s1+1,s2);
//        if (*s1==236) return Next<236>::concatenate(s1+1,s2);
//        if (*s1==237) return Next<237>::concatenate(s1+1,s2);
//        if (*s1==238) return Next<238>::concatenate(s1+1,s2);
//        if (*s1==239) return Next<239>::concatenate(s1+1,s2);
//        if (*s1==240) return Next<240>::concatenate(s1+1,s2);
//        if (*s1==241) return Next<241>::concatenate(s1+1,s2);
//        if (*s1==242) return Next<242>::concatenate(s1+1,s2);
//        if (*s1==243) return Next<243>::concatenate(s1+1,s2);
//        if (*s1==244) return Next<244>::concatenate(s1+1,s2);
//        if (*s1==245) return Next<245>::concatenate(s1+1,s2);
//        if (*s1==246) return Next<246>::concatenate(s1+1,s2);
//        if (*s1==247) return Next<247>::concatenate(s1+1,s2);
//        if (*s1==248) return Next<248>::concatenate(s1+1,s2);
//        if (*s1==249) return Next<249>::concatenate(s1+1,s2);
//        if (*s1==250) return Next<250>::concatenate(s1+1,s2);
//        if (*s1==251) return Next<251>::concatenate(s1+1,s2);
//        if (*s1==252) return Next<252>::concatenate(s1+1,s2);
//        if (*s1==253) return Next<253>::concatenate(s1+1,s2);
//        if (*s1==254) return Next<254>::concatenate(s1+1,s2);
//        return Next<255>::concatenate(s1+1,s2);

//        return "";
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

-> decltype(detail::Concatenator<s1_size-1,s2_size-1, detail::CharList<>>::concatenate(s1,s2)){
     return detail::Concatenator<s1_size-1,s2_size-1, detail::CharList<>>::concatenate(s1,s2);
}

template<int s1_size, int s2_size, int s3_size>
constexpr auto concatenate(

        const char(&s1)[s1_size],
        const char(&s2)[s2_size],
        const char(&s3)[s3_size])

-> decltype(concatenate(concatenate(s1,s2),s3)){
     return concatenate(concatenate(s1,s2),s3);
}
