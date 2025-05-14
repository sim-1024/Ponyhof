#include "stall.h"
#include <ctime>

Stall::Stall() {}

Stall::~Stall() {
    for (size_t i = 0; i < SIZE; i++) {
        delete pferdeboxen[i];
    }
    cout << "\nAuf Wiedersehen!\n" << endl;
}

int Stall::belegteBoxen() {
    int anzahlBelegteBoxen=0;
    for (size_t i = 0; i < SIZE; i++) {
        if (pferdeboxen[i]) {
            anzahlBelegteBoxen++;
        }
    }
    return anzahlBelegteBoxen;
}

bool Stall::einstellen(Pony *p) {
    for (size_t i = 0; i < SIZE; i++) {
        if (pferdeboxen[i]==nullptr) {
            pferdeboxen[i]=p;
            return true;
        }
    }
    return false;
}

Pony *Stall::herausholen(string n) {
    for (size_t i = 0; i < SIZE; i++) {
        if (pferdeboxen[i]!=nullptr && pferdeboxen[i]->gibName()==n) {
            Pony* pPony = pferdeboxen[i];
            pferdeboxen[i]=nullptr;
            return pPony;
        }
    }
    return nullptr;
}

float Stall::durchschnittsalter() {
    int anzahl=0;
    float summe=0.0, durchschnitt=0.0;
    for (size_t i = 0; i < SIZE; i++) {
        if (pferdeboxen[i]) {
            summe += (berechneJahr() - pferdeboxen[i]->gibGeburtsjahr());
            anzahl++;
        }
    }
    if(summe == 0.0) {
        durchschnitt = 0.0;
    } else {
        durchschnitt = summe / anzahl;
    }
    return durchschnitt;
}

void Stall::zeigeInfo() {
    cout << "\nAnzahl der Ponys im Stall: " << belegteBoxen() << endl;
    cout << "Durchschnittsalter der Ponys im Stall: " << durchschnittsalter() << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (size_t i = 0; i < SIZE; i++) {
        if (pferdeboxen[i]) {
            pferdeboxen[i]->zeigeInfo();
        }
    }
    cout << "--------------------------------------------------------------" << endl;
}

int Stall::berechneJahr() {
    time_t seconds = time(NULL);
    int jahr = 1970 + (seconds/(3600*24*365.25));
    return jahr;
}
