#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


template <class T1>
class Vec{
    private:
    vector <T1> a;
    public:
    Vec(){
        a = {4, 22, -5, 9, 0, 11, 23, 6, 6, 1};
    }
    Vec(vector <T1> b){
        a = b;
    }
    void setKeyboard(){
        cout<<"Enter elements: ";
        for(int i=0;i<10;i++){
            cin>>a[i];
        }
    }
    void setRand(){
        for(int i=0;i<10;i++){
            a[i]=rand()%21-10;
        }
    }
    void print(){
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void replace(){
        vector <T1> par;
        vector <T1> nepar;
        for(int i=0;i<a.size();i++){
            if(i%2==0){
                par.push_back(a[i]);
            }else{
                nepar.push_back(a[i]);
            }
        }
        a.clear();
        a.insert(a.end(), par.begin(), par.end());
        a.insert(a.end(), nepar.begin(), nepar.end());
    }
    void del(T1 x){
        for(int i=0;i<a.size();i++){
            if(a[i]==x){
                for(int j=i;j<a.size()-1;j++){
                    a[j]=a[j+1];
                }
                a.pop_back();
                i--;
            }
        }
    }
    Vec operator +(Vec B){
        Vec<T1> T;
        T.a.clear();
        for(int i=0;i<B.a.size();i++){
            T.a.push_back(a[i]+B.a[i]);
        }
        return T;
    }
    void operator ++(int){
        for(int i=0;i<a.size();i++){
            a[i]+=10;
        }
    }
    bool operator >(Vec B){
        T1 sum1=0;
        T1 sum2=0;
        for(int i=0;i<a.size();i++){
            sum1+=a[i];
        }
        for(int i=0;i<a.size();i++){
            sum2+=B.a[i];
        }
        return sum1>sum2;
    }
    bool operator <(Vec B){
        T1 sum1=0;
        T1 sum2=0;
        for(int i=0;i<a.size();i++){
            sum1+=a[i];
        }
        for(int i=0;i<a.size();i++){
            sum2+=B.a[i];
        }
        return sum1<sum2;

    }
    bool operator ==(Vec B){
        T1 sum1=0;
        T1 sum2=0;
        for(int i=0;i<a.size();i++){
            sum1+=a[i];
        }
        for(int i=0;i<a.size();i++){
            sum2+=B.a[i];
        }
        return sum1==sum2;
    }
    ~Vec(){};
};

int main(){
    srand(time(NULL));
    Vec<int> obj;
    obj.print();
    obj.replace();
    obj.print();
    obj.del(6);
    obj.print();
    Vec<float> A, B, C;
    A.setKeyboard();
    B.setKeyboard();
    if(A==B){
        cout<<"A=B"<<endl;
    }else if(A>B){
        cout<<"A>B"<<endl;
    }else if(A<B){
        cout<<"A<B"<<endl;
    }
    C=A+B;
    cout<<"Sum: ";
    C.print();
    cout<<endl;
    A++;
    cout<<"A++:";
    A.print();
    cout<<endl;
    return 0;
}