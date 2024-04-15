#include<iostream>
using namespace std;
#include"BKT.h"
#include"ATM.h"

int p[1001];
int nr=1;
int bancnote[1001], exemplare[1001], n;
int  poz, S, vf[100001];
Collection t;
ATM A(t);

//void incarcare_date(int v[101], int q[101], int t){
//    for(int i=1;i<=t;++i){
//        cout <<"Dati valoarea bancnotei cu numarul " << i <<" : "; cin >> v[i];
//        cout <<"Dati numarul de exemplare: "; cin >> q[i];
//    }
//}
//

void tipar(int k)
{

    for(int i=1;i<=10000;++i) vf[i] = 0; //curat

    for(int i=1;i<=k;++i) vf[p[i]]++;
    cout <<"S = "; cout << n <<" = ";
    for(int i=1;i<=nr;++i) {
        if (vf[bancnote[i]] > 0) cout << vf[bancnote[i]] << "*" << bancnote[i];
        poz = i;
        break;
    }
    for(int i=poz+1;i<=nr;++i)
        if (vf[bancnote[i]] > 0) cout  <<" + " << vf[bancnote[i]] << "*" << bancnote[i];

    cout <<"\n";
}

int cond(int k)
{
    S=0;
    for(int i=1;i<k;++i)
        if(p[k]>p[i]) return 0;
    for(int j=1;j<=nr;++j)
    {
        if(p[k]==bancnote[j]) {
            if (exemplare[j] > 0) {
                exemplare[j]--;
            }
            else return 0;
        }
    }
    for(int i=1;i<=k;++i) S=S+p[i];
    if(S<=n) return 1;
    else return 0;
}

//
void BKTR(int k)
{

    for(int i=1;i<=nr;++i)
    {
        p[k]=bancnote[i];
        if(cond(k))
            if (S == n) tipar(k);
            else BKTR(k+1);
    }
}

void START(){
    p[0]= 1;
    cout <<"Introduceti suma dorita: " << endl;
    //reprezinta suma;
   cin >> n;

    while (A.validare())
    {
        bancnote[nr] = A.bancnotaCurenta();
        exemplare[nr] = A.getNrBancnotaCurenta();
        nr++;
        A.urmPoz();
    }

    A.primaPoz();
    nr--;
    BKTR(1);

//    cout << nr << endl;
//    cout << bancnote[1] << " " << exemplare[1] << endl;
//   cout << bancnote[2] << " " << exemplare[2] << endl;
//   cout << bancnote[3] << " " << exemplare[3] << endl;

}
