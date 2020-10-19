#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool totalPrimes[n + 1];

    for (int i = 2; i <= n; i++)
    {
        totalPrimes[i] = true;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (totalPrimes[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                totalPrimes[j] = false;
        }
    }

    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {

        if (totalPrimes[i] == true)
        {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}