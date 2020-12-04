#include <iostream>
#include <unordered_map>

using namespace std;

int numOfPairs(int a[], int n, int s)
{
    int ans = 0;
    unordered_map<int, int> myMap;

    for (int i = 0; i < n; i++)
    {
        int ad = myMap[s - a[i]];
        ans += ad;
        myMap[a[i]]++;
    }

    return ans;
}

int main()
{
    int a[7] = {3, -2, 9, 3, -2, 4, 9};
    int res = numOfPairs(a, 7, 7);

    cout << res << endl;
}
