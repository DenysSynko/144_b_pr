#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;
int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, m, ka=0, kb=0, i;
    cout<<"Enter N, M: ";
    cin>>n>>m;
    float *a = new float[n]; //оголошення динамічного масиву
    float *b = new float[m];
    cout<<"a[] => ";
    for(i=0;i<n;i++){ //введення псевдовипадкових чисел
        a[i]=rand()%11-5;
        cout<<a[i]<<" ";
    }
    cout<<endl<<"b[] => ";
    for(i=0;i<m;i++){ //введення псевдовипадкових чисел
        b[i]=rand()%11-5;
        cout<<b[i]<<" ";
    }

    for(i=0;i<n;i++){ //рахуємо кіль-сть не кратних 3 в масиві "а[]"
        if(int(a[i])%3!=0){
            ka++;
        }
    }
    for(i=0;i<m;i++){ //рахуємо кіль-сть не кратних 3 в масиві "b[]"
        if(int(b[i])%3!=0){
            kb++;
        }
    }
    cout<<endl<<"Кількість не кратних 3 = "<<ka+kb<<endl;
    cout<<"Більше таких чисел в масиві: ";
    if(ka>kb){ //визначаємо в якому з масивів таких чисел більше
        cout<<"a[] => ";
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }else if(kb>ka){
        cout<<"b[] => ";
        for(i=0;i<m;i++){
            cout<<b[i]<<" ";
        }
    }else if(ka==kb){
        cout<<"--порівну в обох масивах--";
    }
    delete[] a; //вивільняємо пам'ять
    delete[] b;
    cout<<endl;
    system("pause");
    return 0;
}