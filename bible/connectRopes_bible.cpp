#include <bits/stdc++.h>

using namespace std;

long long connectRopes(vector<int> ropes)
{
    long long ans = 0;
    priority_queue<int> pq;

    for (int rope : ropes)
        pq.push(-rope);

    for (int step = 1; step < ropes.size(); step++)
    {
        int minOne = -pq.top();
        pq.pop();
        int minTwo = -pq.top();
        pq.pop();

        ans += minOne + minTwo;
        pq.push(-(minOne + minTwo));
    }
    return ans;
}

int main()
{
    vector<int> ropes = {4, 3, 2, 6};

    long long res = connectRopes(ropes);

    cout << res << endl;
    return 0;
}