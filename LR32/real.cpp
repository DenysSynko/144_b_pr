#include "head.h"
float set_prem(int r, float zarp){
    float prem;
    if((2025-r)<10){
        prem=0.1*zarp;
    }else if((2025-r)>=10 && (2025-r)<20){
        prem=0.25*zarp;
    }else if((2025-r)>=20){
        prem=0.4*zarp;
    }
    return prem;
}


Pracivnyk::Pracivnyk() {
    prizv="--Surname--";
    viddil="--Department--";
    rik=2000;
    zarp=0;
    if((2025-rik)<10){
        prem=0.1*zarp;
    }else if((2025-rik)>=10 && (2025-rik)<20){
        prem=0.25*zarp;
    }else if((2025-rik)>=20){
        prem=0.4*zarp;
    }
}
Pracivnyk::Pracivnyk(string pr, string vdd,  int r, float zp){
    prizv=pr;
    viddil=vdd;
    rik=r;
    zarp=zp;
    if((2025-r)<10){
        prem=0.1*zarp;
    }else if((2025-r)>=10 && (2025-r)<20){
        prem=0.25*zarp;
    }else if((2025-r)>=20){
        prem=0.4*zarp;
    }
}
void Pracivnyk::set_prac(string pr, string vdd,  int r, float zp){
    prizv=pr;
    viddil=vdd;
    rik=r;
    zarp=zp;
    prem = set_prem(rik, zarp);
}
void Pracivnyk::get_prac(){
    cout<<" Surname:"<<prizv<<" Department:"<<viddil<<" Year:"<<rik<<" Salary:"<<zarp<<" Bonuses:"<<prem<<endl;
}
Pracivnyk::~Pracivnyk(){};