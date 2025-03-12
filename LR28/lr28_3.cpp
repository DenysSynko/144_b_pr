#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <clocale>
#include <fstream>
using namespace std;
void sort(int *a, int n){ //тіло функції
    int i, j;
    for(i=0;i<n;i++){ //бульбашкове сортування рядка
        for(j=i+1;j<n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
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
    for(i=0;i<n;i++){ //вводимо псевдовипадкові елементи в матрицю
        for(j=0;j<n;j++){
            a[i][j]=rand()%901+100;
        }
    }
    cout<<"a[] => "<<endl;
    for(i=0;i<n;i++){ //виводимо матрицю
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"===================================="<<endl;
    
    for(i=0;i<n;i++){ //сортуємо рядки через функцію
        sort(a[i], n);
    }
    ofstream file ("lr28_3.txt"); //створюємо текстовий файл 
    for(i=0;i<n;i++){ //записуємо в нього матрицю
        for(j=0;j<n;j++){
            file<<a[i][j]<<"\t";
        }
        file<<endl;
    }
    file.close();
    for(i=0;i<n;i++){ //виводимо відсортовану матрицю
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    delete[] a; //вивільняємо пам'ять
    cout<<endl;
    system("pause");
    return 0;
}