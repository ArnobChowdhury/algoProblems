#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100005;

long long sumOf(int arr[], int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

bool isValid(int arr[], int n, int k, long long x)
{
    long long count = 0;
    for (int i = 0; i < n; i++)
        count += min(x, 1LL * arr[i]);
    return count >= 1LL * x * k;
}

long long bSearch(int arr[], int n, int k)
{
    long long left = 0, right = sumOf(arr, n), ans;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (isValid(arr, n, k, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int main()
{
    int n = 7;
    int k = 5;

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    int res = bSearch(arr, n, k);

    cout << res << endl;
    return 0;
}