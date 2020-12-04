#include <bits/stdc++.h>

using namespace std;

const int N = 666013, x = 13;
vector<pair<string, int>> H[N];

int hFunc(string s)
{
    int key = 0;
    for (int i = 0; i < s.size(); i++)
    {
        key = (key * x + s[i]) % N;
    }
    return key;
}

void add(string s)
{
    int key = hFunc(s);
    for (auto &x : H[key])
    {
        if (x.first == s)
        {
            x.second++;
            return;
        }
    }
    H[key].push_back(make_pair(s, 1));
}

int find(string s)
{
    int key = hFunc(s);
    for (auto x : H[key])
        if (x.first == s)
            return x.second;

    return 0;
}

int main()
{
    return 0;
}