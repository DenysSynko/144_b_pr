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
        prizv="--surname--";
        viddil="--department--";
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
    void Pracivnyk::change(string pr, string npr, string vdd,  int r, float zp){
        if(pr==prizv){
            prizv=npr;
            viddil=vdd;
            rik=r;
            zarp=zp;
            prem = set_prem(rik, zarp);
        }
    }
    void Pracivnyk::sort(Pracivnyk arr[], int n){
        int i, j;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if ((2025-arr[j].rik)>(2025-arr[j+1].rik)){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    void Pracivnyk::get_prac(){
        cout<<" Surname:"<<prizv<<" Dep:"<<viddil<<" Year:"<<rik<<" Salary:"<<zarp<<" Bonus:"<<prem<<endl;
    }
    Pracivnyk::~Pracivnyk(){};


float seredniy_stazh(Pracivnyk arr[], int n) {
    int t=0;
    for (int i=0;i<n;i++) {
        t+=(2025-arr[i].rik);
    }
    return (float)t/n;
}

void i_viddil(Pracivnyk arr[], int n) {
    string vidd[n];
    int r=0;
    bool e=true;
    for(int i=0;i<n;i++) {
        int k=0;
        float sum=0;
        vidd[r] = arr[i].viddil;
        for (int j=0;j<n;j++) {
            if (arr[j].viddil == vidd[r]) {
                k++;
                sum+=arr[j].zarp;
            }
        }
        for(int l=0;l<r;l++){
            if(vidd[l]==arr[i].viddil){
                e=false;
            }
        }
        if(e){
            cout<<"Dep: "<<vidd[r]<<" Workers: "<<k<<" Total salary: "<<sum<<endl;
        }
        r++;
        e=true;
    }
}
Vidpustka::Vidpustka() {
        start = "01.07.2021";
    }
    string Vidpustka::calcDate(int startDay, int Month, int Year, int days) {
        int endDay = startDay + days;

        if (endDay > 30) {
            endDay -= 30;
            Month += 1;
            if (Month > 12) {
                Month = 1;
                Year++;
            }
        }

        char buf[11];
        sprintf(buf, "%02d.%02d.%d", endDay, Month, Year);
        return string(buf);
    }
    void Vidpustka::set(Pracivnyk p) {
        prac=p;
        int stazh=2025-p.rik;
        float sum=p.zarp+p.prem;
        if (stazh<10 && sum<12000)
            term=14;
        else if (stazh>25 && sum>25000)
            term=28;
        else
            term=21;
        end=calcDate(1, 7, 2021, term);
    }

    void Vidpustka::print() {
        cout<<"Worker: "<< prac.prizv<<", Dep: "<<prac.viddil<<", Vacation from "<<start<<" for "<< term <<" days, to "<<end<<endl;
    }