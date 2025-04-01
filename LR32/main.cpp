#include <iostream>
#include <clocale>
#include "head.h"
using namespace std;

//g++ -o program main.cpp real.cpp
int main(){
    setlocale(LC_CTYPE, "uk_UA.UTF-8");
    int i,n,r;
    string pr, vdd, npr;
    float zp;
    Pracivnyk A;
    Pracivnyk B("Honchar", "Printing", 2006, 16000);
    A.get_prac();
    B.get_prac();
    cout<<"Enter N: ";
    cin>>n;
    Pracivnyk C[n];
    for(i=0;i<n;i++){
        cout<<"Surname: ";
        cin>>pr;
        cout<<"Department: ";
        cin>>vdd;
        cout<<"Year: ";
        cin>>r;
        cout<<"Salary: ";
        cin>>zp;
        C[i].set_prac(pr, vdd, r, zp);
    }
    cout<<"Array of objects: "<<endl;
    for(i=0;i<n;i++){
        C[i].get_prac();
    }
    cout<<"Surname: ";
    cin>>pr;
    cout<<"Enter new data (Surname, Department, Year, Salary): "<<endl;
    cin>>npr>>vdd>>r>>zp;
    for(i=0;i<n;i++){
        C[i].change(pr, npr, vdd, r, zp);
    }
    cout<<"Array of objects: "<<endl;
    for(i=0;i<n;i++){
        C[i].get_prac();
    }
    system("pause");
    return 0;
}