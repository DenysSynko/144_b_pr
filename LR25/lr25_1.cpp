#include <iostream>
using namespace std;

int main (){
    int i, n;
    cout<<"Enter N:";
    cin>>n;
    int a[n], *pa, min, *pm=&min;
    cout<<"Enter numbers: "<<endl;
    pa=a;
    for(i=0;i<n;i++){ // вручну вводимо елементи масиву
        cin>>*pa;
        pa++;
    }
    pa=a;
    for(i=0; i<n; i++){ //знаходимо перший парний елемент і записуємо його значення у мінімум
        if(*pa%2==0){
            *pm=*pa;
            break;
        }
        pa++;
    }

    pa=a;
    for(i=0;i<n;i++){
        if(*pm>*pa && *pa%2==0){ //знаходимо мінімальний елемент серед парних
            *pm=*pa;
        }
        pa++;
    }
    cout<<"min (%2): "<<min<<endl; //виводимо значення мінімального парного елемента

    system("pause");
    return 0;
}