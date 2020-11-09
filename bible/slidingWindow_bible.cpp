#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100005;

int fr[Nmax];

// my code for this problem
int longestSubArrayWithKDistinctElements(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        fr[arr[i]] = 0;
    }

    int currentDistinctElements = 0;
    int leftPtr = 0;
    int lengthOfLongestSubArray = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (fr[arr[i]] == 0)
            currentDistinctElements += 1;
        fr[arr[i]] += 1;

        while (currentDistinctElements > k)
        {
            fr[arr[leftPtr]]--;

            if (fr[arr[leftPtr]] == 0)
            {
                currentDistinctElements--;
            }

            leftPtr++;
        }
        lengthOfLongestSubArray = max(lengthOfLongestSubArray, i - leftPtr + 1);
    }
    return lengthOfLongestSubArray;
}

int main()
{
    int arr[10] = {1, 5, 2, 1, 7, 2, 1, 5, 5, 7};
    int res = longestSubArrayWithKDistinctElements(arr, 10, 3);
    cout << res << endl;
    return 0;
}

// original code from bible
// int slidingWindow(int a[], int n, int k)
// {
//     int ans = 0, counter = 0, right;

//     for (right = 1; right <= n; right++)
//     {
//         if (++fr[a[right]] == 1)
//             counter++;
//         if (counter > k)
//             break;
//     }
//     if (counter <= k)
//         return n;
//     if (--fr[a[right--]] == 0)
//         counter--;

//     for (int left = 2; left <= n; left++)
//     {
//         if (--fr[a[left - 1]] == 0)
//             counter--;

//         while (right < n)
//         {
//             if (++fr[a[++right]] == 1)
//                 counter++;
//             if (counter > k)
//                 break;
//         }

//         if (counter <= k)
//             return max(ans, n - left + 1);
//         if (--fr[a[right]] == 0)
//             counter--;
//         ans = max(ans, right - left + 1);
//     }
//     return ans;
// }
