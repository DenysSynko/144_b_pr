#include <iostream>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <clocale>
#include <fstream>
using namespace std;
int main(){
    setlocale(LC_CTYPE, "ukr");
    srand(time(NULL));
    int n, i, j, k=0;
    float ser, s=0;
    cout<<"Enter N: ";
    cin>>n;
    int **a = new int*[n]; //оголошення динамічного масиву
    
    for(i=0;i<n;i++){
        a[i]=new int[n];
    }
    for(i=0;i<n;i++){ //вводимо ел-ти матриці
        for(j=0;j<n;j++){
            a[i][j]=rand()%11-5;
        }
    }
    cout<<"a[] => "<<endl;
    for(i=0;i<n;i++){ //виводимо матрицю
        for(j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++){ //рахуємо суму ел-тів матриці
        for(j=0;j<n;j++){
            s+=a[i][j];
        }
    }
    ser=s/pow(n, 2); //знаходимо середнє арифметичне
    int *b = new int[n]; //оголошуємо новий динамічний масив
    cout<<"Середнє арифметичне: "<<ser<<endl;
    for(i=0;i<n;i++){ //виводимо кількість ел-тів, що більші за сер. ар. в кожному рядку
        cout<<"Кількість ел-тів більших за сер. ар. в рядку №"<<i+1<<": ";
        for(j=0;j<n;j++){
            if(a[i][j]>ser){
                k++;
            }
        }
        cout<<k<<endl;
        b[i]=k; //записуємо кількості в масив
        k=0;
    }
    ofstream file ("lr28_1.txt"); //створюємо текстовий файл
    for(i=0;i<n;i++){ //записуємо в нього попередню відповідь з використанням нового масиву
        file<<"Кількість ел-тів більших за сер. ар. в рядку №"<<i+1<<": "<<b[i]<<endl;
    }
    file.close();

    
    delete[] a; //вивільняємо пам'ять
    delete[] b;
    cout<<endl;
    system("pause");
    return 0;
}