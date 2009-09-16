#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <climits>

using namespace std;

const int infty = -1; // symboliczne oznaczenie nieskończoności

vector<int> waga;

class cmp
{
public:
    bool operator()(const int& a, const int& b)
    {
        if (waga[a] == waga[b]) return a < b;
        return waga[a] < waga[b];
    }
};
priority_queue< int, vector<int>, cmp> kopiec;

int n, s, d, m; // n - liczba miejscowości, s - miejscowość startowa, d - miejscowość docelowa, m - trójki
int a, b, c; // c jest wagą krawędzi łączącą miejscość a z miejscowością b
int elem, size, kuzyn, kuzynW;

int main()
{
    scanf("%d %d %d %d", &n, &s, &d, &m);

    vector< pair<int,int> > graf[n];

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        graf[a].push_back( pair<int,int>(b,c) );
        graf[b].push_back( pair<int,int>(a,c) );
    }

    waga.resize(n, infty);

    waga[s] = INT_MAX;

    for (int i=0; i<n; i++) kopiec.push(i);

    while( !kopiec.empty() )
    {
        elem = kopiec.top();
        kopiec.pop();
        size = graf[elem].size();
        for (int i = 0; i < size; i++)
        {
            kuzyn = graf[elem][i].first;
            kuzynW = graf[elem][i].second;

            if (waga[kuzyn] < min(waga[elem], kuzynW))
            {
                waga[kuzyn] = min(waga[elem], kuzynW);
                kopiec.push(kuzyn);
            }
        }
    }

    cout << waga[d] << endl;

    return 0;
}
