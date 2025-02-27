#include <iostream>
using namespace std;

int main (){
    int i, n, j, s=0;
    cout<<"Enter N: ";
    cin>>n;
    int a[n*2], *pa, *pj, *pj1, *ps;
    pa=a;
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){
        cin>>*pa;
        pa++;
    }

    pa=a;
    for(i=0;i<n;i++){
        if(*pa%5==0){
            ps=a;
            s=0;
            // for(j=0;j<i;j++){
            //     s=s+*ps;
            //     ps++;
            // }
            for(j=n;j>i+1;j--){
                // pj=&a[j];
                // pj1=pj-1;
                // *pj=*pj1;
                // pj--;
                a[j]=a[j-1];
            }
            pa++;
            *pa=100;
            n++;
        }
        pa++;
    }
    cout<<endl;
    pa=a;
    for(i=0;i<n;i++){
        cout<<*pa<<" ";
        pa++;
    }
    

    system("pause");
    return 0;
}