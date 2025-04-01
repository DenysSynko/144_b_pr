#include <iostream>
#include <clocale>
using namespace std;
//вся програма одним файлом
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

class Pracivnyk{
    string prizv, viddil;
    int rik;
    float zarp, prem;
    public:
    Pracivnyk() {
        prizv="--прізвище--";
        viddil="--відділ--";
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
    Pracivnyk(string pr, string vdd,  int r, float zp){
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
    void set_prac(string pr, string vdd,  int r, float zp){
        prizv=pr;
        viddil=vdd;
        rik=r;
        zarp=zp;
        prem = set_prem(rik, zarp);
    }
    void change(string pr, string npr, string vdd,  int r, float zp){
        if(pr==prizv){
            prizv=npr;
            viddil=vdd;
            rik=r;
            zarp=zp;
            prem = set_prem(rik, zarp);
        }
    }
    void get_prac(){
        cout<<" Прізвище:"<<prizv<<" Відділ:"<<viddil<<" Рік пр-ння:"<<rik<<" Зарплата:"<<zarp<<" Премія:"<<prem<<endl;
    }
    ~Pracivnyk(){};
};

int main(){
    setlocale(LC_CTYPE, "ukr");
    int i,n,r;
    string pr, vdd, npr;
    float zp;
    Pracivnyk A;
    Pracivnyk B("Гончар", "Дукарський", 2006, 16000);
    A.get_prac();
    B.get_prac();
    cout<<"Enter N: ";
    cin>>n;
    Pracivnyk C[n];
    for(i=0;i<n;i++){
        cout<<"Прізвище: ";
        cin>>pr;
        cout<<"Відділ: ";
        cin>>vdd;
        cout<<"Рік пр-ння: ";
        cin>>r;
        cout<<"Зарплата: ";
        cin>>zp;
        C[i].set_prac(pr, vdd, r, zp);
    }
    cout<<"Масив об'єктів: "<<endl;
    for(i=0;i<n;i++){
        C[i].get_prac();
    }
    cout<<"Введіть Прізвище: ";
    cin>>pr;
    cout<<"Введіть нові дані для об'єкта (Прізвище, Відділ, Рік, Зарплата): "<<endl;
    cin>>npr>>vdd>>r>>zp;
    for(i=0;i<n;i++){
        C[i].change(pr, npr, vdd, r, zp);
    }
    cout<<"Масив об'єктів: "<<endl;
    for(i=0;i<n;i++){
        C[i].get_prac();
    }
    return 0;
}
//вся програма одним файлом