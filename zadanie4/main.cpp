#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    int n;
    Element a;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a.st >> a.kn;
        a.poz = i + 1;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end(), cmp);
}
