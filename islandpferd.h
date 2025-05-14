#ifndef ISLANDPFERD_H
#define ISLANDPFERD_H

#include "pony.h"

class Islandpferd : public Pony
{
private:
    bool ekzemer;
public:
    Islandpferd();
    bool hatEkzem();
    bool istReitbar(int j);
    void zeigeInfo();

};

#endif // ISLANDPFERD_H
