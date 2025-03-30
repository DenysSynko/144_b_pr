#include <iostream>
#include <clocale>
using namespace std;

class Flat{
    string adressa;
    int poverh, kk;
    float S;
    public:
    Flat() {
        kk = 2;
        S = 55;
    }
    Flat(string adr, int pov, int kilkmnt=2, float S2=55){
        kk=kilkmnt;
        S=S2;
        adressa=adr;
        poverh=pov;
    }
    void set_flat(string adr, int pov){
        adressa=adr;
        poverh=pov;
    }

    void set_flat(string adr, int pov, int kilkmnt, float S2){
        kk=kilkmnt;
        S=S2;
        adressa=adr;
        poverh=pov;
    }

    void get_flat(){
        cout<<"Адреса:"<<adressa<<" Поверх:"<<poverh<<" Кімнат:"<<kk<<" Площа:"<<S<<endl;
    }

    void get_flat_r(int chk){
        if(kk==chk){
            cout<<"Адреса:"<<adressa<<" Поверх:"<<poverh<<" Кімнат:"<<kk<<" Площа:"<<S<<endl;
        }
    }

    void get_flat_floor(int prpov1, int prpov2){
        if(S<40 && prpov1<=poverh && prpov2>=poverh){
            cout<<"Адреса:"<<adressa<<" Поверх:"<<poverh<<" Кімнат:"<<kk<<" Площа:"<<S<<endl;
        }
    }

    ~Flat(){};
};

int main(){
    setlocale(LC_CTYPE, "ukr");
    int i, n, t, pov, kk, chk, prpov1, prpov2;
    float s;
    string adr;
    cout<<"Enter N: ";
    cin>>n;
    Flat *A = new Flat[n];
    Flat B("Кільцева 56", 2);
    Flat C("Соборна 39", 6, 4, 95);
    for(i=0;i<n;i++){
        cout<<"2-кімнатна, 55(м^2)?(1-так, 2-ні): ";
        cin>>t;
        if(t==1){
            cout<<"Адреса: ";
            cin>>adr;
            cout<<"Поверх: ";
            cin>>pov;
            A[i].set_flat(adr,pov);
        }else if(t==2){
            cout<<"Адреса: ";
            cin>>adr;
            cout<<"Поверх: ";
            cin>>pov;
            cout<<"Кількість кімнат: ";
            cin>>kk;
            cout<<"Площа: ";
            cin>>s;
            A[i].set_flat(adr,pov,kk,s);
        }
        
    }
    for(i=0;i<n;i++){
        A[i].get_flat();   
    }
    B.get_flat();
    C.get_flat();
    cout<<"Введіть число кімнат: ";
    cin>>chk;
    cout<<"Квратири з кількістю кімнат ("<<chk<<"): "<<endl;
    for(i=0;i<n;i++){
        A[i].get_flat_r(chk);   
    }
    B.get_flat_r(chk);
    C.get_flat_r(chk);
    cout<<"Введіть проміжок поверхів: ";
    cin>>prpov1>>prpov2;
    cout<<"Квартири до 40(м^2), що розташовані між "<<prpov1<<" та "<<prpov2<<" поверхами включно: "<<endl;
    for(i=0;i<n;i++){
        A[i].get_flat_floor(prpov1, prpov2);   
    }
    B.get_flat_floor(prpov1, prpov2);
    C.get_flat_floor(prpov1, prpov2);
    delete[] A;
    return 0;
}
