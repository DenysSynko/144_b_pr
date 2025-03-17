#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string low(string x){
    x[0]=tolower(x[0]);
    return x;
}

int main(){
    int n, i, is=0, ivl=0, k=0;
    string *s = new string[50]; 
    string *vl = new string[50];
    ifstream file ("text.txt"); //відкриваємо файл
    string a;
    string fin;
    cout<<"Введіть слово: ";
    cin>>fin; //записуємо слово для пошуку
    while(file>>a){ //зчитуємо файл
        if(a.length()==3){ //якщо слово містить 3 літери записуємо його в масив
            s[is]=a;
            is++;
        }
        if(!isupper(a[0])){ //якщо слово починається з маленької літери записуємо в масив
            vl[ivl]=a;
            ivl++;
        }
        if(low(a)==low(fin)){ //знаходимо кількість шуканих слів
            k++;
        }

    }
    cout<<"Слова, що містять 3 літери: ";
    for(i=0;i<is;i++){ //виводимо масиви
        cout<<s[i]<<" ";
    }
    cout<<endl;
    cout<<"Слова, що починається з маленької літери: ";
    for(i=0;i<ivl;i++){
        cout<<vl[i]<<" ";
    }
    cout<<endl<<"Кількість знадених слів "<<fin<<" = "<<k<<endl;
    file.close();

    delete[] s; //вивільнюємо пам'ять
    delete[] vl;

    system("pause");
    return 0;
}