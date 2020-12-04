#include <iostream>

using namespace std;

const int Nmax = 1005;

int b[Nmax];
int a[Nmax];

void mergeArrays(int left, int mid, int right)
{
    int i = left, j = mid + 1, p = 1;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            b[p++] = a[i++];
        else
            b[p++] = a[j++];
    }
    while (i <= mid)
        b[p++] = a[i++];

    while (j <= right)
        b[p++] = a[j++];

    for (int i = left; i <= right; i++)
        a[i] = b[i - left + 1];
}

void mergeSort(int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    mergeArrays(left, mid, right);
}

int main()
{
    a[1] = 9;
    a[2] = 10;
    a[3] = 8;
    a[4] = 7;
    a[5] = 3;
    a[6] = 1;
    a[7] = 6;
    a[8] = 4;
    a[9] = 5;
    a[10] = 2;

    mergeSort(1, 10);

    for (int i = 1; i <= 10; i++)
        cout << a[i] << endl;

    return 0;
}