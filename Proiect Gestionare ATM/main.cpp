#include <iostream>
#include "TRepo.h"
#include "ATM.h"
#include "BKT.h"
using namespace std;
Tranzaction* lista;
//int x[10001], SUMA; // vector solutie si suma
int *freq, *tip;


void afisATM(ATM a)
{
    cout<<"ATM-ul stocheaza urmatoarele seturi bancnote: "<<endl;
    while (a.validare())
    {
        cout << a.bancnotaCurenta()<<" RON x" << a.getNrBancnotaCurenta() << endl;
        a.urmPoz();
    }
    a.primaPoz();

}
void printMenu()
{
    cout<<"1.Afisati inventarul ATM-ului."<<endl;
    cout<<"2.Efectuati o tranzactie."<<endl;
    cout<<"3.Solicitati o lista a istoricului tranzactiilor."<<endl;
    cout<<"4.Afisati toate posibilitatile de plata a unei sume."<<endl;
    cout<<"5.EXIT."<<endl;
}
int main()
{
    Collection c;
    ATM a(c);
    TRepo repo;
    int id=0;
    while(true)
    {
        printMenu();
        cout<<"Alegeti optiunea dorita: ";
        int optiune;
        cin>>optiune;
        if(optiune==1)
        {
            afisATM(a);
        }
        else if(optiune==5)
        {
            return 0;
        }
        else if(optiune == 2)
        {
            id++;
            int suma;
            int bancnoteDistincte;
            cout<<"Introduceti suma pe care doriti sa o scoateti: ";
            cin>>suma;
            cout<<"Numarul de bancnote diferite sunt: ";
            cin>>bancnoteDistincte;
            int* tipBancnote = new int[bancnoteDistincte];
            int* freqBancnote = new int[bancnoteDistincte];
            cout<<"Introduceti pe rand tipul fiecarei bancnote urmat,printr-un spatiu, de numarul ei:"<<endl;
            for(int i=0; i<bancnoteDistincte; i++)
            {
                cin>>tipBancnote[i]>>freqBancnote[i];
            }
            int validare;
            cout<<"Pentru Continuare Tranzactie apasa 1 "<<endl;
            cout <<" Pentru anulare apasa 0: ";
            cin>>validare;
            if(validare)
            {
                cout << "Inainte" <<  tipBancnote[0] << endl;
                Tranzaction t(id,suma,tipBancnote,freqBancnote,bancnoteDistincte);
                cout << "TEST" << t.getTipBancnote()[0] << endl;
                repo.addNewTranzactie(t);
                //for(int i=0; i<bancnoteDistincte; i++)
                //{
                //  int aux = freqBancnote[i];
                //while(aux)
                //{
                //  c.remove(tipBancnote[i]);
                // aux--;
                // }
                //}

            }
            //delete[] tipBancnote;
            // delete[] freqBancnote;
        }
        else if(optiune == 3)
        {
            //Tranzaction* lista = new Tranzaction[repo.getCurrentSize()];
            lista = repo.getAllTranzactii();
           // cout << *lista[0].getFrecventaBancnote() << endl;
            for(int i=0; i<repo.getCurrentSize(); i++)
            {
                cout<<"Tranzactia cu ID-ul: "<<lista[i].getIdTranzaction()<<" in valoare de "<<lista[i].getSuma()<<" a fost efectuata astfel: "<<endl;
                //int* tip = new int[lista[i].getBancnoteDistincte()];
                //int* freq = new int[lista[i].getBancnoteDistincte()];
                tip = lista[i].getTipBancnote();
                freq = lista[i].getFrecventaBancnote();
               // cout << freq[0] << endl;
                for(int j=0; j<lista[i].getBancnoteDistincte(); j++)
                {
                    cout<<*(tip+j)<<" ron x"<<freq[j]<<endl;
                }
            }

        }
        else if(optiune == 4){
            START();
}
        else
        {
            cout<<"Optiune invalida, va rugam reincercati!"<<endl;
        }
    }
}


