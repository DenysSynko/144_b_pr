#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Worker{
    protected:
    int kod;
    string surname;
    public:

    Worker(int kodE, string surE){
        kod=kodE;
        surname=surE;
    }
    virtual void calc()=0;
    int getKod() const {
        return kod;
    }
    string getSurname() const {
        return surname;
    }
    bool operator==(Worker& T){
        return kod == T.kod;
    }
    
    ~Worker(){};
};

class Manager: public Worker{
    protected:
    int kw;
    float rate;
    public:
    Manager(int kwE, float rateE, int kodE, string surE):Worker(kodE, surE){
        kw=kwE;
        rate=rateE;
    }
    void calc()override{
        bool b=false;
        if(kw>5){
            b=true;
        }
        cout<<" Salary: "<<rate+(b?rate*0.1:0)<<endl;
    }
    ~Manager(){};
};

class Developer: public Worker{
    protected:
    int kh;
    float rate;
    public:
    Developer(int khE, float rateE, int kodE, string surE):Worker(kodE, surE){
        kh=khE;
        rate=rateE;
    }
    void calc()override{
        cout<<" Salary: "<<kh*rate<<endl;
    }
    ~Developer(){};
};

int main(){
    bool u=true;
    int n, i, c, kh, kw, kod;
    float rate;
    string sur;
    vector <Worker*> workers;
    Worker* T;
    cout<<"Enter N: ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Worker (1-manager, 2-developer): ";
        cin>>c;
        if(c==1){
            cout<<"Enter the number of subordinates, rate, code, and surname: ";
            cin>>kw>>rate>>kod>>sur;
            workers.push_back(new Manager(kw,rate,kod,sur));
        }else if(c==2){
            cout<<"Enter the number of hours, rate, code, and surname: ";
            cin>>kh>>rate>>kod>>sur;
            workers.push_back(new Developer(kh, rate, kod,sur));
        }
    }

    for(auto it:workers){
        cout<<"Surname: "<<it->getSurname();
        it->calc();
        if(!u){
            if(*it == *T){
                cout<<"Code is not unique"<<endl;
            }else{
                cout<<"Code is unique"<<endl;
            }
        }else{
            cout<<"Code is unique"<<endl;
        }
        T=it;
        u=false;
        cout<<endl<<"--------------------------------"<<endl;
    }

    for(auto it:workers){
        delete it;
    }
    return 0;
}