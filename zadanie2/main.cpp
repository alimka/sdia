#include<iostream>
#include<string>
#include "book.h"

using namespace std;

int main()
{
    Book lista;
    lista.dodaj("Katarzyna","Cieślińska", "Emanuela", "García", 1335, 93 );
    lista.dodaj("Sławek" ,"Borzdyński" ,"Dario" ,"Fernández", 70, 33333);
    lista.dodaj("Agnieszka","Cieślińska", "Catalina", "García", 12345, 9376 );
    lista.dodaj("Judyta" ,"Borzdyński" ,"Antonia" ,"Fernández", 70, 337);


    cout << "Ilość elementów w liście: " << lista.ileElementow() << endl;

    lista.sortujAktorow(lista, 1, lista.ileElementow());

    Book temp;
    for (int i = 0; i < lista.ileElementow(); i++)
        temp.dodaj("tmp", "tmp", "tmp", "tmp", 0, 0);

    cout << "Posortowani aktorzy: " << endl;
    lista.drukuj();
    cout << endl << endl;
    cout << "4-ty element listy: " << lista[4] << endl;

    lista.sortujPostaci(lista, temp, 1, lista.ileElementow());
    cout << "Posortowane postacie: " << endl;
    lista.drukuj();
    //lista.drukuj(1);
    //lista[1];


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
                    lista.dodaj(imieAktora, nazwiskoAktora, imiePostaci, nazwiskoPostaci, pierwszyOdcinek, ostatniOdcinek);
                    break;
                }
            case 2:
                {
                    lista.sortujAktorow(lista, 1, lista.ileElementow());
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
                    lista.drukuj(index);
                    break;
                }
        }
    }
   return 0;
}
