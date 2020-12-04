#include <bits/stdc++.h>

using namespace std;

struct Activity
{
    int start, finish;
    bool operator<(const Activity &x) const
    {
        return finish < x.finish;
    }
};

const int Nmax = 1005;

Activity act[Nmax];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> act[i].start;
        cin >> act[i].finish;
    }

    sort(act + 1, act + n + 1);
    int ans = 0, curFinish = -1;

    for (int i = 1; i <= n; i++)
    {
        if (curFinish < act[i].start)
        {
            ans++;
            curFinish = act[i].finish;
        }
    }

    cout << ans << endl;
    return 0;
}
