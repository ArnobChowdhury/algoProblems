#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100005;

int ans[Nmax];

void buildAns(int a[], int n)
{
    stack<int> S;

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && a[S.top()] < a[i])
        {
            ans[S.top()] = i;
            S.pop();
        }
        S.push(i);
    }
}

int main()
{
    int a[Nmax] = {5, 4, 3, 2, 1};
    int n = 5;

    buildAns(a, n);

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}