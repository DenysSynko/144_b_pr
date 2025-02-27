#include <iostream>
using namespace std;

int main (){
    int i, n, k=0;
    cout<<"Enter N: ";
    cin>>n;
    int a[n], *pa; //оголошення масиву і показника
    pa=a; //присвоєння показнику адреси першого ел-та масиву
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){ //введення ел-тів масиву
        cin>>*pa;
        pa++;
    }
    cout<<"Element index: ";
    pa=&a[1]; //присвоєння показнику адреси другого ел-та масиву (індекс 1)

    for(i=1;i<n;i++){
        if(*pa>*(pa-1)){ //підрахунок кількості ел-тів, що більші за лівого сусіда і виведення їх індексів
            k++;
            cout<<i<<" ";
        }
        pa++; //зсув показника
    }
    cout<<"Amount: "<<k<<endl; 


    system("pause");
    return 0;
}