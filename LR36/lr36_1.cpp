#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);
int yearNow = 1900 + ltm->tm_year;
vector <string> err;
class Worker{
    protected:
        int age;
        int exp;
    public:
        string surname;
    Worker(){}
    Worker(int ageE, int expE, string surnameE){
        age=ageE;
        exp=expE;
        surname=surnameE;
    }
    void setWorker(int ageE, int expE, string surnameE){
        age=ageE;
        exp=expE;
        surname=surnameE;
    }
    void printW(){
        cout<<"Surname: "<<surname<<" Age: "<<age<<" Expirience: "<<exp<<endl;
    }
    int getStartYear(){
        int sY = yearNow - exp;
        return sY;
    }
    ~Worker(){};
};

class Car{
    private:
        int mile;
    protected:
        int yearRel;
    public:
        int num;
        string mark;
    Car(){}
    Car(int mileE, int yearRelE, int numE, string markE){
        mile=mileE;
        yearRel=yearRelE;
        num=numE;
        mark=markE;
    }
    void setCar(int mileE, int yearRelE, int numE, string markE){
        mile=mileE;
        yearRel=yearRelE;
        num=numE;
        mark=markE;
    }
    void printC(){
        cout<<"Mark: "<<mark<<" num: "<<num<<" year: "<<yearRel<<" miles: "<<mile<<endl;
    }
    float getEverMile(){
        float carAge=yearNow-yearRel;
        float eM;
        if(carAge!=0){
            eM=mile*1.0/carAge*1.0;
        }else{
            err.push_back("Division by zero!");
        }
        return eM;
    }
    int getMile(){
        return mile;
    }
};

class Driver: public Car, public Worker{
    public: 
        int avtoYear;
        bool penalty;
        Driver(){}
        Driver(int ageE, int expE, string surnameE, int mileE, int yearRelE, int numE, string markE, int avtoYearE, bool penaltyE){
            age=ageE;
            exp=expE;
            surname=surnameE;
            setCar(mileE, yearRelE, numE, markE);
            avtoYear=avtoYearE;
            penalty=penaltyE;
        }
        void setDriver(int ageE, int expE, string surnameE, int mileE, int yearRelE, int numE, string markE, int avtoYearE, bool penaltyE){
            if(ageE<0 || expE<0 || mileE<0 || yearRelE<0 || numE<0 || avtoYearE<0){
                err.push_back("Negative values are not allowed!");
            }
            age=ageE;
            exp=expE;
            surname=surnameE;
            setCar(mileE, yearRelE, numE, markE);
            avtoYear=avtoYearE;
            penalty=penaltyE;
        }
        void printD(){
            cout<<"Driver: "<<surname<<" Age: "<<age<<" Exp: "<<exp<<" Start year: "<<getStartYear()<<" Start using car: "<<avtoYear<<" Penalty: "<<(penalty ? "yes" : "no")<<endl<<" Mark: "<<mark<<" Num: "<<num<<" Car year: "<<yearRel<<" Miles: "<<getMile()<<" Everage for year: "<<getEverMile()<<endl;
        }
        void compareAgeExp(){
            int carAge=yearNow-yearRel;
            if(carAge>exp){
                cout<<"Car is older than driver’s experience."<<endl;
            } else if (carAge<exp){
                cout<<"Driver’s experience is bigger than car’s age."<<endl;
            } else {
                cout<<"Driver’s experience equals car’s age."<<endl;
            }
        }
};

int main(){
    Driver d;
    d.setDriver(30, 10, "Ivanov", 120000, 2010, 12345, "Toyota", 2015, true);
    d.printD();
    d.compareAgeExp();
    int age, exp, mile, yearRel, num, avtoYear, r;
    string surname, mark;
    bool penalty;
    cout<<"Enter: surname, age, exp, avtoYear -> ";
    cin>>surname>>age>>exp>>avtoYear;
    cout<<"Does driver has penalty?: (1-yes, 2-no) -> ";
    cin>>r;
    cout<<"Enter: mark, yearRel, miles, num -> ";
    cin>>mark>>yearRel>>mile>>num;
    if(r==1){
        penalty=true;
    }else{
        penalty=false;
    }

    try{
        d.setDriver(age, exp, surname, mile, yearRel, num, mark, avtoYear, penalty);
        d.printD();
        d.compareAgeExp();
    }
    catch(vector <string> err){
		cout<<"Errors!"<<endl;
		for(string i:err){
			cout<<i<<endl;
		}
	}

    return 0;
}
