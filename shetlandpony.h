#ifndef SHETLANDPONY_H
#define SHETLANDPONY_H

#include "pony.h"

class Shetlandpony : public Pony
{
private:
    bool kinderlieb;
public:
    Shetlandpony();
    bool istKinderlieb();
    bool istReitbar(int j);
    void zeigeInfo();
};

#endif // SHETLANDPONY_H
