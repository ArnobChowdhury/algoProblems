#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100;
const int Mmax = 100;

bool a[Nmax][Mmax] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 0},
};
int n, m, dist[Nmax][Mmax]; // dist for distnace

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int leesAlgo(pair<int, int> src, pair<int, int> dst)
{
    queue<pair<int, int>> Q;
    dist[src.first][src.second] = 1;
    Q.push(src);

    while (!Q.empty())
    {
        pair<int, int> cell = Q.front();

        if (cell == dst)
            return dist[cell.first][cell.second] - 1;

        Q.pop();

        for (int dir = 0; dir < 4; dir++)
            if (a[cell.first + dx[dir]][cell.second + dy[dir]] == 1 && dist[cell.first + dx[dir]][cell.second + dy[dir]] == 0)
            {
                dist[cell.first + dx[dir]][cell.second + dy[dir]] = dist[cell.first][cell.second] + 1;
                Q.push(make_pair(cell.first + dx[dir], cell.second + dy[dir]));
            }
    }
    return -1;
}

int main()
{
    pair<int, int> src;
    src.first = 6;
    src.second = 5;

    pair<int, int> dst;
    dst.first = 2;
    dst.second = 3;

    int res = leesAlgo(src, dst);

    cout << res << endl;
    return 0;
}