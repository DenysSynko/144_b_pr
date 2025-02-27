#include <iostream>
using namespace std;

int main (){
    float m[4], ser, *ps=&ser, *pm, s=0, max, min, *pmax=&max, *pmin=&min, imax, imin;
    int i, j;
    bool u=true;
    for(i=0;i<4;i++){
        u=true;
        cout<<"Enter a number "<<i+1<<": ";
        cin>>m[i];
        for(j=0;j<4;j++){
            if(m[i]==m[j] && i!=j){ //перевірка унікальності
                u=false;
            }
        }
        if(u){
            cout<<"Number is unique"<<endl;
        }else{
            cout<<"Number is non-unique"<<endl;
        }
    }
    pm=m;
    for(i=0;i<4;i++){ //знаходимо суму з використанням показника, що обходить масив
        s=s+*pm;
        pm++; //зміщення показника
    }
    *ps=s/4; //знаходимо середнє арифметичне
    cout<<"arithmetic average: "<<*ps<<endl;
    pm=m;
    *pmax=*pm;
    for(i=0;i<4;i++){ 
        if(*pm>*pmax){ //знаходимо індекс максимального елемента
            *pmax=*pm;
            imax=i;
        }
        pm++;
    }
    pm=m;
    *pmin=*pm;
    for(i=0;i<4;i++){
        if(*pm<*pmin){ //знаходимо індекс мінімального елемента
            *pmin=*pm;
            imin=i;
        }
        pm++;
    }
    pm=m;
    for(i=0;i<4;i++){
        if(i!=imax && i!=imin){
            cout<<*pm<<"  "; //виводимо елементи що не є максимальними чи мінімальними
        }
        pm++;
    }

    system("pause");
    return 0;
}