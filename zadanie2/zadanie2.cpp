#include <iostream>
#include <string>

using namespace std;

struct Record
{
    string imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci;
    int pierwszy, ostatni;
};

int main()
{
    int liczbaPolecen, polecenie, index;
    Record dane;
    Record tablica[100];

    cin >> liczbaPolecen;
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        switch(polecenie)
        {
            case 1:
                {
                    cin >> dane.imieAktora >> dane.nazwiskoAktora >> dane.imiePostaci >> dane.nazwiskoPostaci >> dane.pierwszy >> dane.ostatni;
                    cout << dane.imieAktora << " " << dane.nazwiskoAktora << " " << dane.imiePostaci << " " << dane.nazwiskoPostaci << " " << dane.pierwszy << " " << dane.ostatni << endl;
                    break;
                }
            case 2:
                {
                    //sortujAktorow();
                    break;
                }
            case 3:
                {
                    //sortujPostaci();
                    break;
                }
            case 4:
                {
                    cin >> index;
                    cout << index << endl;
                    break;
                }
        }
    }
}
