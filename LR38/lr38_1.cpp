#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
template <typename T>
void numEqualToFirst(T* arr, int n){
    T f=*(arr);
    int i, k=0;
    for(i=1;i<n;i++){
        if(f==*(arr+i)){
            k++;
        }
    }
    cout<<"The number of equals to the first: "<<k<<endl;
}
template <typename T>
void exchange(T* arr, int i_1, int i_2){
    T temp = *(arr+i_1);
    *(arr+i_1) = *(arr+i_2);
    *(arr+i_2) = temp;
}
template <typename T>
void insert(T* arr, T el, int& n,  int pos){
    int i, j;
    for(i=0;i<n;i++){
        if(i==pos){
            for(j=n+1;j>i;j--){
                *(arr+j)=*(arr+j-1);
            }
            *(arr+i)=el;
            n=n+1;
        }
    }
}
template <typename T>
void maxSection(T* arr, int n){
    int i, k=1;
    T temp=*arr;
    vector <T> num;
    num.push_back(temp);
    vector <T> top;
    for(i=1;i<n;i++){
        if(*(arr+i)==temp){
            num.push_back(*(arr+i));
        }else{
            temp=*(arr+i);
            if(num.size()>top.size()){
                top.clear();
                top = num;
                num.clear();
            }else{
                num.clear();
            }
            num.push_back(temp);
        }
    }
    if (num.size() > top.size()) {
        top = num;
    }
    cout<<"Max section: ";
    for(auto it:top){
        cout<<it<<" ";
    }
    cout<<endl;
}
template <typename T>
void sortArr(T* arr, int n){
    T min, max;
    int min_i, max_i;
    int i;
    max=*arr;
    max_i=0;
    for(i=1;i<n;i++){
        if(max<*(arr+i)){
            max=*(arr+i);
            max_i=i;
        }
    }
    min=*arr;
    min_i=0;
    for(i=1;i<n;i++){
        if(min>*(arr+i)){
            min=*(arr+i);
            min_i=i;
        }
    }
    bool b = max_i>min_i;
    vector <T> el_for_sort;
    for(i=0;i<n;i++){
        if(i>(b?min_i:max_i) && i<(b?max_i:min_i)){
            el_for_sort.push_back(*(arr+i));
        }
    }
    sort(el_for_sort.begin(), el_for_sort.end());
    int r=0;
    for(i=0;i<n;i++){
        if(i>(b?min_i:max_i) && i<(b?max_i:min_i)){
            *(arr+i)=el_for_sort[r];
            r++;
        }
    }
}
template <typename T>
void print(T* arr, int n){
    int i;
    cout<<"arr[] = ";
    for(i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

int main(){
    srand(time(NULL));
    int i_1, i_2, el, pos;
    char el_ch;
    int n=10;
    int arr[n*2]={90, 25, 31, 31, 31, 18, 90, 90, 60, 44};
    char arr1[n*2]={'a', 'b', 'a', 'p', 'p', 'y', 'y', 'y', 'a', 'b'};
    print(arr, n);
    numEqualToFirst(arr, n);
    cout<<"Enter indexes: ";
    cin>>i_1>>i_2;
    exchange(arr, i_1, i_2);
    print(arr, n);
    cout<<"Enter element and pos: ";
    cin>>el>>pos;
    insert(arr, el, n, pos);
    print(arr, n);
    maxSection(arr, n);
    sortArr(arr, n);
    print(arr, n);
    n=10;
    print(arr1, n);
    numEqualToFirst(arr1, n);
    cout<<"Enter indexes: ";
    cin>>i_1>>i_2;
    exchange(arr1, i_1, i_2);
    print(arr1, n);
    cout<<"Enter element and pos: ";
    cin>>el_ch>>pos;
    insert(arr1, el_ch, n, pos);
    print(arr1, n);
    maxSection(arr1, n);
    sortArr(arr1, n);
    print(arr1, n);
    return 0;
}