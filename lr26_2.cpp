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
    int a[n][n], **dp;  //ініціалізуємо матрицю, показники і змінні
    int *p[n*n];
	
	for(i=0;i<n;i++){ //присвоюємо масиву показників значення масиву адрес матриці
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
    cout<<endl<<"====================================="<<endl;
    for(i=0;i<n;i++){ //виводимо матрицю
		if(i%2==0){ //парні рядки виводимо зліва на право
            for(j=0;j<n;j++){
                cout<< *(*(dp+i)+j)<<"\t";
            }
        }else{ //непарні рядки виводимо справа на ліво
            for(j=n-1;j>=0;j--){
                cout<< *(*(dp+i)+j)<<"\t";
            }
        }
        cout<<endl;
	}

    system("pause");
    return 0;
}