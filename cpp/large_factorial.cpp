#include <iostream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

string factorial(int A) // A = 4
{
    if (A == 0)
    {
        return "1";
    }
    string s1 = "1", s2 = "";
    for (int i = 2; i <= A; i++) // n - 1 *
    {
        int c = 0;
        for (int j = s1.size() - 1; j >= 0; j--) // n = 1, n = 2 -> 1 time, n = 3 -> 1 time, n = 4 -> 3 times, n = 20 -> 18 times
        {
            int s = (s1[j] - '0') * i + c;
            c = s / 10;
            s = s % 10;
            s2 += (s + '0');
            ran++;
        }
        string s3 = to_string(c);
        reverse(s3.begin(), s3.end());
        if (c != 0)
        {
            s2 += s3;
        }
        reverse(s2.begin(), s2.end());
        s1 = s2;
        s2 = "";
    }
    return s1;
}

int main()
{
    int n;
    cin >> n;
    string res = factorial(n);
    cout << res << endl;
    return 0;
}