#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int* arr_w(int n, ...) {
    int *b = new int[7];
    va_list arg_list;
    va_start(arg_list,n);

    for(int i=0;i<n;i++){
        b[i]=va_arg(arg_list, int);
    }

    va_end(arg_list);
    return b;
}

int main(){
    srand(time(NULL));
    int i, r=0, j;
    int a[12];
    int c[12];
    bool t;
    for(i=0;i<12;i++){
        do{
            a[i]=rand()%50+1;
            t=false;
            for(j=0;j<r;j++){
                if(a[i]==c[j]){
                    t=true;
                }
            }
            if(!t){
                c[r]=a[i];
                r++;
            }
            
        }while(t);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int* b = arr_w(7, a[4], a[5], a[6], a[7], a[8], a[9], a[10]);

    cout<<"Масив b: ";
    for (int i = 0; i < 7; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}