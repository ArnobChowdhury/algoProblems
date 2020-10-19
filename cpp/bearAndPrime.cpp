#include <bits/stdc++.h>
using namespace std;

bitset<101> b;
int number;
vector<int> primes;

void sieve()
{
    b.set();
    b[0] = 0;
    b[1] = 1;

    for (int i = 2; i <= number; i++)
    {
        if (b[i] == 1)
        {
            primes.push_back(i);
            for (int j = i * i; j <= number; j += i)
                b[j] = 0;
        }
    }
}

signed main()
{
    number = 100;

    sieve();
    int flag = 0;
    for (int i = 0; i < 15; i++)
    {
        cout << primes[i] << endl;
        cout << flush;
        string s;
        cin >> s;
        if (s == "yes")
        {
            flag++;
            if (flag == 1 && primes[i] * primes[i] <= 100)
            {
                cout << primes[i] * primes[i] << endl;
                cin >> s;
                if (s == "yes")
                {
                    flag++;
                    break;
                }
            }
        }
        if (flag >= 2)
            break;
    }
    if (flag >= 2)
        cout << "composite";
    else
        cout << "prime";

    return 0;
}