#include <bits/stdc++.h>

using namespace std;

int maxLeftSum(int a[], int left, int mid)
{
    int maxS = a[mid], sum = 0;
    for (int l = mid; l >= left; l--)
    {
        sum += a[l];
        maxS = max(maxS, sum);
    }

    return maxS;
}

int maxRightSum(int a[], int mid, int right)
{
    int maxS = a[mid + 1], sum = 0;
    for (int r = mid + 1; r <= right; r++)
    {
        sum += a[r];
        maxS = max(maxS, sum);
    }

    return maxS;
}

int maxSumSubArray(int a[], int left, int right)
{
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;

    int maxSubArrayLeft = maxSumSubArray(a, left, mid);
    int maxSubArrayRight = maxSumSubArray(a, mid + 1, right);

    int ans = max(maxSubArrayLeft, maxSubArrayRight);

    int answerOfMaxLeftSum = maxLeftSum(a, left, mid);
    int answerOfMaxRightSum = maxRightSum(a, mid, right);

    return max(ans, answerOfMaxLeftSum + answerOfMaxRightSum);
}

int main()
{
    int a[7] = {5, -6, 3, 4, -2, 3, -3};
    // int a[5] = {10, -2, 4, 6, 5};
    int res = maxSumSubArray(a, 0, 6);
    // int res = maxSumSubArray(a, 0, 4);

    cout << res << endl;
    return 0;
}