#include <bits/stdc++.h>

using namespace std;

int minNumOfBoats(vector<int> w, int W, int B)
{
    sort(w.begin(), w.end());
    int n = w.size(), ans = 0;

    vector<bool> isTaken(n, false);

    int p = 0;
    priority_queue<pair<int, int>> Q;

    for (int i = n - 1; i >= 0; i--)
    {
        while (p < i && w[p] + w[i] <= W)
            Q.push({w[p], p++});

        if (isTaken[i])
            continue;

        // Below statement was not in the original statement
        // But without this it gives wrong result
        // if (!Q.empty() && Q.top().second == i)
        //     Q.pop();

        while (!Q.empty() && w[i] - Q.top().first <= B)
        {
            // comaprison after || in below line was not present in the original implementation
            // but without that comparison it returns wrong answer
            if (isTaken[Q.top().second] || Q.top().second == i)
            {
                Q.pop();
                continue;
            }
            isTaken[i] = isTaken[Q.top().second] = true;
            Q.pop();
            break;
        }
        ans++;
    }
    return ans;
}

int main()
{
    vector<int> w = {81, 37, 32, 88, 55, 93, 45, 72};

    int res = minNumOfBoats(w, 100, 10);

    cout << res << endl;

    return 0;
}