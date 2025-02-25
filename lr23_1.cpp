#include <iostream>
using namespace std;

int main (){
    float a=5, c=3, *p=&a;
    *p=*p*3;
    *p=*p+c;
    p=&c;
    cout<<&a<<" "<<&c<<" "<<&p<<" "<<p<<" "<<a<<" "<<c<<" "<<*p<<endl;

    system("pause");
    return 0;
}