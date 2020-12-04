#include <bits/stdc++.h>

using namespace std;

int sumOfAllMultiplesOfThreeAndFive(int n)
{
    int result = 0;
    if (n == 2)
    {
        return 0;
    }

    if (n % 3 == 0 || n % 5 == 0)
        result += n;
    return result + sumOfAllMultiplesOfThreeAndFive(n - 1);
}

int main()
{
    int counter = 0;
    for (int i = 3; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            counter += i;
        }
    }

    cout << sumOfAllMultiplesOfThreeAndFive(999) << endl;
    cout << counter << endl;
    return 0;
}