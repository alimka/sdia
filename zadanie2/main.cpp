#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string aktor, postac;
    int pierwszyOdcinek, ostatniOdcinek;
    Persona () {}
    Persona (string a, string p, int pO, int oO):aktor(a), postac(p), pierwszyOdcinek(pO), ostatniOdcinek(oO) {}
};

int pozycja(0), size(100);
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

int dzielTablice(int left, int right) {
    Persona x = wsk[right];
    int i = left - 1;
    Persona pom;
    for (int j = left; j < right; ++j) {
        if (wsk[j].aktor <= x.aktor) {
            i++;
            pom = wsk[i];
            wsk[i] = wsk[j];
            wsk[j] = pom;
        }
    }
    pom = wsk[i+1];
    wsk[i+1] = wsk[right];
    wsk[right] = pom;
    return i + 1;
}

void sortujAktorow(int left, int right) { // Quicksort
    if (left < right) {
        int dz = dzielTablice(left, right);
        sortujAktorow(left, dz-1);
        sortujAktorow(dz + 1, right);
    }
}

void mergeTable(int left, int dz, int right) {
    int x = (dz - left + 1);
    int y = right - dz;
    Persona X [x+1];
    Persona Y [y+1];
    Persona osoba;
    osoba.postac = '~'; // ostatni znak w ASCII

    for (int i = 0; i < x; ++i) X[i] = wsk[left + i];
    for (int i = 0; i < y; ++i) Y[i] = wsk[dz + i + 1];

    X[x] = Y[y] = osoba;

    int i = 0;
    int j = 0;
    for (int k = left; k <= right; ++k) {
        if (X[i].postac <= Y[j].postac) {
            wsk[k] = X[i];
            ++i;
        } else {
            wsk[k] = Y[j];
            ++j;
        }
    }
}

void sortujPostacie(int left, int right) { // MergeSort
    if (left < right) {
        int dz = (left + right)/2;
        sortujPostacie(left, dz);
        sortujPostacie(dz + 1, right);
        mergeTable(left, dz, right);
    }
}

int main()
{
    wsk = new Persona[size];

    int liczbaPolecen, polecenie, index;

    string aktor, postac;
    int pierwszyOdcinek, ostatniOdcinek;

    pozycja = 0;

    cin >> liczbaPolecen;
    cin.ignore();
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        switch(polecenie)
        {
        case 1: // Dodanie aktora na koniec listy.
            {
                cin.ignore(99999, '\n');
                getline (cin, aktor);
                getline (cin, postac);
                cin >> pierwszyOdcinek;
                cin >> ostatniOdcinek;

                cout << aktor << ", " << postac << ", " << pierwszyOdcinek << ", " << ostatniOdcinek << endl;

                Persona a(aktor, postac, pierwszyOdcinek, ostatniOdcinek);
                dodaj(a);
                ++pozycja;
                break;
            }
        case 2: // Posortowanie rosn&#261;co listy  wzgl&#281;dem imion i nazwisk aktorów (algorytmem quicksort).
            {
                sortujAktorow(0, size-1);
                break;
            }
        case 3: // Posortowanie rosn&#261;co listy wzgl&#281;dem imion i nazwisk postaci (algorytmem mergesort).
            {
                sortujPostacie(0, size-1);
                break;
            }
        case 4: // Wypisanie rekordu przechowywanego w li&#347;cie na miejscu o zadanym indeksie
            {
                cin >> index;
                wyswietl(index);
                break;
            }
        }
    }
    return 0;
}
