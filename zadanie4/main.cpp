#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Element {
    int st;
    int kn;
    int poz;
};

bool cmp (const Element& i, const Element& j) { // posortuj do lewej wzg. końców przedziałów (jeśli końce są równe to początków)
    if (i.kn != j.kn) return (i.kn < j.kn);
    return (i.st < j.st);
}

Element vec[10001]; // vector elementów
int wynik[10001]; // tablica wyników
int flaga[10001];

int main()
{
    int n;
    // Element a;
    int i, j;
    int licznik_wiez = 0;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %d", &vec[i].st, &vec[i].kn);
        vec[i].poz = i;
        // vec[i] = a;
        // vec.push_back(a);
    }

    // sort(vec.begin(), vec.end(), cmp);
    sort(vec, vec + n, cmp);


    for (i = 0; i < n; ++i) { // dla każdego wiersza
        for (j = vec[i].st; j <= vec[i].kn; ++j) { // w obrębie dostępnego obszaru
            if (!flaga[j]) { // sprawdź flagę
                flaga[j] = 1;
                wynik[vec[i].poz] = j;
                licznik_wiez++;
                break;
            }
        }
    }
    if (licznik_wiez == n) for (int i = 0; i < n; i++) cout << wynik[i] << endl;
    else cout << "NIE" << endl;

    return 0;
}
