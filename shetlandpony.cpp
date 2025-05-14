#include "shetlandpony.h"

Shetlandpony::Shetlandpony() {
    char k_lieb;
    cout << "Geburtsjahr: ";
    cin >> geburtsJahr;
    cout << "Name: ";
    cin >> name;
    cout << "Kinderlieb [y/n]: ";
    cin >> k_lieb;
    if (k_lieb=='y') {
        kinderlieb=true;
    } else if (k_lieb=='n') {
        kinderlieb=false;
    } else {
        cout << "Ungueltige Eingabe!" << endl;
    }
}

bool Shetlandpony::istKinderlieb() {
    return kinderlieb;
}

bool Shetlandpony::istReitbar(int j) {
    if (j>8 && j<=12) {
        return true;
    } else if (j>=5 && j<=8 && kinderlieb) {
        return true;
    } else {
        return false;
    }
}

void Shetlandpony::zeigeInfo() {
    string kdl;
    if (istKinderlieb()) {
        kdl="Ja";
    } else {
        kdl="Nein";
    }
    cout << "  * Shetlandpony \"" << name << "\", in " << geburtsJahr
         << " geboren:\n    -Kinderlieb: " << kdl << endl;
}
