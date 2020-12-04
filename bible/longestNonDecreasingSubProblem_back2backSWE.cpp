#include <bits/stdc++.h>

using namespace std;

const int n = 8;
vector<int> dp(n, 1);

int LongestNonDecreasingSubProplm(vector<int> a)
{
    int si = a.size();
    int ans = 0;

    for (int i = 1; i < si; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    vector<int> a = {-1, 3, 4, 5, 2, 2, 2, 2};
    int res = LongestNonDecreasingSubProplm(a);

    cout << res << endl;
    return 0;
}