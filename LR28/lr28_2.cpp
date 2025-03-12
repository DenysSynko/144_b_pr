#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <clocale>
#include <fstream>
using namespace std;
int k_st(int **a, int n){ //тіло функції
    int i, j, k=0;
    bool b=true;
    for(i=0;i<n;i++){ //знаходимо кількість стовпців, що впорядковані за спаданням
        for(j=0;j<n-1;j++){
            if(a[j][i]<=a[j+1][i]){
                b=false;
            }
        }
        if(b){
            k++;
        }
        b=true;
    }
    return k;
}

int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, i, j;
    cout<<"Enter N: ";
    cin>>n;
    int **a = new int*[n]; //оголошення динамічного масиву
    
    for(i=0;i<n;i++){
        a[i]=new int[n];
    }
    for(i=0;i<n;i++){ //вводимо елементи
        cout<<"Введіть рядок №"<<i+1<<": "<<endl;
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    
    cout<<"Кількість стовпців, що впорядковані за спаданням: "<<k_st(a, n)<<endl;
    

    
    delete[] a; //вивільняємо пам'ять
    cout<<endl;
    system("pause");
    return 0;
}