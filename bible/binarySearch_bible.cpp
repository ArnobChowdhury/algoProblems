#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int n, int searchItem)
{
    int left = 0, right = n - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == searchItem)
            return mid;
        else
        {
            if (searchItem > arr[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {5, 13, 27, 36, 45, 56, 61, 79, 84, 99};

    int ind = binarySearch(arr, 10, 84);

    cout << ind << endl;
    return 0;
}