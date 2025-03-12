#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <clocale>
#include <fstream>
using namespace std;
bool if_the_same(int **a, int i, int j){ //тіло функції
    bool b=true;
    if(a[j][i]%10 == (a[j][i]/10)%10){ //перевірка чи цифри повторюються
        b=false;
    }
    return b;
}
int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    bool b=true;
    int n, i, j, s=0;
    cout<<"Enter N: ";
    cin>>n;
    int **a = new int*[n]; //оголошення динамічного масиву
    
    for(i=0;i<n;i++){
        a[i]=new int[n];
    }
    for(i=0;i<n;i++){ //вводимо псевдовипадкові елементи в матрицю
        for(j=0;j<n;j++){
            a[i][j]=rand()%90+10;
        }
    }
    cout<<"a[] => "<<endl;
    for(i=0;i<n;i++){ //виводимо матрицю
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++){ //робимо перевірку через функцію і рахуємо суми стовпців
        for(j=0;j<n;j++){
            if(!if_the_same(a, i, j)){
                b=false;
            }
        }
        if(b){
            for(j=0;j<n;j++){
                s+=a[j][i];
            }
            cout<<"Сума ел-тів стовпця №"<<i+1<<": "<<s<<endl;
            s=0;
        }
        b=true;
    }
    
    delete[] a; //вивільняємо пам'ять
    cout<<endl;
    system("pause");
    return 0;
}