#include <iostream>
using namespace std;

int main (){
    int i, n, k=0;
    cout<<"Enter N: ";
    cin>>n;
    int a[n], *pa; // оголошення масиву і показника
    pa=a; //присвоєння показнику адреси першого ел-та масиву
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){ // ведення ел-тів вручну
        cin>>*pa;
        pa++; // зсув показника
    }
    pa=a; 
    cout<<"Addresses: ";
    for(i=0;i<n;i++){
        if(*pa<0){ //знаходження кількості ел-тів менших за 0
            k++;
            cout<<pa<<" "; //виведення адрес цих елементів за допомогою показника
        }
        pa++;
    }
    cout<<"Amount: "<<k<<endl;


    system("pause");
    return 0;
}