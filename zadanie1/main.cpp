#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int szachy[1001][1001];
int hetmany[1001];
int n;

bool nieSzachowany(int i, int j)
{
    int suma = j + i;
    int roznica = j - i;
    for (int z = 0; z < i; ++z)
    {
        if ((hetmany[z] + z == suma) ||(hetmany[z] - z == roznica) || (hetmany[z] == j)) return false;
    }
    return true;
}

void ustawHetmana(int i)
{
    for ( int j = 0; j < n; ++j)
    {
        if (szachy[i][j] == 1 && nieSzachowany(i, j))
        {
            hetmany[i] = j;
            if ( i == n - 1 )
            {
                for (int x = 0; x < n; ++ x)
                {
                    cout << hetmany[x] << endl;
                }
                exit(0);
            }
            ustawHetmana(i+1);
        }
    }
}

int main()
{
    int a, b, c, d;

    int k;
    scanf("%d %d", &n, &k);
    while (k--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = b; i <= d; ++i)
        {
            for (int j = a; j <= c; ++j)
            {
                szachy[i][j] = 1;
            }
        }
    }

    ustawHetmana(0);
    cout << "NIE" << endl;
    return 0;
}
