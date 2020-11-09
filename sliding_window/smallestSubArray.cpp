#include <bits/stdc++.h>

using namespace std;

// Smallest sub array with a given sum S;
// Example input
// [4, 2, 2, 7, 8, 1, 2, 8, 1, 0]

int smallestSubArrayWithGivenSum(int arr[], int n, int s)
{
    int minSubArraySize = INT_MAX;
    int windownStart = 0;
    int runningSum = 0;
    for (int i = 0; i < n; i++)
    {
        runningSum += arr[i];

        while (runningSum >= s)
        {
            minSubArraySize = min(minSubArraySize, i - windownStart + 1);
            runningSum -= arr[windownStart];
            windownStart++;
        }
    }
    return minSubArraySize;
}

int main()
{
    int arr[10] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};

    int res = smallestSubArrayWithGivenSum(arr, 10, 3);
    cout << res << endl;

    return 0;
}