#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int liczbaUrz, liczbaParAnty, liczbaParSymp, a, b;
vector<int> antypatie[10000];
vector<int> sympatie[10000];
int grupa[10000];
queue<int> kolejka;

int main ()
{
    cin >> liczbaUrz;
    for (int i = 0; i < liczbaUrz; i++)
        grupa[i] = -1;

    cin >> liczbaParAnty;
    while (liczbaParAnty--) {
        cin >> a >> b;
        antypatie[a].push_back(b);
        antypatie[b].push_back(a);
    }

    cin >> liczbaParSymp;
    while (liczbaParSymp--) {
        cin >> a >> b;
        sympatie[a].push_back(b);
        sympatie[b].push_back(a);
    }

    int elem, size, kuzyn;
    for (int i = 0; i < liczbaUrz; ++i)
    {
        if(grupa[i] == -1)
        {
            grupa[i] = 0;
            kolejka.push(i);
            while (!kolejka.empty()) {
                elem = kolejka.front();
                kolejka.pop();
                size = sympatie[elem].size();
                for (int i = 0; i < size; ++i) {
                    kuzyn = sympatie[elem][i];
                    if (grupa[kuzyn] ==  -1) {
                        grupa[kuzyn] = grupa[elem];
                        kolejka.push(kuzyn);
                    } else if (grupa[kuzyn] != grupa[elem]) {
                        cout << "NO" << endl;
                        exit(0);
                    }
                }
                size = antypatie[elem].size();
                for (int i = 0; i < size; ++i) {
                    kuzyn = antypatie[elem][i];
                    if (grupa[kuzyn] == -1) {
                        grupa[kuzyn] = (grupa[elem] ? 0:1);
                        kolejka.push(kuzyn);
                    } else if (grupa[kuzyn] == grupa[elem]){
                        cout << "NO" << endl;
                        exit(0);
                    }
                }

            }
        }
    }

    for (int i = 0; i < liczbaUrz; ++i) {
        cout << grupa[i] << endl;
    }

    return 0;
}
