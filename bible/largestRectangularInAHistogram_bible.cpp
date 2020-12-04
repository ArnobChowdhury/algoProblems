#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    vector<int> h;
    h.push_back(6);
    h.push_back(2);
    h.push_back(5);
    h.push_back(4);
    h.push_back(5);
    h.push_back(1);
    h.push_back(6);

    int res = maxRectArea(h);

    cout << res << endl;

    return 0;
}