#include<iostream>
#include "book.h"

using namespace std;

int main()
{
    Book lista;
    int liczbaPolecen, polecenie, index;

    cin >> liczbaPolecen;
    cin.ignore();
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        cin.ignore();
        switch(polecenie)
        {
            case 1:
                {
                    string aktor, postac;
                    int pierwszyOdcinek, ostatniOdcinek;
                    getline (cin, aktor);
                    getline (cin, postac);
                    cin >> pierwszyOdcinek;
                    cin.ignore();
                    cin >> ostatniOdcinek;
                    cin.ignore();
                    lista.dodaj(aktor, postac, pierwszyOdcinek, ostatniOdcinek);
                    break;
                }
            case 2:
                {
                    lista.sortujAktorow(lista, 1, lista.ileElementow());
                    break;
                }
            case 3:
                {
                    Book temp;
                    for (int i = 0; i < lista.ileElementow(); i++)
                        temp.dodaj("tmp tmp", "tmp tmp", 0, 0);

                    lista.sortujPostaci(lista, temp, 1, lista.ileElementow());
                    break;
                }
            case 4:
                {
                    cin >> index;
                    cout << "Index: " << index << endl;
                    lista.drukuj(index);
                    break;
                }
        }
    }
   return 0;
}
