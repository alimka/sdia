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
    vector<Sc>::iterator it;
    vector<Sc>::iterator it2;
    int idx, idx2;

public:

    int hashujSc (int &nrSc);
    int hashujTyt (string &tytSc, int &nrOdc);
    void dodaj (string &tyt, int nrOdc, int nrSc);
    void szukajPoScenie (int szukajSc);
    void szukajPoTytule (string &szukajTyt, int szukajOdc);
    void deletScene (int deletSc);
    void deletTyt (string &deletTyt, int deletOdc);
    bool istnieje (int index, string &tyt, int nrOdc, int nrSc);
    int jestFull ();
    void powieksz ();


    int size, elements;

    HashTable();
};

HashTable::HashTable() {
    elements = 0;
    size = 10000;
    vec = new vector<Sc> [size];
}

int HashTable::hashujSc(int &nrSc) {
    return (abs(nrSc * nrSc) % size);
}

int HashTable::hashujTyt(string &tytSc, int &nrOdc) {
    int l = tytSc.length();
    int s = nrOdc + l;
    return (abs(s * s) % size);
}

bool HashTable::istnieje(int index, string &tyt, int nrOdc, int nrSc) {
    // Sc a(tyt,nrOdc, nrSc);
    for (it = vec[index].begin(); it != vec[index].end(); ++it) {

        if ((*it).nrOdc == nrOdc && (*it).tytSc == tyt && (*it).nrSc == nrSc) return true;
    }
    return false;
}

void HashTable::powieksz() {
    vector<Sc> * pom = vec;
    int old_size = size;
    size = 2 * old_size + 1;
    vec = new vector<Sc> [size];

    for (int i = 0; i < old_size; ++i) {
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

void HashTable::dodaj(string &tyt, int nrOdc, int nrSc) {
    if (jestFull())
        powieksz();

    idx = hashujSc(nrSc);
    idx2 = hashujTyt(tyt, nrOdc);

    if (!istnieje(idx, tyt, nrOdc, nrSc) && !istnieje(idx2, tyt, nrOdc, nrSc)) {
        Sc a(tyt, nrOdc, nrSc);
        vec[idx].push_back(a);
        vec[idx2].push_back(a);
        elements++;
    }
}

void HashTable::szukajPoTytule(string &szukajTyt, int szukajOdc) {

    idx = hashujTyt(szukajTyt, szukajOdc);

    for (it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrOdc == szukajOdc && (*it).tytSc == szukajTyt) {
            cout << (*it).nrSc << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

void HashTable::szukajPoScenie(int szukajSc) {

    idx = hashujSc(szukajSc);

    for (it = vec[idx].begin(); it != vec[idx].end(); ++it) {
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
    int odc;
    idx = hashujSc(deletSc);

    for (it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrSc == deletSc) {
            tyt = (*it).tytSc;
            odc = (*it).nrOdc;
            vec[idx].erase(it);
            idx2 = hashujTyt(tyt, odc);
            for (it2 = vec[idx2].begin(); it2 != vec[idx2].end(); ++it2) {
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

void HashTable::deletTyt(string &deletTyt, int deletOdc) {

    int sc;
    idx = hashujTyt(deletTyt, deletOdc);

    for (it = vec[idx].begin(); it != vec[idx].end(); ++it) {
        if ( (*it).nrOdc == deletOdc && (*it).tytSc == deletTyt) {
            sc = (*it).nrSc;
            vec[idx].erase(it);
            idx2 = hashujSc(sc);
            for (it2 = vec[idx2].begin(); it2 != vec[idx2].end(); ++it2) {
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
