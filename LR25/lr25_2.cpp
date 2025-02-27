#include <iostream>
using namespace std;

int main (){
    int i, n;
    cout<<"Enter N: ";
    cin>>n;
    float a[n], *pa; //оголошення масиву і показника
    pa=a; //присвоєння показнику адреси першого ел-та масиву
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){ //вручну вводимо елементи
        cin>>*pa;
        pa++;   //зсув показника
    }
    cout<<endl;
    pa=a;
    for(i=0;i<n-2;i++){ //цикл що виводить комбінації 3х ел-тів, що розміщені за спаданням
        if(*pa>*(pa+1) && *(pa+1)>*(pa+2)){
            cout<<*pa<<" "<<*(pa+1)<<" "<<*(pa+2)<<endl;
        }
        pa++; //зсув показника
    }
    system("pause");
    return 0;
}