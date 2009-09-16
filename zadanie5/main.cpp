#include <iostream>
#include <string>

using namespace std;

int Left(int i) {
    return 2*i+1;
}
int Right(int i) {
    return 2*i+2;
}
int Parent(int i) {
    if (i % 2 == 0) {
        return i/2 - 1;
    } else {
        return i/2;
    }
}

void Heapify(int czasZd[], string textZd[], int size, int i) {
    int minEl;
    int l = Left(i);
    int r = Right(i);
    int pom;
    string pomT;

    if (l <= size && czasZd[l] < czasZd[i])
        minEl = l;
    else
        minEl = i;

    if (r <= size && czasZd[r] < czasZd[minEl])
        minEl = r;

    if (minEl != i)
    {
        pom = czasZd[i];
        czasZd[i] = czasZd[minEl];
        czasZd[minEl] = pom;

        pomT = textZd[i];
        textZd[i] = textZd[minEl];
        textZd[minEl] = pomT;

        Heapify(czasZd, textZd, size, minEl);
    }
}

string ExtractMin (int czasZd[], string textZd[], int size) {
    if (size < 0)
        cout << "Tablica jest pusta" << endl;

    int minCzasZd = czasZd[0];
    string minTextZd = textZd[0];
    czasZd[0] = czasZd[size];
    textZd[0] = textZd[size];
    Heapify(czasZd, textZd, size, 0);
    return minTextZd;
}

void Insert(int czasZd[], string textZd[], int czas, string text, int size) {
    size++;
    int i = size;

    int pomPar = Parent(i);

    while (i > 0 && czasZd[pomPar] > czas)
    {
        czasZd[i] = czasZd[pomPar];
        textZd[i] = textZd[pomPar];
        i = Parent(i);
        pomPar = Parent(i);
    }

    czasZd[i] = czas;
    textZd[i] = text;
}

int czasWyd[1000000]; //czas wydarzenia
string scena[1000000]; //wydarzenia w serialu

int main()
{
    int liczbaOp, operacja;
    int i = 0;
    int czasZd;
    string textZd;

    cin >> liczbaOp;
    while(liczbaOp--)
    {
        cin >> operacja;
        cin.ignore();
        switch(operacja)
        {
                case 1: // Dodaj zdarzenie do bazy
                    getline (cin, textZd);
                    cin >> czasZd;
                    Insert(czasWyd, scena, czasZd, textZd, i-1);
                    i++;
                    break;

                case 2: // Wypisz i usuń pierwsze zdarzenie
                    cout << ExtractMin(czasWyd, scena, i-1) <<endl;
                    i--;
                    break;

                case 3: // Zapytanie o pustość bazy
                    if (i < 1)
                        cout << "1" << endl;
                    else
                        cout << "0" << endl;
                    break;
                }
    }

    return 0;
}
