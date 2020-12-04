#include <bits/stdc++.h>

using namespace std;

// const int Nmax = 100005;
// const int Mmax = 100005;

long long maxRectArea(vector<int> h)
{
    int n = h.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> stOne, stTwo;

    for (int i = 0; i < n; i++)
    {
        while (!stOne.empty() && h[i] < h[stOne.top()])
        {
            right[stOne.top()] = i;
            stOne.pop();
        }
        stOne.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stTwo.empty() && h[i] < h[stTwo.top()])
        {
            left[stTwo.top()] = i;
            stTwo.pop();
        }
        stTwo.push(i);
    }
    long long ans = 0;

    for (int k = 0; k < n; k++)
        ans = max(ans, h[k] * (right[k] - left[k] - 1) * 1LL);
    return ans;
}

vector<vector<int>> tower;

int maxSizeRect(vector<vector<int>> a)
{
    int ans = 0;
    // change i

    tower.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
        {
            int item = a[i][j];
            if (a[i][j] == 0)
                tower[i].push_back(0);
            // tower[i][j] = 0;
            else
            {
                if (i == 0)
                    tower[i].push_back(1);
                else
                    // int pushing = tower[i - 1][j];
                    tower[i].push_back(1 + tower[i - 1][j]);
                // tower[i][j] = 1 + tower[i - 1][j];
            }
        }
    for (int i = 0; i < a.size(); i++)
        ans = max(ans * 1LL, maxRectArea(tower[i]));
    return ans;
}

int main()
{
    vector<vector<int>> a{{1, 1, 0, 1, 1, 0, 1},
                          {1, 1, 1, 0, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1},
                          {0, 1, 1, 1, 1, 0, 1}};

    int res = maxSizeRect(a);
    cout << res << endl;
    return 0;
}