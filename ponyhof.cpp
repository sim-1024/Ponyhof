#include "ponyhof.h"

Ponyhof::Ponyhof() {}

Ponyhof::~Ponyhof() {
    for (size_t i = 0; i < beimReiten.size(); i++) {
        delete beimReiten[i];
    }
}

void Ponyhof::userDialog() {
    char eingabe;

    while (true) {
        cout << "\n1\tPonny einstellen" << endl;
        cout << "2\tPonny zum Reiten holen" << endl;
        cout << "3\tPonnys kontrollieren" << endl;
        cout << "4\tFeierabend" << endl;
        cout << "0\tProgramm beenden" << endl;
        cout << "> ";
        cin >> eingabe;

        switch (eingabe) {
        case '1': {
            char choice;
            cout << "Welche Rasse soll eingestellt werden? [0 - Isi | 1 - Shetty]: ";
            cin >> choice;
            Pony* pPony = ponyAnlegen(choice);
            if (pPony) {
                if(stallung.einstellen(pPony)) {
                    cout << "Pony wurde eingefuegt" << endl;
                } else {
                    cout << "Pferdeboxen sind voll!" << endl;
                }
            } else {
                cout << "Ungueltige Eingabe!" << endl;
            }
        }
        break;
        case '2': {
            string name;
            int alter;
            cout << "Name des zu holenden Ponys: ";
            cin >> name;
            Pony* pPony = stallung.herausholen(name);
            if (pPony) {
                cout << "Alter des Reiters: ";
                cin >> alter;
                if (pPony->istReitbar(alter)) {
                    beimReiten.push_back(pPony);
                    cout << "Pony wird geritten" << endl;
                } else {
                    stallung.einstellen(pPony);
                    cout << "Pony nicht reitbar!" << endl;
                }
            } else {
                cout << "Pony nicht gefunden!" << endl;
            }
        }
        break;
        case '3': {
            stallung.zeigeInfo();
            cout << "Anzahl der geritteten Ponys: " << beimReiten.size() << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (size_t i = 0; i < beimReiten.size(); i++) {
                beimReiten[i]->zeigeInfo();
            }
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        case '4': {
            feierAbend();
        }
        break;
        case '0': {
            return;
        }
        default:
            cout << "Ungueltige Eingabe!" << endl;
        }
    }
}

Pony* Ponyhof::ponyAnlegen(char c) {
    if (c=='0') {
        Pony* isi = new Islandpferd();
        return isi;
    } else if (c=='1') {
        Pony* shetty = new Shetlandpony();
        return shetty;
    } else {
        return nullptr;
    }
}

void Ponyhof::feierAbend() {
    for (size_t i = 0; i < beimReiten.size(); i++) {
        stallung.einstellen(beimReiten[i]);
    }
    beimReiten.clear();
    cout << "Alle Ponnys sind jetzt im Stahl" << endl;
    cout << "Schoenen Feierabend!" << endl;
}

