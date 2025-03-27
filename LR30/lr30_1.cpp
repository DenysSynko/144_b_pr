#include <iostream>
using namespace std;
int par=0, nepar=0;
bool even;
void vvesty(int a[],int n){
    int i;
    cout<<"Enter numbers: ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
}
void vyvesty(int a[],int n, bool b){
    int i;
    if(b){
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }else{
        for(i=0;i<n;i++){
            cout<<a[i]<<endl;
        }
    }
    cout<<endl;
}
int del_max_min(int a[],int n){
    int i, r, j, max, min;
    max= a[0];
    for(i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    min= a[0];
    for(i=0;i<n;i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    cout<<"max: "<<max<<endl;
    cout<<"min: "<<min<<endl;
    for(i=0;i<n;i++){
        if(a[i]==max){
            for(r=i+1;r<n;r++){
                if(a[r]==max){
                    for(j=r;j<n;j++){
                        a[j]=a[j+1];
                    }
                    n--;
                    i--;
                }
            }
            
        }
    }
    for(i=0;i<n;i++){
        if(a[i]==min){
            for(r=i+1;r<n;r++){
                if(a[r]==min){
                    for(j=r;j<n;j++){
                        a[j]=a[j+1];
                    }
                    n--;
                    i--;
                }
            }
            
        }
    }
    return n;
}
void min_to_start(int a[],int n){
    int i, j, min, mi;
    min= a[0];
    mi=0;
    for(i=0;i<n;i++){
        if(min>a[i]){
            min=a[i];
            mi=i;
        }
    }
    
    for(j=0;j<mi;j++){
        a[n]=a[j];
        n++;
    }
    
        
    for(i=0;i<n;i++){
        if(i!=mi){
            for(j=0;j<n-1;j++){
                a[j]=a[j+1];
            }
            n--;
        }else{
            break;
        }
    }

}

int del_after_max(int a[],int n){
    int i, r, mi, max, min;
    max= a[0];
    mi=0;
    for(i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
            mi=i;
        }
    }
    cout<<"Max: "<<max<<" mi="<<mi<<endl;
    n=mi+1;
    return n;
}
int* crArr(int a[],int n){
    int i, j=0, k=0;
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            par++;
        }else{
            nepar++;
        }
    }
    int *bnep = new int[nepar];
    int *bp = new int[par];

    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            bp[j++] = a[i];
        } else {
            bnep[k++] = a[i];
        }
    }

    if(nepar>par){
        return bnep;
        even=false;
    }else{   
        return bp;
        even=true;
    }
    
}

int main(){
    int i, n, t;
    bool b, p=true;
    cout<<"Enter N: ";
    cin>>n;
    int a[2*n];
    void (*p1)(int [], int);
    int (*p3)(int [], int);
    p1=vvesty;
    p1(a,n);
    void (*p2)(int [], int, bool);
    while(p){
        cout<<"Вивести в стовпець чи рядок?(1-рядок, 2-стовпець): ";
        cin>>t;
        if(t==1){
            b=true;
            p=false;
        }else if(t==2){
            b=false;
            p=false;
        }
    }
    p2=vyvesty;
    p2(a,n,b);
    p3=del_max_min;
    n=p3(a, n);
    p2(a,n,b);
    p1=min_to_start;
    p1(a, n);
    p2(a,n,b);
    p3=del_after_max;
    n=p3(a,n);
    p2(a,n,b);
    int* arr = crArr(a, n);
    cout<<"Новий масив: ";
    if(even){
        for(i=0;i<par;i++){
            cout<<arr[i]<<" ";
        }
    }else{
        for(i=0;i<nepar;i++){
            cout<<arr[i]<<" ";
        }
    }


    return 0;
}