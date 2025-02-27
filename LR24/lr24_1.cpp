#include <iostream>
using namespace std;

int main (){
    float a=5, c=3, *p=&a;
    *p=*p*3; //розіменований показник множимо на 3
    *p=*p+c; //до розіменованого показника додаємо с
    p=&c; //присвоюємо показнику адресу с
    cout<<&a<<" "<<&c<<" "<<&p<<" "<<p<<" "<<a<<" "<<c<<" "<<*p<<endl;

    system("pause");
    return 0;
}