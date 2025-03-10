#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;
void arr_w(float *a, int n){ //тіло функції
    int i, m, r=0, k=0;
    for(i=0;i<n;i++){
        if(int(a[i])%2==0 && i%2!=0){ //рахуємо парні елементи на непарних місцях
            k++;
        }
    }
    m=k;
    int *b = new int[m]; //оголошення динамічного масиву
    for(i=0;i<n;i++){
        if(int(a[i])%2==0 && i%2!=0){ //записуємо ці елементи в новий масив
            b[r]=a[i];
            r++;
        }
    }
    cout<<endl<<"b[] => "; //виводимо новий масив
    for(i=0;i<m;i++){
        cout<<b[i]<<" ";
    }
    delete[] b; //вивільняємо пам'ять

}

int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, i;
    cout<<"Enter N: ";
    cin>>n;
    float *a = new float[n]; //оголошення динамічного масиву
    
    cout<<"a[] => ";
    for(i=0;i<n;i++){ //введення псевдовипадкових чисел
        a[i]=rand()%11-5;
        cout<<a[i]<<" ";
    }
    void (*pa)(float *, int); //вказівник на функцію
    pa=arr_w;
    pa(a, n); //виклик функції через вказівник
    
    delete[] a; //вивільняємо пам'ять
    
    cout<<endl;
    system("pause");
    return 0;
}