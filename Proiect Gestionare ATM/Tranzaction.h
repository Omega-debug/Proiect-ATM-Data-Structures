//
// Created by Mihnea Marinescu on 26.04.2023.
//

class Tranzaction
{
private:
    int idTranzactie;
    int suma;
    int* tipBancnote;
    int* frecventaBancnote;
    int bancnoteDistincte;
public:
    Tranzaction();
    Tranzaction(int idTranzaction,int suma,int *&tipBancnote,int *&frecventaBancnote,int bancnoteDistincte);
    ~Tranzaction();

    Tranzaction& operator=(const Tranzaction& t);

    int getIdTranzaction();
    int getSuma();
    int* getTipBancnote();
    int* getFrecventaBancnote();
    int getBancnoteDistincte();
};
