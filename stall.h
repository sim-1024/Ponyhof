#ifndef STALL_H
#define STALL_H

#include "pony.h"
const int SIZE = 20;

class Stall
{
private:
    Pony* pferdeboxen[SIZE]={nullptr};
public:
    Stall();
    virtual ~Stall();
    int belegteBoxen();
    bool einstellen(Pony* p);
    Pony* herausholen(string n);
    float durchschnittsalter();
    void zeigeInfo();
    int berechneJahr();
};

#endif // STALL_H
