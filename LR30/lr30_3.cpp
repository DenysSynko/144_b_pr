#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void func(int a[]){
    int b[8];
    int g[8];
    bool t;
    int i, j, r=0;
    for(i=0;i<8;i++){
        do{
            b[i]=a[rand()%8+0];
            t=false;
            for(j=0;j<r;j++){
                if(b[i]==g[j]){
                    t=true;
                }
            }
            if(!t){
                g[r]=b[i];
                r++;
            }
            
        }while(t);
        cout<<b[i]<<" ";
    }
}

int main(){
    srand(time(NULL));
    int i, j, r=0;
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

    func(a);

    return 0;
}