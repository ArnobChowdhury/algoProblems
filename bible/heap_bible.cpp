#include <bits/stdc++.h>

using namespace std;

int n = 0;
int maxHeap[1000] = {};

void upHeap(int pos)
{
    while (pos > 1 && maxHeap[pos] > maxHeap[pos / 2])
    {
        swap(maxHeap[pos], maxHeap[pos / 2]);
        pos /= 2;
    }
}

void insert(int x)
{
    maxHeap[++n] = x;
    upHeap(n);
}

void downHeap(int pos)
{
    int largest = pos;
    int l_son = 2 * pos, r_son = 2 * pos + 1;

    if (l_son <= n && maxHeap[l_son] > maxHeap[largest])
        largest = l_son;
    if (r_son <= n && maxHeap[r_son] > maxHeap[largest])
        largest = r_son;
    if (pos != largest)
    {
        swap(maxHeap[pos], maxHeap[largest]);
        downHeap(largest);
    }
}

void removeMax()
{
    maxHeap[1] = maxHeap[n--];
    downHeap(1);
}

int main()
{
    return 0;
}