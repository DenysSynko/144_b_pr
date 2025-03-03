#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;

int main (){
    setlocale(LC_CTYPE,"ukr");
    srand(time(NULL));
    int i, n, j, maxh, minb, *mxh=&maxh, *mnb=&minb, r;
    cout<<"Enter N:";
    cin>>n;
    int a[n][n], **dp;  //ініціалізуємо матрицю, показники і змінні
    int *p[n*n];
	dp=p;
	
	for(i=0;i<n;i++){ //присвоюємо масиву показників значення масиву адрес матриці
		p[i]=a[i];
		
	}

    for(i=0;i<n;i++){ //вводимо значення елементів матриці
		for(j=0;j<n;j++){
			*(*(dp+i)+j)=rand()%110-50;
		}
		
	}

    for(i=0;i<n;i++){ //виводимо матрицю
		for(j=0;j<n;j++){
			cout<< *(*(dp+i)+j)<<"\t";
		}
		cout<<endl;
		
	}
    *mxh=a[0][0];
    for(i=0;i<n;i++){ //знаходимо максимальний ел-т головної діагоналі
		for(j=0;j<n;j++){
			if(*mxh<*(*(dp+i)+j) && i==j){
                *mxh=*(*(dp+i)+j);
            }
		}
		
	}
    cout<<"Максимальний головної = "<<*mxh<<endl;

    *mnb=a[0][n-1];
    for(i=0;i<n;i++){ //знаходимо мінімальний ел-т бічної діагоналі
		for(j=0;j<n;j++){
			if(*mnb>*(*(dp+i)+j) && i+j==n-1){
                *mnb=*(*(dp+i)+j);
            }
		}
		
	}
    cout<<"Мінімальний бічної = "<<*mnb<<endl;
    r=*mxh-*mnb; //знаходимо різницю
    cout<<"Різниця = "<<r<<endl;

    system("pause");
    return 0;
}