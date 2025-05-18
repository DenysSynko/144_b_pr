#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Figura{

    public:
    virtual void perimeter() = 0;
    virtual void area() = 0;

};

class Circle: public Figura{
    float r;
    public:
    Circle(float rE){
        r=rE;
    }
    void perimeter() override{
        cout<<"Perimeter of circle: "<<2*M_PI*r<<endl;
    }
    void area() override{
        cout<<"Area of circle: "<<M_PI*pow(r, 2)<<endl;
    }
    ~Circle(){};
};

class Rectangle: public Figura{
    float a;
    float b;
    public:
    Rectangle(float aE, float bE){
        a=aE;
        b=bE;
    }
    void perimeter() override{
        cout<<"Perimeter of rectangle: "<<2*(a+b)<<endl;
    }
    void area() override{
        cout<<"Area of rectangle: "<<a*b<<endl;
    }
    ~Rectangle(){};
};

class Triangle: public Figura{
    float a;
    float b;
    float c;
    public:
    Triangle(float aE, float bE, float cE){
        a=aE;
        b=bE;
        c=cE;
    }
    void perimeter() override{
        cout<<"Perimeter of triangle: "<<a+b+c<<endl;
    }
    void area() override{
        float p = (a+b+c)/2;
        float s = sqrt(p*(p-a)*(p-b)*(p-c));
        cout<<"Area of triangle: "<<s<<endl;
    }
    ~Triangle(){};
};


int main(){

    vector <Figura*> figuras;

    figuras.push_back(new Circle(5));
    figuras.push_back(new Rectangle(4, 9));
    figuras.push_back(new Triangle(3, 6, 8));

    for(auto it:figuras){
        it->area();
        it->perimeter();
    }

    for(auto it:figuras){
        delete it;
    }
    
    return 0;
}