#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;

int main (){
    setlocale(LC_CTYPE,"ukr");
    srand(time(NULL));
    int i, n, j;
    cout<<"Enter N:";
    cin>>n;
    int a[n][n], **dp, m[n], *pm, min, *pmin=&min, jm, im; //ініціалізуємо матрицю, показники і змінні
    int *p[n*n];
	
	
	for(i=0;i<n;i++){
		p[i]=a[i];
		
	}
    dp=p;

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
    pm=m;
    for(i=0;i<n;i++){
        *pmin=*(*(dp+i)+0);
        im=i;
        jm=0;
		for(j=0;j<n;j++){
			if(*(*(dp+i)+j)<*pmin){ // знаходимо індекси мінімальних елементів 
                *pmin=*(*(dp+i)+j);
                im=i;
                jm=j;
            }
		}
        cout<<"min #"<<i+1<<" = "<<*pmin<<" i="<<im<<" j="<<jm<<endl;
        *pm=n*im+jm+1; //записуємо порядковий номер в масив за допомогою показника
        pm++; //зсув показника
	}
    cout<<"numbers of minimum elements"<<endl;
    pm=m;
    for(i=0;i<n;i++){ //виводимо порядкові номери (в усій матриці) мінімальних ел-тів кожного рядка
        cout<<*pm<<" ";
        pm++;
    }
    cout<<endl;

    system("pause");
    return 0;
}