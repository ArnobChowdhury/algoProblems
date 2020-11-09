#include <bits/stdc++.h>

using namespace std;

// Find the max sum subarray for a fixed size k;
// Example input
// [4, 2, 1, 7, 8, 1, 2, 8, 1, 0]

int maxSumSubArray(int arr[], int n, int k)
{
    int maxSum = INT_MIN;
    int runningSum = 0;

    for (int i = 0; i < n; i++)
    {
        runningSum += arr[i];
        if (i >= k - 1)
        {
            maxSum = max(maxSum, runningSum);
            runningSum -= arr[i - (k - 1)];
        }
    }
    return maxSum;
}

int main()
{
    int arr[10] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};

    int res = maxSumSubArray(arr, 10, 3);
    cout << res << endl;

    return 0;
}