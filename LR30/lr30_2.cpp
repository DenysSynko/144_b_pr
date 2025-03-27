#include <iostream>
using namespace std;
float pl(float a, float b=2, float c=3){
    return 2*(a*b+b*c+c*a);
}

int main(){
    cout<<"a = 1:  "<<pl(1)<<endl;
    cout<<"a = 1, b = 4:  "<<pl(1,4)<<endl;
    cout<<"a = 1, b = 4, c = 2:  "<<pl(1,4,2)<<endl;
    return 0;
}