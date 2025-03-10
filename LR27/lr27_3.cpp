#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;
int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, i, k=0, m, r=0, j;
    cout<<"Enter N: ";
    cin>>n;
    float *a = new float[n]; //оголошення динамічного масиву
    cout<<"a[] => ";
    for(i=0;i<n;i++){ //введення псевдовипадкових чисел
        a[i]=rand()%11-5;
        cout<<a[i]<<" ";
    }
    for(i=0;i<n;i++){
        if(int(a[i])%2==0){ //рахуємо парні елементи
            k++;
        }
    }
    m=k;
    float *b = new float[m]; //оголошення динамічного масиву
    for(i=0;i<n;i++){ //сортуємо масив "а[]" за зростанням
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(i=0;i<n;i++){
        if(int(a[i])%2==0){ //записуємо парні елементи в новий масив
            b[r]=a[i];
            r++;
        }
    }
    cout<<endl<<"b[] => "; //виводимо новий масив
    for(i=0;i<m;i++){ 
        cout<<b[i]<<" ";
    }

    delete[] a; //вивільняємо пам'ять
    delete[] b;
    cout<<endl;
    system("pause");
    return 0;
}