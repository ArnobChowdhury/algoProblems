#include <iostream>

using namespace std;

const int Nmax = 100005;
int a[Nmax];
int b[Nmax];
int s[Nmax];

void update(int x, int y, int val)
{
    b[x] += val;
    b[y + 1] -= val;
}

void buildFinalArray(int n)
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + b[i];
        a[i] += s[i];
    }
}

int main()
{
}