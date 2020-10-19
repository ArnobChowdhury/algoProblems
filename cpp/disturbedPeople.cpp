#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int flats[100];
    int j = 0;
    while (j < n)
    {
        int inp;
        cin >> inp;
        flats[j] = inp;
        j++;
    }

    int count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (flats[i] == 0 && flats[i - 1] == 1 && flats[i + 1] == 1)
        {
            flats[i + 1] = 0;
            count++;
            bool exists;
        }
    }
    cout << count << endl;
}