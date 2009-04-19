#include<iostream>
#include "book.h"

using namespace std;

int main()
{
    Book lista;
    /*lista.dodaj("Katarzyna Cieślińska", "Emanuela García", 1335, 93 );
    lista.dodaj("Sławek Borzdyński" ,"Dario Fernández", 70, 33333);
    lista.dodaj("Agnieszka Cieślińska", "Catalina García", 12345, 9376 );
    lista.dodaj("Judyta Borzdyński" ,"Antonia Fernández", 70, 337);


    cout << "Ilość elementów w liście: " << lista.ileElementow() << endl;

    lista.sortujAktorow(lista, 1, lista.ileElementow());

    Book temp;
    for (int i = 0; i < lista.ileElementow(); i++)
        temp.dodaj("tmp tmp", "tmp tmp", 0, 0);

    cout << "Posortowani aktorzy: " << endl;
    lista.drukuj();
    cout << endl << endl;
    cout << "4-ty element listy: " << lista[4] << endl;

    lista.sortujPostaci(lista, temp, 1, lista.ileElementow());
    cout << "Posortowane postacie: " << endl;
    lista.drukuj();
    //lista.drukuj(1);
    //lista[1];*/


    int liczbaPolecen, polecenie, index;

    cin >> liczbaPolecen;
    cin.ignore();
    //cout << "Liczba poleceń: " << liczbaPolecen << endl;
    while (liczbaPolecen--)
    {
        cin >> polecenie;
        cin.ignore();
        //cout << "Nr polecenia: " << polecenie << endl;
        switch(polecenie)
        {
            case 1:
                {
                    //string imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci;
                    string aktor, postac;
                    int pierwszyOdcinek, ostatniOdcinek;
                    getline (cin, aktor);
                    getline (cin, postac);
                    cin >> pierwszyOdcinek;
                    cin.ignore();
                    cin >> ostatniOdcinek;
                    cin.ignore();
                    //cout << aktor << " " << postac << " " << pierwszyOdcinek << " " << ostatniOdcinek << endl;
                    //getline (cin, pierwszyOdcinek);
                    //getline (cin, ostatniOdcinek);
                    //cin >> imieAktora >> nazwiskoAktora >> imiePostaci >> nazwiskoPostaci >> pierwszyOdcinek >> ostatniOdcinek;
                    //lista.dodaj(imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci, pierwszyOdcinek, ostatniOdcinek);
                    lista.dodaj(aktor, postac, pierwszyOdcinek, ostatniOdcinek);
                    //lista.drukuj();
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
