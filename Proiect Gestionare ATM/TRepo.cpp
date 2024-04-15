#include "TRepo.h"

TRepo::TRepo()
{
    this->tranzactii=new Tranzaction[this->maxSize];
}
void TRepo::addNewTranzactie(const Tranzaction &t)
{
    if(this->currentSize+1>this->maxSize)
    {
        Tranzaction *newTranzactii = new Tranzaction[this->maxSize*2+1];
        this->maxSize=this->maxSize*2+1;
        for(int i=0; i<this->currentSize; i++)
        {
            newTranzactii[i]=this->tranzactii[i];
        }
        delete[] this->tranzactii;
        this->tranzactii=newTranzactii;

    }
    this->tranzactii[this->currentSize++] = t;

}
Tranzaction *TRepo::getAllTranzactii()
{
    return this->tranzactii;
}

int TRepo::getCurrentSize()
{
    return this->currentSize;
}

