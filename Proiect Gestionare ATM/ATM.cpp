//
// Created by Mihnea Marinescu on 26.04.2023.
//

#include "ATM.h"

ATM::ATM(Collection c) {
    this->collection = c;

    if(collection.size()!=0)
        this->position = 1;
    else
        this->position = 0;
}

bool ATM::validare() {
    return (position > 0 && position <= collection.size());
}

void ATM::primaPoz() {
    if(collection.size()!=0)
        this->position = 1;
}

void ATM::urmPoz(){
    position++;
}

int ATM::bancnotaCurenta() {
    return collection.getAt(position-1);
}

int ATM::getNrBancnotaCurenta() {
    return collection.nroccurrences(bancnotaCurenta());
}

