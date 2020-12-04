#include <bits/stdc++.h>

using namespace std;

int getValue(int n, int x, int y)
{
    if (n == 0)
        return 1;

    if (x <= 1 << (n - 1))
    {
        if (y <= 1 << (n - 1))
            return getValue(n - 1, x, y);

        return (1 << (2 * n - 2)) + getValue(n - 1, x, y - (1 << (n - 1)));
    }
    if (y <= 1 << (n - 1))
        return (1 << (2 * n - 1)) + getValue(n - 1, x - 1 << (n - 1), y);

    return 3 * (1 << (2 * n - 2)) + getValue(n - 1, x - 1 << (n - 1), y - 1 << (n - 1));
}

int main()
{
    int res = getValue(2, 2, 3);

    cout << res << endl;
}