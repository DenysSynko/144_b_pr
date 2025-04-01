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
    void get_prac();
    ~Pracivnyk();
};