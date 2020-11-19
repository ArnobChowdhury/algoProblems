#include <bits/stdc++.h>

using namespace std;

int maxVal(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, arr[i]);

    return maxVal;
}

long long sumOfAll(int arr[], int n)
{
    long long sum = 0;
    for (int i = 0; i <= n; i++)
        sum += arr[i];

    return sum;
}

bool isValid(int arr[], int n, int k, long long C)
{
    long long sum = 0;
    int ridesCnt = 1;
    for (int i = 0; i <= n; i++)
        if (sum + arr[i] <= C)
            sum += arr[i];
        else
        {
            ridesCnt++;
            sum = arr[i];
        }
    return ridesCnt <= k;
}

long long bSearch(int arr[], int n, int k)
{
    long long left = maxVal(arr, n), right = sumOfAll(arr, n), ans;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (isValid(arr, n, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    int arr[6] = {7, 3, 2, 3, 1, 8};
    // int n = 6;
    // int k = 3;
    long long res = bSearch(arr, 6, 3);

    cout << res << endl;

    return 0;
}