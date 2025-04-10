#include <iostream>
using namespace std;
float set_prem(int r, float zarp);

class Pracivnyk{
    string prizv, viddil;
    int rik;
    float zarp, prem;
    public:
    Pracivnyk();
    Pracivnyk(string pr, string vdd,  int r, float zp);
    void set_prac(string pr, string vdd,  int r, float zp);
    void change(string pr, string npr, string vdd,  int r, float zp);
    void sort(Pracivnyk arr[], int n);
    void get_prac();
    ~Pracivnyk();

    friend void sort(Pracivnyk arr[], int n);
    friend float seredniy_stazh(Pracivnyk arr[], int n);
    friend void i_viddil(Pracivnyk arr[], int n);

    friend class Vidpustka;
};

float seredniy_stazh(Pracivnyk arr[], int n);

void i_viddil(Pracivnyk arr[], int n);

class Vidpustka {
    Pracivnyk prac;
    string start;
    int term;
    string end;

public:
    Vidpustka();
    string calcDate(int startDay, int Month, int Year, int days);
    void set(Pracivnyk p);

    void print();
};