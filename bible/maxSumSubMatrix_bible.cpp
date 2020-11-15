#include <bits/stdc++.h>

using namespace std;

const int Nmax = 101;
const int Mmax = 101;

int a[Nmax][Mmax], n, m;

int maxSumSubArrayKadane(int arr[], int l)
{
    int maxGlobal = INT_MIN;

    int maxRunning = 0;
    for (int i = 0; i < l; i++)
    {
        maxRunning += arr[i];

        if (arr[i] > maxRunning)
        {
            maxRunning = arr[i];
        }

        if (maxRunning > maxGlobal)
        {
            maxGlobal = maxRunning;
        }
    }
    return maxGlobal;
}

int maxSumSubMatrix(int arr[][5], int n, int m)
{
    int funcMax = INT_MIN;
    for (int left = 0; left < m; left++)
    {

        int currentArr[n];
        for (int s = 0; s < n; s++)
        {
            currentArr[s] = 0;
        }

        for (int right = left; right < m; right++)
        {
            int runningSum = 0;
            for (int i = 0; i < n; i++)
            {
                currentArr[i] += arr[i][right];
            }
            int runningMax = maxSumSubArrayKadane(currentArr, n);

            funcMax = max(funcMax, runningMax);
        }
    }
    return funcMax;
}

int main()
{
    // int arr[4] = {-2, -7, -5, 1};
    // int res = maxSumSubArrayKadane(arr, 4);

    int arr[4][5] = {{6, -5, -7, 4, -4},
                     {-9, 3, -6, 5, 2},
                     {-10, 4, 7, -6, 3},
                     {-8, 9, -3, 3, -7}};
    int res = maxSumSubMatrix(arr, 4, 5);
    cout
        << res << endl;

    return 0;
}