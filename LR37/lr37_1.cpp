#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);
int yearNow = 1900 + ltm->tm_year;
vector <string> err;

class Shkoliar{
    protected:
    string pib;
    int year;
    bool sex;
    public:
    Shkoliar(){

    }
    int ageCount(){
        int age = yearNow-year;
        return age;
    }
    ~Shkoliar(){};
};

class Pracivnyk: public Shkoliar{
    int salary;
    string place;
    public:
    Pracivnyk(string pibE, int yearE, bool sexE, int salE, string placeE){
        pib=pibE;
        year=yearE;
        sex=sexE;
        salary=salE;
        place=placeE;
    }
    void print(){
        cout<<"PIB: "<<pib<<" Year: "<<year<<" Age: "<<ageCount()<<" Sex: "<<(sex ? "boy" : "girl")<<" Salary: "<<salary<<" Place: "<<place<<endl;
    }
    ~Pracivnyk(){};
};

int main(){
    Pracivnyk A("Bihus Artem Vitalijovych", 2010, true, 12000, "Cafe");
    A.print();
    return 0;
}