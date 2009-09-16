#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class HashTable {

    struct Sc {
        int nrOdc, nrSc;
        string tytSc;

    };

    vector<Sc> * vec;

    int hashujOdc (int nrOdc);
    int hashujSc (string tytSc, int nrSc);
    void dodaj (string tyt, int nrOdc, int nrSc);
    // void szukajPoScenie (int szukajSc);
    // void szukajPoOdcinku (string szukajTyt, int szukajOdc);
    // void deletScene (int deletSc);
    // void deletOdcinek (string deletTyt, int deletOdc);
    // bool czyIstnieje (string tyt, int nrOdc, int nrSc);
    int jestFull ();
    void powieksz ();

public:
    int size, elements;

    HashTable();
};

HashTable::HashTable() {
    elements = 0;
}

int HashTable::hashujOdc(int nrOdc) {
    return nrOdc % size;
}

int HashTable::hashujSc(string tytSc, int nrSc) {
    int l = tytSc.length();
    return (nrSc + l) % size;
}

void HashTable::powieksz() {
    vector<Sc> * pom = vec;
    size *= 2;
    vec = new vector<Sc> [size];

    for (int i = 0; i < elements; ++i) {
        while (!pom[i].empty()) {
            Sc tmp = pom[i].back();
            pom[i].pop_back();
            --elements;
            dodaj(tmp.tytSc, tmp.nrOdc, tmp.nrSc);
        }
    }
    delete [] pom;
}

int HashTable::jestFull() {
    int wsp = elements/size;
    if (wsp > 1) return 1;
    return 0;
}

void HashTable::dodaj(string tyt, int nrOdc, int nrSc) {
    // jeśli tablica jest zapełniona w pewnym procencie powiększ ją
    if (jestFull()) powieksz();

    // użyj funkcji haszującej tyt i nrOdc oraz funkcji haszującej nrSc
    int h1 = hashujOdc(nrOdc);
    int h2 = hashujSc(tyt, nrSc);

    // jeśli elemntu nie ma jeszcze w tablicy dodaj go (do wyszukiwania można użyć zwykłej funkcji wyszukującej?)

    // zwiększo elements o 1
    elements++;
}

int main()
{
    HashTable tab;

    int liczbaOp, op, odc, sc;
    string tyt;

    cin >> liczbaOp;
    while (liczbaOp--)
    {
        cin >> op;
        cin.ignore();
        switch (op)
        {
                case 1: // Dodaj scenę do bazy
                    getline (cin, tyt);
                    cin >> odc;
                    cin >> sc;
                    // dodaj (scena);
                    break;

                case 2: // Znajdź w bazie scenę o podanym numerze
                    cin >> sc;
                    // szukajPoScenie (szukajSc);
                    break;

                case 3: // Znajdź w bazie scenę o podanych tytule i numerze odcinka
                    getline (cin, tyt);
                    cin >> odc;
                    // szukajPoOdcinku (szukajTyt, szukajOdc);
                    break;

                case 4: // Usuń z bazy scenę o podanym numerze
                    cin >> sc;
                    // deletScene (deletSc);
                    break;

                case 5: // Usuń z bazy scenę o podanych tytule i numerze odcinka
                    getline (cin, tyt);
                    cin >> odc;
                    // deletOdcinek (deletTyt, deletOdc);
                    break;

                case 6: // Zakończ pracę programu
                    exit(0);
                }
    }
    return 0;
}
