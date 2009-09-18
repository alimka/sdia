#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string aktor, postac;
    int pierwszyOdcinek, ostatniOdcinek;
    Persona () {}
    Persona (string a, string p, int pO, int oO):aktor(a), postac(p), pierwszyOdcinek(pO), ostatniOdcinek(oO) {}
};

int pozycja, size;
Persona * wsk;

void powieksz() {
    Persona * pom = wsk;
    int old_size = size;
    size *= 2;
    wsk = new Persona [size];
    for (int i = 0; i < old_size; ++i) {
        wsk[i] = pom[i];
    }
    delete [] pom;
}

void dodaj(Persona a) {
    if (pozycja == size) powieksz();
    wsk[pozycja] = a;
}

void wyswietl (int index) {
    cout << wsk[index].aktor << endl;
    cout << wsk[index].postac << endl;
    cout << wsk[index].pierwszyOdcinek << endl;
    cout << wsk[index].ostatniOdcinek << endl;
}

int main()
{
    wsk = new Persona [100];

    int liczbaPolecen, polecenie, index;

    string aktor, postac;
    int pierwszyOdcinek, ostatniOdcinek;

    pozycja = 0;

    cin >> liczbaPolecen;
    cin.ignore();
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        cin.ignore();
        switch(polecenie)
        {
        case 1: // Dodanie aktora na koniec listy.
            {
                getline (cin, aktor);
                getline (cin, postac);
                cin >> pierwszyOdcinek;
                cin.ignore();
                cin >> ostatniOdcinek;
                cin.ignore();

                Persona a(aktor, postac, pierwszyOdcinek, ostatniOdcinek);
                dodaj(a);
                pozycja++;
                break;
            }
        case 2: // Posortowanie rosnąco listy  względem imion i nazwisk aktorów (algorytmem quicksort).
            {
                break;
            }
        case 3: // Posortowanie rosnąco listy względem imion i nazwisk postaci (algorytmem mergesort).
            {
                break;
            }
        case 4: // Wypisanie rekordu przechowywanego w liście na miejscu o zadanym indeksie
            {
                cin >> index;
                wyswietl(index);
                break;
            }
        }
    }
    return 0;
}
