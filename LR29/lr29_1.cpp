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
    ifstream file ("text.txt");
    string a;
    string fin;
    cout<<"Введіть слово: ";
    cin>>fin;
    while(file>>a){
        if(size(a)==3){
            s[is]=a;
            is++;
        }
        if(!isupper(a[0])){
            vl[ivl]=a;
            ivl++;
        }
        if(low(a)==low(fin)){
            k++;
        }

    }
    for(i=0;i<is;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<ivl;i++){
        cout<<vl[i]<<" ";
    }
    cout<<endl<<"Кількість знадених слів "<<fin<<" = "<<k<<endl;
    file.close();

    delete[] s;
    delete[] vl;

    system("pause");
    return 0;
}