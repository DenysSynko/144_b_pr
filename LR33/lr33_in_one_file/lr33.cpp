#include <iostream>
#include <clocale>
#include <string>
#include <ctime>
using namespace std;

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
    void sort(Pracivnyk arr[], int n){
        int i, j;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if ((2025-arr[j].rik)>(2025-arr[j+1].rik)){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    void get_prac(){
        cout<<" Прізвище:"<<prizv<<" Відділ:"<<viddil<<" Рік пр-ння:"<<rik<<" Зарплата:"<<zarp<<" Премія:"<<prem<<endl;
    }
    ~Pracivnyk(){};

    friend void sort(Pracivnyk arr[], int n);
    friend float seredniy_stazh(Pracivnyk arr[], int n);
    friend void i_viddil(Pracivnyk arr[], int n);

    friend class Vidpustka;
};

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
            cout<<"Відділ: "<<vidd[r]<<" Працівників: "<<k<<" Загальна зарплата: "<<sum<<endl;
        }
        r++;
        e=true;
    }
}

class Vidpustka {
    Pracivnyk prac;
    string start;
    int term;
    string end;

public:
    Vidpustka() {
        start = "01.07.2021";
    }
    string calcDate(int startDay, int Month, int Year, int days) {
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
    void set(Pracivnyk p) {
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

    void print() {
        cout<<"Працівник: "<< prac.prizv<<", Відділ: "<<prac.viddil<<", Відпустка з "<<start<<" на "<< term <<" днів, до "<<end<<endl;
    }
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
    C[0].sort(C, n);
    cout<<"Масив об'єктів: "<<endl;
    for(i=0;i<n;i++){
        C[i].get_prac();
    }
    cout<<"Середній стаж: "<<seredniy_stazh(C, n)<<" років"<<endl;
    cout<<"Інформація по відділах:"<<endl;
    i_viddil(C, n);

    cout<<"Інформація про відпустки:"<<endl;
    for(i=0;i<n;i++){
        Vidpustka V;
        V.set(C[i]);
        V.print();
    }
    return 0;
    system("pause");
}