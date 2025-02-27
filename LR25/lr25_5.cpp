#include <iostream>
using namespace std;

int main (){ 
    int i, n, j, s=0;
    cout<<"Enter N: ";
    cin>>n;
    int a[n*2], *pa, *pj, *ps; //оголошуємо масив і необхідні показники
    pa=a; //присвоюємо показнику перший ел-т масиву
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++){ //вводимо вручну елементи
        cin>>*pa;
        pa++; //зсув показника
    }

    pa=a;
    for(i=0;i<n;i++){ //цикл для знаходження ел-тів %5
        if(*pa%5==0){ //перевірка умови %5
            ps=a;
            s=0;
            for(j=0;j<i;j++){ //сумма ел-тів, що стоять перед ел-том, що відповідає умові
                s=s+*ps;
                ps++;
            }
            for(j=n;j>i+1;j--){ //цикл для вставки елемента
                pj=&a[j];
                *pj=*(pj-1);
                pj--;
            }
            pa++;
            i++;
            *pa=s; //вставка суми
            n++;
        }
        pa++;
    }
    cout<<endl;
    pa=a;
    for(i=0;i<n;i++){ //виведення масиву
        cout<<*pa<<" ";
        pa++;
    }
    

    system("pause");
    return 0;
}