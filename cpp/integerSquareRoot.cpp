#include <bits/stdc++.h>

using namespace std;

int squareRoot(int n)
{
    int left = 0, right = n, mid, ans;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if ((mid * mid) == n)
            return mid;

        if ((mid * mid) > n)
            right = mid - 1;
        else
        {
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int res = squareRoot(n);

    cout << res << endl;

    return 0;
}