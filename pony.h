#ifndef PONY_H
#define PONY_H

#include <iostream>
using namespace std;

class Pony
{
protected:
    int geburtsJahr;
    string name;
public:
    Pony();
    virtual ~Pony();
    string gibName();
    int gibGeburtsjahr();
    virtual bool istReitbar(int j)=0;
    virtual void zeigeInfo()=0;
};

#endif // PONY_H
