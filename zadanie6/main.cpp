#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int liczbaLinijek;
    string linijka, znak, tmp;

    stack<string> stos;

    cin >> liczbaLinijek;
    cin.ignore();
    
    while (liczbaLinijek--)
    {
        getline(cin, tmp);
        istringstream iss(tmp);

        while(!iss.eof())
        {
            iss >> znak;

            if (znak == "(") stos.push(znak);

            else if (znak == ")")
            {
                while (stos.top() != "(")
                {
                    cout << stos.top() << " ";
                    stos.pop();
                }
                stos.pop();
            }

            else if (znak == "^")
            {
                if (!stos.empty() && stos.top() == "^")
                {
                    cout << stos.top() << " ";
                    stos.pop();
                }
                stos.push(znak);
            }

            else if (znak == "*" || znak == "/")
            {
                while (!stos.empty() && (stos.top() == "^" || stos.top() == "*" || stos.top() == "/"))
                {
                    cout << stos.top() << " ";
                    stos.pop();
                }
                stos.push(znak);
            }

            else if (znak == "-" || znak == "+")
            {
                while (!stos.empty() && (stos.top() == "^" || stos.top() == "*" || stos.top() == "/" || stos.top() == "+" || stos.top() == "-"))
                {
                    cout << stos.top() << " ";
                    stos.pop();
                }
                stos.push(znak);
            }

            else cout << znak << " ";

        }

        while (!stos.empty())
        {
            cout << stos.top() << " ";
            stos.pop();
        }

        cout << "\n";
    }
    return 0;
}
