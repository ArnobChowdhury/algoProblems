#include <iostream>

using namespace std;

const int Nmax = 100001;

// int s = 10;
const int n = 7;
int a[Nmax];
bool fr[Nmax];

int longestConsecNumSubArray()
{
    int ans = 0;
    for (int left = 0; left < n; left++)
    {
        for (int i = 0; i < n; i++)
            fr[a[i]] = false;

        int Min = a[left], Max = a[left];

        for (int right = left; right < n; right++)
        {
            if (fr[a[right]] == true)
                break;
            fr[a[right]] = true;
            Min = min(Min, a[right]);
            Max = max(Max, a[right]);

            if (right - left == Max - Min)
                ans = max(ans, right - left + 1);
        }
    }

    return ans;
}

int main()
{
    int arr[n] = {6, 1, 3, 4, 5, 2, 7};
    for (int i = 0; i < n; i++)
    {
        a[i] = arr[i];
    }

    int an = longestConsecNumSubArray();
    cout << an << endl;
    return 0;
}