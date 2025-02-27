#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int i, n, j, t;
    cout<<"Enter N: ";
    cin>>n;
    int a[n], *pa, *pj;
    pa=a; //присвоєння показнику адреси першого ел-та масиву
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){ // введення ел-тів вручну
        cin>>*pa;
        pa++; // зсув показника
    }
    pa=a;
    for(i=0;i<n;i++){ //сортування
        pj=pa+1; 
        for(j=i+1;j<n;j++){
            if(*pa>*pj && i%2==0 && j%2==0){ //бульбашкове сортування для парних індексів (зростання)
                t=*pj;
                *pj=*pa;
                *pa=t;
            }
            if(*pa<*pj && i%2!=0 && j%2!=0){ //бульбашкове сортування для непарних індексів (спадання)
                t=*pj;
                *pj=*pa;
                *pa=t;
            }
            pj++; // зсув показника
        }
        pa++; // зсув показника
    }
    cout<<"---------------------------------------------------"<<endl;
    pa=a; //присвоєння показнику адреси першого ел-та масиву
    for(i=0;i<n;i++){ 
        cout<<*pa<<" ";
        pa++; // зсув показника
    }
    cout<<endl;
    system("pause");
    return 0;
}