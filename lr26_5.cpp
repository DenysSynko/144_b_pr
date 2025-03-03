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
    int a[n][n], **dp, t; //ініціалізуємо матрицю, показники і змінні
    int *p[n*n];
	
	
	for(i=0;i<n;i++){ //присвоюємо масиву показників значення масиву адрес матриці
		p[i]=a[i];
	}
    dp=p;

    for(i=0;i<n;i++){  //вводимо значення елементів матриці
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
    int m=n;
    for(i=0;i<n-1;i++){ //цикл бульбашкового сортування ел-тів головної діагоналі
		for(j=0;j<m;j++){
            if(*(*(dp+i)+i)>*(*(dp+i+j)+i+j)){
                t=*(*(dp+i)+i);
                *(*(dp+i)+i)=*(*(dp+i+j)+i+j);
                *(*(dp+i+j)+i+j)=t;
            }
		}
        m--;
	}
    cout<<endl<<"=============================="<<endl;
    for(i=0;i<n;i++){ //виводимо матрицю
		for(j=0;j<n;j++){
			cout<< *(*(dp+i)+j)<<"\t";
		}
		cout<<endl;
	}

    system("pause");
    return 0;
}