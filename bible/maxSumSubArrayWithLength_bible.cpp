// lets skip this solution as it is giving wrong result for some values
#include <bits/stdc++.h>

using namespace std;

int maxSum(int a[], int n, int A, int B)
{
    vector<int> s(n + 1);

    int ans = 0;
    s[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    deque<int> dq;
    dq.push_back(0);

    for (int Right = 1; Right <= n; Right++)
    {
        if (!dq.empty() && dq.front() < Right - B)
            dq.pop_back();
        if (Right >= A)
        {
            int summ = s[Right] - s[dq.front()];
            ans = max(ans, s[Right] - s[dq.front()]);
        }
        while (!dq.empty() && s[dq.back()] >= s[Right])
            dq.pop_back();

        dq.push_back(Right);
    }

    return ans;
}

int main()
{
    // int a[8] = {0, 2, -9, 7, -2, 8, -1, 1};
    int a[5] = {0, 2, -9, 7, -5};

    int res = maxSum(a, 4, 2, 4);

    cout << res << endl;

    return 0;
}