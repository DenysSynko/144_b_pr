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
    int a[n][n], **dp, k0=0,  kd=0, kv=0;  //ініціалізуємо матрицю, показники і змінні
    int *p[n*n];
    float serd, *sd=&serd, serv, *sv=&serv, sumd=0, sumv=0;
	
	
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

    for(i=0;i<n;i++){ 
		for(j=0;j<n;j++){
			if(*(*(dp+i)+j)==0){ //рахуємо кількість нулів
                k0++;
            }else if(*(*(dp+i)+j)>0){ //рахуємо кількість додатніх та їх суму
                sumd+=*(*(dp+i)+j);
                kd++;
            }else if(*(*(dp+i)+j)<0){ //рахуємо кількість від'ємних та їх суму
                sumv+=*(*(dp+i)+j);
                kv++;
            }
        }
	}
    *sd=sumd/kd; //рахуємо середні значення
    *sv=sumv/kv;
    
    cout<<"Середнє додатнє: "<<*sd<<" \tСереднє від'ємне: "<<*sv<<" \tКількість нулів: "<<k0<<endl;
    

    system("pause");
    return 0;
}