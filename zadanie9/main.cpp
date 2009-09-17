#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Sc {
    int nrOdc, nrSc;
    string tytSc;
    Sc (string t, int o, int s):tytSc(t), nrOdc(o), nrSc(s) {}
    friend bool operator==(const Sc& a,const Sc& b);
};

bool operator==(const Sc& a,const Sc& b) {
    if (b.nrOdc == a.nrOdc && b.nrSc == a.nrSc && b.tytSc == a.tytSc) return true;
    return false;
}

class HashTable {

    vector<Sc> * vec;

public:

    int hashujSc (int nrSc);
    int hashujTyt (string tytSc, int nrOdc);
    void dodaj (string tyt, int nrOdc, int nrSc);
    void szukajPoScenie (int szukajSc);
    void szukajPoTytule (string szukajTyt, int szukajOdc);
    void deletScene (int deletSc);
    void deletTyt (string deletTyt, int deletOdc);
    bool istnieje (int index, string tyt, int nrOdc, int nrSc);
    int jestFull ();
    void powieksz ();


    int size, elements;

    HashTable();
};

HashTable::HashTable() {
    elements = 0;
    size = 1;
    vec = new vector<Sc> [size];
}

int HashTable::hashujSc(int nrSc) {
    return (nrSc * nrSc % size);
}

int HashTable::hashujTyt(string tytSc, int nrOdc) {
    int l = tytSc.length();
    int s = nrOdc + l;
    return (s * s % size);
}

bool HashTable::istnieje(int index, string tyt, int nrOdc, int nrSc) {
    Sc a(tyt,nrOdc, nrSc);
    for (vector<Sc>::iterator it = vec[index].begin(); it != vec[index].end(); ++it) {
        //if (*it == a) return true;
        if ((*it).nrOdc == nrOdc && (*it).tytSc == tyt && (*it).nrSc == nrSc) return true;
    }
    return false;
}

void HashTable::powieksz() {
    vector<Sc> * pom = vec;
    int nju_size = 2 * size + 1;
    vec = new vector<Sc> [nju_size];

    for (int i = 0; i < size; ++i) {
        while (!pom[i].empty()) {
            Sc tmp = pom[i].back();
            pom[i].pop_back();
            --elements;
            dodaj(tmp.tytSc, tmp.nrOdc, tmp.nrSc);
        }
    }
    size = nju_size;
    delete [] pom;
}

int HashTable::jestFull() {
    int wsp = elements/size;
    if (wsp > 1) return 1;
    return 0;
}

void HashTable::dodaj(string tyt, int nrOdc, int nrSc) {
    if (jestFull()) powieksz();

    int h1 = hashujSc(nrSc);
    int h2 = hashujTyt(tyt, nrOdc);

    if (!istnieje(h1, tyt, nrOdc, nrSc) && !istnieje(h2, tyt, nrOdc, nrSc)) {
        Sc a(tyt, nrOdc, nrSc);
        vec[h1].push_back(a);
        vec[h2].push_back(a);
        elements++;
    }
}

void HashTable::szukajPoTytule(string szukajTyt, int szukajOdc) {

    int idx = hashujTyt(szukajTyt, szukajOdc);

    for (vector<Sc>::iterator it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrOdc == szukajOdc && (*it).tytSc == szukajTyt) {
            cout << (*it).nrSc << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void HashTable::szukajPoScenie(int szukajSc) {

    int idx = hashujSc(szukajSc);

    for (vector<Sc>::iterator it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrSc == szukajSc) {
            cout << (*it).tytSc << endl;
            cout << (*it).nrOdc << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void HashTable::deletScene(int deletSc) {

    string tyt;
    int odc, idx2;
    int idx = hashujSc(deletSc);

    for (vector<Sc>::iterator it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrSc == deletSc) {
            tyt = (*it).tytSc;
            odc = (*it).nrOdc;
            vec[idx].erase(it);
            idx2 = hashujTyt(tyt, odc);
            for (vector<Sc>::iterator it2 = vec[idx2].begin(); it2 != vec[idx2].end(); ++it2) {
                if ( (*it2).tytSc == tyt && (*it2).nrOdc == odc ) {
                    vec[idx2].erase(it2);
                    break;
                }
            }
            elements--;
            return;
        }
    }
}

void HashTable::deletTyt(string deletTyt, int deletOdc) {

    int sc, idx2;
    int idx = hashujTyt(deletTyt, deletOdc);

    for (vector<Sc>::iterator it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrOdc == deletOdc && (*it).tytSc == deletTyt) {
            sc = (*it).nrSc;
            vec[idx].erase(it);
            idx2 = hashujSc(sc);
            for (vector<Sc>::iterator it2 = vec[idx2].begin(); it2 != vec[idx2].end(); ++it2) {
                if ((*it2).nrSc == sc ) {
                    vec[idx2].erase(it2);
                    break;
                }
            }
            elements--;
            return;
        }
    }
}

int main()
{
    HashTable tab;

    int op, odc, sc;
    string tyt;

    while (true)
    {
        cin >> op;
        cin.ignore();
        switch (op)
        {
                case 1: // Dodaj scenę do bazy
                    getline (cin, tyt);
                    cin >> odc;
                    cin >> sc;
                    tab.dodaj(tyt, odc, sc);
                    break;

                case 2: // Znajdź w bazie scenę o podanym numerze
                    cin >> sc;
                    tab.szukajPoScenie(sc);
                    break;

                case 3: // Znajdź w bazie scenę o podanych tytule i numerze odcinka
                    getline (cin, tyt);
                    cin >> odc;
                    tab.szukajPoTytule(tyt, odc);
                    break;

                case 4: // Usuń z bazy scenę o podanym numerze
                    cin >> sc;
                    tab.deletScene(sc);
                    break;

                case 5: // Usuń z bazy scenę o podanych tytule i numerze odcinka
                    getline (cin, tyt);
                    cin >> odc;
                    tab.deletTyt(tyt, odc);
                    break;

                case 6: // Zakończ pracę programu
                    exit(0);
                }
    }
    return 0;
}
