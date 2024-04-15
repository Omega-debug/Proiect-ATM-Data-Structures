//
// Created by Mihnea Marinescu on 26.04.2023.
//

#include "Tranzaction.h"
#include<iostream>
using namespace std;

Tranzaction::Tranzaction()
{
    this->idTranzactie=0;
    this->suma=0;
    this->bancnoteDistincte=0;
    this->tipBancnote=nullptr;
    this->frecventaBancnote=nullptr;
}
Tranzaction::Tranzaction(int idTranzactie,int suma,int *&tipBancnote,int *&frecventaBancnote,int bancnoteDistincte)
{
    this->idTranzactie=idTranzactie;
    this->suma=suma;
    this->tipBancnote=tipBancnote;
    this->frecventaBancnote=frecventaBancnote;
    this->bancnoteDistincte=bancnoteDistincte;

    //cout<<"IN CONSTRUCTOR" << this->tipBancnote[0];
}
Tranzaction::~Tranzaction()
{
    delete[] tipBancnote;
    delete[] frecventaBancnote;
}
int Tranzaction::getIdTranzaction()
{
    return this->idTranzactie;
}
int Tranzaction::getSuma()
{
    return this->suma;
}
int* Tranzaction::getTipBancnote()
{
    //cout << this->tipBancnote[0];
    return this->tipBancnote;
}
int* Tranzaction::getFrecventaBancnote()
{
    return this->frecventaBancnote;
}
int Tranzaction::getBancnoteDistincte()
{
    return this->bancnoteDistincte;
}

Tranzaction& Tranzaction::operator=(const Tranzaction &t) {
    this->idTranzactie = t.idTranzactie;
    this->suma = t.suma;
    this->tipBancnote = new int[t.bancnoteDistincte];
    this->frecventaBancnote = new int[t.bancnoteDistincte];
    for(int i=0;i<t.bancnoteDistincte;++i){
        this->tipBancnote[i] = t.tipBancnote[i];
        this->frecventaBancnote[i] = t.frecventaBancnote[i];
    }
    this->bancnoteDistincte = t.bancnoteDistincte;

    return *this;
}

