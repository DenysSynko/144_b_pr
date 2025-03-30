#include <iostream>
#include <clocale>
using namespace std;

class People{
    string prizv, kraina, stat, v_osvita;
    int rik, vik;
    public:
    People (){
        kraina = "Україна";
        rik = 2006;
    }
    People (string pr, int st, int v, char osv, string kr="Україна", int r=2006){
        prizv=pr;
        kraina=kr;
        rik=r; 
        vik=v;
        if(st==1){
            stat="ч";
        }else if(st==2){
            stat="ж";
        }
        
        if(osv=='+'){
            v_osvita="є";
        }else{
            v_osvita="немає";
        }
    }
    void set_people(string pr, int st, int v, char osv, string kr="Україна", int r=2006){
        prizv=pr;
        kraina=kr;
        rik=r; 
        vik=v;
        if(st==1){
            stat="ч";
        }else if(st==2){
            stat="ж";
        }
        
        if(osv=='+'){
            v_osvita="є";
        }else{
            v_osvita="немає";
        }
    }
    void get_people(){
        cout<<"Прізвище:"<<prizv<<" Країна:"<<kraina<<" Рік нар.:"<<rik<<" Вік:"<<vik<<" Стать:"<<stat<<" Вища освіта:"<<v_osvita<<endl;
    }
    void get_people_vo(int pv){
        if(v_osvita=="є" && vik>pv){
            cout<<"Прізвище:"<<prizv<<" Країна:"<<kraina<<" Рік нар.:"<<rik<<" Вік:"<<vik<<" Стать:"<<stat<<" Вища освіта:"<<v_osvita<<endl;
        }
    }
    string get_stat(){
        return stat;
    }
    ~People(){};
};

int del(int st, int n, People *A){
    int i, j;
    for(i=0;i<n;i++){
        if((A[i].get_stat()=="ч" && st==1) || (A[i].get_stat()=="ж" && st==2)){
            for(j=i;j<n-1;j++){
                A[j]=A[j+1];
            }
            n--;
            i--;
        }
    }
    return n;
}
int add_start(int n, People C, People *A){
    int i;
    for(i=n;i>0;i--){
        A[i]=A[i-1];
    }
    A[0]=C;
    n++;
    return n;
}

int main(){
    setlocale(LC_CTYPE, "ukr");
    int i, n, t, vik, rik, st, poshuk_vik;
    string pr, kr;
    char osv;
    cout<<"Enter N: ";
    cin>>n;
    People *A = new People[n];
    for(i=0;i<n;i++){
        cout<<"Україна, 2006рн ?(1-так, 2-ні): ";
        cin>>t;
        if(t==1){
            cout<<"Прізвище: ";
            cin>>pr;
            cout<<"Стать(1-чоловік, 2-жінка): ";
            cin>>st;
            cout<<"Вік: ";
            cin>>vik;
            cout<<"Вища освіта(+, -): ";
            cin>>osv;
            A[i].set_people(pr, st, vik, osv);
        }else if(t==2){
            cout<<"Прізвище: ";
            cin>>pr;
            cout<<"Країна: ";
            cin>>kr;
            cout<<"Стать(1-чоловік, 2-жінка): ";
            cin>>st;
            cout<<"Рік народження: ";
            cin>>rik;
            cout<<"Вік: ";
            cin>>vik;
            cout<<"Вища освіта(+, -): ";
            cin>>osv;
            A[i].set_people(pr, st, vik, osv, kr, rik);
        }
    }
    for(i=0;i<n;i++){
        A[i].get_people();
    }
    cout<<"Введіть вік: ";
    cin>>poshuk_vik;
    cout<<"Громадяни з вищою освітою, старші "<<poshuk_vik<<" років: "<<endl;
    for(i=0;i<n;i++){
        A[i].get_people_vo(poshuk_vik);
    }
    cout<<"Видалити осіб (1-чоловічої, 2-жіночої) статі: "<<endl;
    cin>>st;
    n=del(st, n, A);
    cout<<"Список після видалення: "<<endl;
    for(i=0;i<n;i++){
        A[i].get_people();
    }
    People B("Нечипоренко", 1, 26, '+'), C(B);
    n = add_start(n, C, A);
    cout<<"Список після додавання нового об'єкта на початок: "<<endl;
    for(i=0;i<n;i++){
        A[i].get_people();
    }
    delete[] A;
    return 0;
}