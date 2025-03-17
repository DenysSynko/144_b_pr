#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(){
    srand(time(NULL));
    int n, i, j, r, isl, jslp, jslk, pi=0, pj=0, ki=0, kj=0;

    bool fsl;
    cout<<"Enter N: ";
    cin>>n;
    int posi[n][3];
    int posj[n][3];
    char **s = new char*[n];
    const char a[] = "eyuioa";
    const char b[] = "bcdfghjklmnpqrstvwxyz";
    char fin[50];
    for(i=0;i<n;i++){
        s[i]= new char[n];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j || i+j==n-1){
                s[i][j]=a[rand()%6+0];

            }else{
                s[i][j]=b[rand()%21+0];
            }
            
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Введіть слово: ";
    cin>>fin;
    int d=strlen(fin);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[i][j]==fin[0] && n-j>=d){
                fsl=true;
                isl=i;
                jslp=j;
                jslk=j+d-1;
                for(r=1;r<d;r++){
                    if(s[i][j+r]==fin[r]){

                    }else{
                        fsl=false;
                    }
                }
                if(fsl){
                    posi[pi][0]=isl;
                    posi[pi][1]=jslp;
                    posi[pi][2]=jslk;
                    pi++;
                    ki++;
                }
            }
        }

    }


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[j][i]==fin[0] && n-j>=d){
                fsl=true;
                isl=i;
                jslp=j;
                jslk=j+d-1;
                for(r=1;r<d;r++){
                    if(s[j+r][i]==fin[r]){

                    }else{
                        fsl=false;
                    }
                }
                if(fsl){
                    posj[pj][0]=isl;
                    posj[pj][1]=jslp;
                    posj[pj][2]=jslk;
                    pj++;
                    kj++;
                }
            }
        }

    }




    cout<<"Позиції на яких знайдено слово \""<<fin<<"\": ";
    for(i=0;i<ki;i++){
        cout<<posi[i][0]<<","<<posi[i][1]<<" - "<<posi[i][0]<<","<<posi[i][2]<<" | ";
    }
    for(i=0;i<kj;i++){
        cout<<posj[i][1]<<","<<posj[i][0]<<" - "<<posj[i][2]<<","<<posj[i][0]<<" | ";
    }

    delete[] s;
    return 0;
}