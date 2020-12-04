#include <bits/stdc++.h>

using namespace std;

vector<int> findSum(vector<int> nums, int S)
{
    int n = nums.size();

    unordered_map<int, vector<int>> mySums;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                mySums[nums[i] + nums[j] + nums[k]] = {i, j, k};
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                if (mySums.find(S - nums[i] - nums[j] - nums[k]) != mySums.end())
                {
                    int sum = S - nums[i] - nums[j] - nums[k];
                    vector<int> v = mySums[S - nums[i] - nums[j] - nums[k]];
                    return {nums[i], nums[j], nums[k], nums[v[0]], nums[v[1]], nums[v[2]]};
                }
            }
        }
    }
    return {};
}

int main()
{
    vector<int> a = {3, 7, 2, -1, -10};

    vector<int> res = findSum(a, 21);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}