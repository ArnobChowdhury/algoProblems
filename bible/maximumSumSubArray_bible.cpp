#include <iostream>

using namespace std;

long long maxSumSubarray(int a[], int n)
{
    long long sum = 0, ans = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > ans)
            ans = sum;
        if (sum < 0)
            sum = 0;
    }
    return ans;
}

long long maxSumSubarrayKadane(int a[], int n)
{
    long long sum = a[0], ans = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(sum + a[i], 1LL * a[i]);
        ans = max(sum, ans);
    }
    return ans;
}

long long maxSumSubarrayPartialSum(int a[], int n)
{
    int partialSum[n];
    partialSum[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        partialSum[i] = a[i] + partialSum[i - 1];
    }

    long long sum = 0, ans = a[0];
    int minS = 0;
    for (int i = 1; i < n; i++)
    {
        if (partialSum[i] - minS > ans)
            ans = partialSum[i] - minS;
        if (partialSum[i] < minS)
            minS = partialSum[i];
    }

    return ans;
}

int main()
{
    const int s = 7;
    int a[s] = {5, -6, 3, 4, -2, 3, -3};
    long long b = maxSumSubarray(a, s);
    long long b2 = maxSumSubarrayKadane(a, s);
    long long b3 = maxSumSubarrayPartialSum(a, s);
    cout << "b " << b << endl;
    cout << "b2 " << b2 << endl;
    cout << "b3 " << b3 << endl;
    return 0;
}