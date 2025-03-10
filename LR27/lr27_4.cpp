#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;
int s_min_max(int *a, int i){ //тіло функції
    int min, max, sum, t;
    max=a[0];
    for(t=0;t<i;t++){ //знаходження максимального 
        if(max<a[t]){
            max=a[t];
        }
    }
    min=a[0];
    for(t=0;t<i;t++){ //знаходження мінімального
        if(min>a[t]){
            min=a[t];
        }
    }
    sum = min+max;
    return sum; //повертаємо значення суми
}

int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, i, j, sum;
    cout<<"Enter N: ";
    cin>>n;
    int *a = new int[n*2]; //оголошення динамічного масиву
    
    cout<<"a[] => ";
    for(i=0;i<n;i++){ //заповнення псевдовипадковими числами [-2;3]
        a[i]=rand()%6-2;
        cout<<a[i]<<" ";
    }
    
    for(i=1;i<n;i++){
        if(a[i]<0){
            sum = s_min_max(a, i);

            for(j=n;j>i;j--){ //вставка cуми мінімуму і максимуму перед від'ємними
                a[j]=a[j-1];
            }
            
            a[i]=sum;
            i++;
            n++;
        }
        
    }
    cout<<endl<<"a[] => ";
    for(i=0;i<n;i++){ //виведення масиву
        cout<<a[i]<<" ";
    }
    
    
    
    delete[] a; //вивільняємо пам'ять
    
    cout<<endl;
    system("pause");
    return 0;
}