#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Notification{
protected:
    string title;
    string message;
public:
    Notification(string t, string m){
        title = t;
        message = m;
    }
    void showNot(){
        cout<<"Заголовок: "<<title<<endl;
        cout<<"Повідомлення: "<<message<<endl;
    }
};

class Importance : public Notification{
    int priority;
    void (*validation)();

public:
    Importance(string t, string m, int p): Notification(t, m){
        priority=p;
    }
    void setFunc(auto func){
        validation = func;
    }
    void showLevel(){
        showNot();

        cout<<"Рівень важливості: ";
        if(priority == 1){ 
            cout<<"Високий"<<endl;
        }else if (priority == 2){ 
            cout<<"Середній"<<endl;
        }else if (priority == 3){ 
            cout<<"Низький"<<endl;
        }else{ 
            cout<<"Невідомий"<<endl;
        }
        if (priority == 1 || priority == 2){
            validation();
        }
    }
};

int main(){
    vector<Importance> notifs{
        Importance("Зміна налаштувань", "Змінено важливі налаштування безпеки.", 1),
        Importance("Оновлення", "Необхідно встановити оновлення функцій підсистеми.", 2),
        Importance("Зміна параметрів", "Змінено користувацькі параметри функцій.", 3)
    };
    for (auto& it: notifs){
        it.setFunc([](){
            cout<<"Потрібне підтвердження!"<<endl;
        });
        it.showLevel();
        cout<<"-------------------"<<endl;
    }
    return 0;
}