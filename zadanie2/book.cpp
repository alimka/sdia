#include <iostream>
#include "book.h"

using namespace std;

Book::Book()
{
    next = NULL;
    prev = NULL;
}

Book::Book (string aktor, string postac, int pierwszyOdcinek, int ostatniOdcinek)
{
    this->aktor = aktor;
    this->postac = postac;
    this->pierwszyOdcinek = pierwszyOdcinek;
    this->ostatniOdcinek = ostatniOdcinek;

    next = NULL;
    prev = NULL;
}

void Book::dodaj(string aktor, string postac, int pierwszyOdcinek, int ostatniOdcinek)
{
    Book *nowy = new Book (aktor, postac, pierwszyOdcinek, ostatniOdcinek);
    Book *ostatni = this;
    while (ostatni->next != NULL)
    {
        ostatni = ostatni-> next;
    }
    ostatni -> next = nowy;
    (ostatni -> next) -> prev = ostatni;
}

void Book::drukuj()
{
    Book *ostatni = this;
    ostatni = ostatni->next;
    while (ostatni->next != NULL)
    {
        cout << ostatni->aktor<<" "<<ostatni->postac << " " << ostatni->pierwszyOdcinek << " " << ostatni->ostatniOdcinek << endl;
        ostatni = ostatni -> next;
    }
    cout << ostatni->aktor<<" "<< ostatni->postac << " " << ostatni->pierwszyOdcinek << " " << ostatni->ostatniOdcinek << endl;
}

void Book::drukuj(int i)
{
    int licznik = 0;
    Book *ostatni = this;
    ostatni = ostatni->next;
    while ((licznik < i)&&(ostatni->next != NULL))
    {
        ostatni = ostatni -> next;
        licznik++;
    }
    cout << ostatni->aktor<<" "<< ostatni->postac << " " << ostatni->pierwszyOdcinek << " " << ostatni->ostatniOdcinek << endl;
}

void Book::sortujAktorow(Book& a, int l, int p) //QuickSort
{
    string v=a[(l+p)/2].aktor;
    int i = l;
    int j = p;
    do
    {
        while (a[i].aktor < v)
            i++;
        while (v < a[j].aktor)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) sortujAktorow(a,l,j);
    if (i < p) sortujAktorow(a,i,p);
}

void Book::sortujPostaci(Book& a, Book& temp, int l, int p) //Mergesort
{
    int v;

    if ( p > l )
    {
        v = (p+l)/2;
        sortujPostaci(a, temp, l, v);
        sortujPostaci(a, temp, (v+1), p);

        scalaj(a, temp, l, (v+1), p);
    }
}

void scalaj(Book& a, Book& temp, int l, int v, int p)
{
    int i, left_end, num_elem, tmp_pos;

    left_end = v - 1;
    tmp_pos = l;
    num_elem = p - l + 1;

    while ((l <= left_end) && (v <= p))
    {
        if (a[l].postac <= a[v].postac)
        {
            podstaw(temp[tmp_pos], a[l]);
            tmp_pos++;
            l++;
        } else {
            podstaw(temp[tmp_pos], a[v]);
            tmp_pos++;
            v++;
        }
    }

    while ( l <= left_end)
    {
        podstaw(temp[tmp_pos], a[l]);
        tmp_pos++;
        l++;
    }

    while ( v <= p )
    {
        podstaw(temp[tmp_pos], a[v]);
        tmp_pos++;
        v++;
    }

    for (i = 0; i <= num_elem; i++)
    {
        podstaw(a[p], temp[p]);
        p--;
    }
}


Book& Book::operator [](int q)
{
    int licznik = 0;
    Book* ostatni = this;
    while ((licznik < q)&&(ostatni->next != NULL))
    {
        ostatni = ostatni->next;
        licznik++;
    }
    //cout << ostatni->imieAktora<<" "<<ostatni->nazwiskoAktora<<" "<< ostatni->imiePostaci << " " << ostatni->nazwiskoPostaci << " " << ostatni->pierwszyOdcinek << " " << ostatni->ostatniOdcinek << endl;
    Book& a = *ostatni;
    return a;
}

ostream& operator<<(ostream& os, Book& a)
{
    os << a.aktor << " " << a.postac << " " << a.pierwszyOdcinek << " " << a.ostatniOdcinek << endl;
    return os;
}

int Book::ileElementow()
{
    int licznik = 0;
    Book *ostatni = this;
    while (ostatni->next != NULL)
    {
        licznik++;
        ostatni = ostatni -> next;
    }
    return licznik;
}

/*void Book::operator=(Book& a)
                    {
    this->imieAktora = a.imieAktora;
    this->imiePostaci = a.imiePostaci;
    this->nazwiskoAktora = a.nazwiskoAktora;
    this->nazwiskoPostaci = a.nazwiskoPostaci;
    this->ostatniOdcinek = a.ostatniOdcinek;
    this->pierwszyOdcinek = a.pierwszyOdcinek;
}*/

void podstaw(Book &x, Book &a)
{
    x.aktor = a.aktor;
    x.postac = a.postac;
    x.ostatniOdcinek = a.ostatniOdcinek;
    x.pierwszyOdcinek = a.pierwszyOdcinek;
}

void Book::swap(Book& x, Book& a)
{
    Book tmp;

    tmp.aktor = x.aktor;
    tmp.postac = x.postac;
    tmp.ostatniOdcinek = x.ostatniOdcinek;
    tmp.pierwszyOdcinek = x.pierwszyOdcinek;

    x.aktor = a.aktor;
    x.postac = a.postac;
    x.ostatniOdcinek = a.ostatniOdcinek;
    x.pierwszyOdcinek = a.pierwszyOdcinek;

    a.aktor = tmp.aktor;
    a.postac = tmp.postac;
    a.ostatniOdcinek = tmp.ostatniOdcinek;
    a.pierwszyOdcinek = tmp.pierwszyOdcinek;
}
