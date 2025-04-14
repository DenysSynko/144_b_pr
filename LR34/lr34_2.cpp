#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Matrix {
    int arr[20][20];
    int n;
public:
    void set_matrix(int ne, int a, int b){
        int i, j;
        n=ne;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                arr[i][j]=rand()%(b-a+1)+a;
            }
        }
    }

    void print(){
        int i, j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    friend Matrix operator +(Matrix A, Matrix B);
    friend Matrix operator -(Matrix A, Matrix B);
    friend Matrix operator *(Matrix A, Matrix B);
    friend bool operator ==(Matrix A, Matrix B);
    ~Matrix(){}
};

Matrix operator +(Matrix A, Matrix B){
    int i, j;
    Matrix T;
    T.n=A.n;
    for(i=0;i<A.n;i++){
        for(j=0;j<A.n;j++){
            T.arr[i][j]=A.arr[i][j]+B.arr[i][j];
        }
    }
    return T;
}

Matrix operator -(Matrix A, Matrix B){
    int i, j;
    Matrix T;
    T.n=A.n;
    for(i=0;i<A.n;i++){
        for(j=0;j<A.n;j++){
            T.arr[i][j]=A.arr[i][j]-B.arr[i][j];
        }
    }
    return T;
}

Matrix operator *(Matrix A, Matrix B){
    int i, j, r;
    Matrix T;
    T.n=A.n;
    for(i=0;i<A.n;i++){
        for(j=0;j<A.n;j++){
            T.arr[i][j]=0;
            for(r=0;r<A.n;r++){
                T.arr[i][j]+=A.arr[i][r]*B.arr[r][j];
            }
        }
    }
    return T;
}

bool operator ==(Matrix A, Matrix B){
    int i, j;
    for(i=0;i<A.n;i++){
        for(j=0;j<A.n;j++){
            if(A.arr[i][j]!=B.arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    srand(time(NULL));
    int n, a, b;
    cout<<"Enter N: ";
    cin>>n;
    cout<<"Enter min and max: ";
    cin>>a>>b;
    Matrix A[2];
    A[0].set_matrix(n, a, b);
    A[1].set_matrix(n, a, b);
    cout<<"Matrix A[0]:"<<endl;
    A[0].print();
    cout<<"Matrix A[1]:"<<endl;
    A[1].print();
    Matrix T;
    T=A[0]+A[1];
    cout<<"A[0]+A[1]:"<<endl;
    T.print();
    T=A[0]-A[1];
    cout<<"A[0]-A[1]:"<<endl;
    T.print();
    T=A[0]*A[1];
    cout<<"A[0]*A[1]:"<<endl;
    T.print();
    if(A[0]==A[1]){
        cout<<"A[0]=A[1]"<<endl;
    }else{
        cout<<"A[0]!=A[1]"<<endl;
    }

    system("pause");
    return 0;
}
