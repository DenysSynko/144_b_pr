#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int h, m, s;
    public:
    void set_time(){
        h=0;
        m=0;
        s=0;
    }
    void set_time(Time A[], int he, int me, int se, int i){
        A[i].h=he;
        A[i].m=me;
        A[i].s=se;
    }
    void print_arr(Time A[], int n){
        int i;
        for(i=0;i<n;i++){
            cout<<setfill('0')<<setw(2)<<A[i].h<<":"<<setw(2)<<A[i].m<<":"<<setw(2)<<A[i].s<<endl;
        }
    }
    void print_obj(){
        cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
    }
    Time operator +(Time C){
        Time T;
        T.h=h+C.h;
        T.m=m+C.m;
        T.s=s+C.s;
        if(T.s>=60){
            T.s-=60;
            T.m++;
        }else if(T.s<0){
            T.s+=60;
            T.m--;
        }
        if(T.m>=60){
            T.m-=60;
            T.h++;
        }else if(T.m<0){
            T.m+=60;
            T.h--;
        }
        if(T.h>=24){
            T.h-=24;
        }else if(T.h<0){
            T.h+=24;
        }
        return T;
    }
    Time operator -(Time C){
        Time T;
        T.h=h-C.h;
        T.m=m-C.m;
        T.s=s-C.s;
        if(T.s>=60){
            T.s-=60;
            T.m++;
        }else if(T.s<0){
            T.s+=60;
            T.m--;
        }
        if(T.m>=60){
            T.m-=60;
            T.h++;
        }else if(T.m<0){
            T.m+=60;
            T.h--;
        }
        if(T.h>=24){
            T.h-=24;
        }else if(T.h<0){
            T.h+=24;
        }
        return T;
    }
    bool operator <(Time C){
        int t1, t2;
        t1=h*3600+m*60+s;
        t2=C.h*3600+C.m*60+C.s;
        if(t1<t2){
            return true;
        }else{
            return false;
        }
    }
    bool operator >(Time C){
        int t1, t2;
        t1=h*3600+m*60+s;
        t2=C.h*3600+C.m*60+C.s;
        if(t1>t2){
            return true;
        }else{
            return false;
        }
    }
    bool operator ==(Time C){
        int t1, t2;
        t1=h*3600+m*60+s;
        t2=C.h*3600+C.m*60+C.s;
        if(t1==t2){
            return true;
        }else{
            return false;
        }
    }
    ~Time(){};

};

int main(){
    int i, n=2, h, m, s;
    Time A[n];
    for(i=0;i<n;i++){
        cout<<"Enter hour, minute and second: ";
        cin>>h>>m>>s;
        A[i].set_time(A, h, m, s, i);
    }
    A[0].print_arr(A, n);
    Time T;
    T=A[0]-A[1];
    cout<<"A[0]-A[1]=";
    T.print_obj();
    T=A[0]+A[1];
    cout<<"A[0]+A[1]=";
    T.print_obj();
    cout<<endl;
    if(A[0]<A[1]){
        cout<<"A[0]<A[1]"<<endl;
    }else if(A[0]>A[1]){
        cout<<"A[0]>A[1]"<<endl;
    }else if(A[0]==A[1]){
        cout<<"A[0]=A[1]"<<endl;
    }
    system("pause");
    return 0;
}