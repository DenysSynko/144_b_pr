#include <iostream>
using namespace std;

int main (){
    int a, b, c, max, min, *p, *pn, *pa;
    cout<<"Enter a, b, c: ";
    cin>>a>>b>>c;
    max=a;
    p=&max;
    pn=p;
    pn++;
    for(int i=0;i<3;i++){
        if(*p<*pn){
            max=*pn;
            pa=pn;
        }
        pn++;
    }
    cout<<"max = "<<*p<<" address = "<<pa<<endl;

    min=a;
    p=&min;
    pn=p;
    pn++;
    for(int i=0;i<3;i++){
        if(*p>*pn){
            min=*pn;
            pa=pn;
        }
        pn++;
    }
    cout<<"min = "<<*p<<" address = "<<pa<<endl;

    system("pause");
    return 0;
}