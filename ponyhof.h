#ifndef PONYHOF_H
#define PONYHOF_H

#include "pony.h"
#include "stall.h"
#include "islandpferd.h"
#include "shetlandpony.h"
#include <vector>

class Ponyhof
{
private:
    Stall stallung;
    vector<Pony*>beimReiten;
public:
    Ponyhof();
    virtual ~Ponyhof();
    void userDialog();
    Pony* ponyAnlegen(char c);
    void feierAbend();
};

#endif // PONYHOF_H
