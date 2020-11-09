#include <iostream>

using namespace std;

const int Nmax = 100005;
int s[Nmax];

void buildPartialSums(int a[], int n)
{
    s[0] = a[0];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
}

long long query(int x, int y)
{
    return s[y] - s[x - 1];
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    buildPartialSums(a, 9);

    long long b = query(5, 9);
    cout << b << endl;
    return 0;
}