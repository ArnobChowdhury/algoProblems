#include <bits/stdc++.h>

using namespace std;

vector<int> maxset(vector<int> &A)
{
    vector<int> res, localRes;
    long long max = 0, localMax = INT_MIN;

    for (auto i : A)
    {
        if (i < 0)
        {
            localMax = 0, localRes.clear();
            continue;
        }
        localMax += i;
        localRes.emplace_back(i);
        if (max < localMax or (max == localMax and res.size() < localRes.size()))
        {
            max = localMax;
            res = localRes;
        }
    }
    return res;
}

int main()
{
    vector<int> A;
    // A.push_back(1);
    // A.push_back(2);
    // A.push_back(5);
    // A.push_back(-7);
    // A.push_back(2);
    // A.push_back(3);
    // 1967513926, 1540383426, -1303455736, -521595368

    A.push_back(5);
    A.push_back(4);
    A.push_back(1);
    A.push_back(-1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(-4);
    A.push_back(100);
    // A.push_back(1967513926);
    // A.push_back(1540383426);
    // A.push_back(-1303455736);
    // A.push_back(-521595368);

    vector<int> res = maxset(A);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
