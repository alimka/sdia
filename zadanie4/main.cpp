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

bool cmp (Element i, Element j) { // posortuj do lewej wzg. końców przedziałów (jeśli końce są równe to początków)
    if (i.kn != j.kn) return (i.kn < j.kn);
    return (i.st < j.st);
}

vector<Element> vec; // vector elementów
int wynik[10001]; // tablica wyników
bool flaga[10001];

int main()
{
    int n;
    Element a;
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %d", &a.st, &a.kn);
        a.poz = i + 1;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end(), cmp);

    for (i = 0; i < n; ++i) { // dla każdego wiersza
        for (j = vec[i].st; j <= vec[i].kn; ++j) { // w obrębie dostępnego obszaru
            if (!flaga[j]) { // sprawdź flagę
                flaga[j] = 1;
                wynik[vec[i].poz] = j;
                break;
            }
        }
    }
}
