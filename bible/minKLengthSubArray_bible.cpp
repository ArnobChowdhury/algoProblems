#include <bits/stdc++.h>

using namespace std;

vector<int> findMins(int a[], int n, int k)
{
    deque<int> dq;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        dq.push_back(i);
        if (i + 1 >= k)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}

int main()
{
    int a[9] = {-7, 9, 2, -1, 7, 5, 6, 4, 1};
    vector<int> res = findMins(a, 9, 3);

    for (auto &it : res)
        cout << it << endl;
    return 0;
}