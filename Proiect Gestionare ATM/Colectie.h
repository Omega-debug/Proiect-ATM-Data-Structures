typedef int TypeBanknote;
#include "VectorDinamic.h"
class Collection {
private:
    VectorDinamic values;
    VectorDinamic exemplare;
    int distincteValues;
    int capacity;
public:
    Collection();
    void add(int banknote);
    bool remove(int banknote);
    bool search(int banknote);
    int size();
    int nroccurrences(int banknote);
    void destroy();
    TypeBanknote getAt(int position);
    void afis();
};