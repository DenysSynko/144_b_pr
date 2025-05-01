#include <iostream>
using namespace std;

class Engine {
protected:
    int power;
    int num;
public:
    Engine(){
        power=0;
        num=0;
    }
    Engine(int powerE, int numE){
        power=powerE;
        num=numE;
    }
    void setE(int powerE, int numE) {
        power=powerE;
        num=numE;
    }
    void printE(){
        cout<<"Num: "<<num<<" Power: "<<power<<endl;
    }
    ~Engine(){}
};

class Car : public Engine {
protected:
    string mark;
    int price;
public:
    Car() {
        mark="";
        price=0;
    }
    Car(string markE, int priceE, int powerE, int numE) : Engine(powerE, numE) {
        mark=markE;
        price=priceE;
    }
    void setC(string markE, int priceE, int powerE, int numE){
        mark=markE;
        price=priceE;
        setE(powerE, numE);
    }
    void printC(){
        printE();
        cout<<"Mark: "<<mark<<" Price: "<<price<<endl;
    }
    ~Car(){}
};

class Truck : public Car {
    int maxkg;
public:
    Truck() {
        maxkg = 0;
    }
    Truck(string markE, int priceE, int powerE, int numE, int maxkgE) : Car(markE, priceE, powerE, numE){
        maxkg=maxkgE;
    }
    void setV(string markE, int priceE, int powerE, int numE, int maxkgE){
        setC(markE, priceE, powerE, numE);
        maxkg=maxkgE;
    }
    void printV() {
        printC();
        cout<<"MaxKG: "<<maxkg<< endl;
    }
    ~Truck(){}
};

int main() {
    int i;
    cout<<"=== Array of engines ===\n";
    Engine engines[3]={
        Engine(100, 374378),
        Engine(120, 237484),
        Engine(150, 998376)
    };
    for(i=0;i<3;i++){
        engines[i].printE();
    }
    cout<<"\n=== Array of cars ===\n";
    Car cars[3]={
        Car("Toyota", 30000, 130, 587584),
        Car("Suzuki", 45000, 160, 236536),
        Car("Ford", 28000, 140, 190938)
    };
    for(i=0;i<3;i++) {
        cars[i].printC();
    }
    cout<<"\n=== An array of trucks ===\n";
    Truck vants[3]={
        Truck("Iveco", 60000, 180, 348794, 8000),
        Truck("MAN", 70000, 200, 109838, 10000),
        Truck("DAF", 65000, 190, 948855, 9000)
    };
    for(i=0;i<3;i++){
        vants[i].printV();
    }

    return 0;
}