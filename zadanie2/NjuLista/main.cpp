 #include<iostream>
#include<string>
#include "lista.h"

using namespace std;

int main()
{

    int liczbaPolecen, polecenie, index;

    cin >> liczbaPolecen;
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        switch(polecenie)
        {
            case 1:
                {
                    string imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci;
                    int pierwszyOdcinek, ostatniOdcinek;
                    cin >> imieAktora >> nazwiskoAktora >> imiePostaci >> nazwiskoPostaci >> pierwszyOdcinek >> ostatniOdcinek;
                    //lista.dodaj(imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci, pierwszyOdcinek, ostatniOdcinek);
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
                    cout << "Index: " << index << endl;
                    //lista.drukuj(index);
                    break;
                }
        }
    }
   return 0;
}

