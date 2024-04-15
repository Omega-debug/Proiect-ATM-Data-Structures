//
// Created by Mihnea Marinescu on 26.04.2023.
//

#include "Colectie.h"

class ATM {
private:
    Collection collection;
    int position;
public:
    ATM(Collection c);
    bool validare();
    void primaPoz();
    void urmPoz();
    int bancnotaCurenta();
    int getNrBancnotaCurenta();
};