#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr;
        while (n--)
        {
            int inp;
            cin >> inp;
            arr.push_back(inp);
        }

        int smallestind = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[smallestind])
            {
                smallestind = i;
            }
        }
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (j != smallestind)
            {
                while (k >= arr[j] + arr[smallestind])
                {
                    arr[j] = arr[j] + arr[smallestind];
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}