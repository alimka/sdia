#ifndef BOOK_H
#define BOOK_H



using namespace std;


class Book
{
public:
    string aktor, postac;
    int pierwszyOdcinek, ostatniOdcinek;

    Book* next;
    Book* prev;

    Book();
    Book (string aktor, string postac, int pierwszyOdcinek, int ostatniOdcinek);

    Book& operator[](int q);
    //void operator=(Book& a);
    friend ostream& operator<<(ostream& os, Book& a);

    void dodaj(string aktor, string postac, int pierwszyOdcinek, int ostatniOdcinek);
    void drukuj();
    void drukuj(int i);
    int ileElementow();
    void sortujAktorow(Book& a, int l, int p);
    void sortujPostaci(Book& a, Book& temp, int l, int p);
    void swap(Book& x, Book& a);
    friend void podstaw(Book& x, Book& a);
    friend void scalaj(Book& a, Book& temp, int l, int v, int p);
};

#endif // BOOK_H
