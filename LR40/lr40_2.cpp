#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string n, double p) {
        name = n;
        price = p;
    }

    virtual double getPrice(){
        return price;
    }

    void show(){
        cout<<"Назва: "<<name<<endl;
        cout<<"Ціна без знижки: "<<price<<" грн"<<endl;
    }
};

class DiscountedProduct : public Product {
    double (*discountFunc)(double);

public:
    DiscountedProduct(string n, double p) : Product(n, p){}
    void setDiscount(auto func){
        discountFunc = func;
    }
    double getPrice() override{
        if (discountFunc) {
            return discountFunc(price);
        } else {
            return price;
        }
    }
    void showWithDiscount(){
        show();
        cout<<"Ціна зі знижкою: "<<getPrice()<<" грн"<<endl;
    }
};

int main(){
    vector<DiscountedProduct> products{
        DiscountedProduct("Стіл", 3000),
        DiscountedProduct("Диван", 13000),
        DiscountedProduct("Шафа", 10000)
    };
    for(auto& p:products) {
        p.setDiscount([](double currentPrice) {
            return currentPrice*0.85;
        });
        p.showWithDiscount();
        cout<<"-------------------"<<endl;
    }

    return 0;
}

