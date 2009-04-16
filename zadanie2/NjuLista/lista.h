#ifndef LISTA_H
#define LISTA_H

#include <string>

using namespace std;

template<class T>
class Lista
{
public:
    T element;

    T* next;
    T* prev;

    Lista();
    Lista(T element);

    T operator[](int q);
    friend ostream& operator<<(ostream& os, Book& a);

    void dodaj(T element);
    void drukuj();
    void drukuj(int i);
    int ileElementow();
    void sortujAktorow();
    void sortujPostaci();
};

#endif // LISTA_H
