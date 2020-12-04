// You are given a knapsack of capacity G and N objects
// by their weights w[i] and values v[i]. Fill the knapsack
// such that the sum of the value is maximum. You can split
// and object in serveral parts.
#include <bits/stdc++.h>

using namespace std;

struct obj
{
    int w;
    double vpu;
    bool operator<(const obj &x) const { return vpu > x.vpu; };
};

const int Nmax = 1000;
obj a[Nmax];

int main()
{
    int n = 7, G = 10;
    int valueWeightArray[8][2] = {{0, 0},
                                  {10, 2},
                                  {5, 3},
                                  {15, 5},
                                  {7, 7},
                                  {6, 1},
                                  {18, 4},
                                  {3, 1}};

    for (int i = 1; i <= n; i++)
    {
        // int v, w;
        // cin >> v >> w;
        a[i].w = valueWeightArray[i][1];
        a[i].vpu = (double)valueWeightArray[i][0] / valueWeightArray[i][1];
    }

    sort(a + 1, a + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = min(a[i].w, G);
        ans += q * a[i].vpu;
        G -= q;
    }

    cout << ans << endl;
}
