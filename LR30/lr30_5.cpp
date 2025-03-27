#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;
int k=0;
int* func(int a[], int b[], ...){
    int *f = new int[20];
    int i;
    for(i=0;i<11;i++){
        if(a[i]!=b[i]){
            f[k]=i;
            k++;
        }
    }
    return f;
}

int main(){
    setlocale(LC_CTYPE, "ukr");
    int a[]={3, 22, 14, 10, 16, 12, 9, 11, 20, 44, 29};
    int b[]={3, 22, 31, 10, 17, 12, 9, 5, 20, 44, 90};
    int* c=func(a, b, 2, 4, 5,  8, 9, 11);
    cout<<"Індекси де не співпадає: ";
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }


    return 0;
}