#include "islandpferd.h"

Islandpferd::Islandpferd() {
    char ekz;
    cout << "Geburtsjahr: ";
    cin >> geburtsJahr;
    cout << "Name: ";
    cin >> name;
    cout << "Ekzemer [y/n]: ";
    cin >> ekz;
    if (ekz=='y') {
        ekzemer=true;
    } else if (ekz=='n') {
        ekzemer=false;
    } else {
        cout << "Ungueltige Eingabe!" << endl;
    }
}

bool Islandpferd::hatEkzem() {
    return ekzemer;
}

bool Islandpferd::istReitbar(int j) {
    if (j>=10) {
        return true;
    } else {
        return false;
    }
}

void Islandpferd::zeigeInfo() {
    string ekz;
    if (hatEkzem()) {
        ekz="Ja";
    } else {
        ekz="Nein";
    }
    cout << "  * Islandpferd \"" << name << "\", in " << geburtsJahr
         << " geboren:\n    -Sommerekzem: " << ekz << endl;
}
