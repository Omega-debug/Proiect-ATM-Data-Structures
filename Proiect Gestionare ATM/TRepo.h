#include "Tranzaction.h"
class TRepo{
private:
    Tranzaction *tranzactii;
    int currentSize=0;
    int maxSize=9999;
public:
    TRepo();
    void addNewTranzactie(const Tranzaction &t);
    Tranzaction *getAllTranzactii();
    int getCurrentSize();
};