#include <bits/stdc++.h>

using namespace std;
// n = 6
// Trains = [(2, 2.30), (2.10, 3.40), (3.00, 3.20), (3.20, 4.30), (3.50, 4), (5, 5.20)]

int minPlatforms(vector<pair<double, double>> trains)
{
    vector<pair<double, int>> events;
    for (pair<int, int> tr : trains)
    {
        events.push_back(make_pair(tr.first, 1));
        events.push_back(make_pair(tr.second, 0));
    }

    sort(events.begin(), events.end());
    int ans = 0, free_plat = 0;
    for (pair<double, int> ev : events)
    {
        if (ev.second == 0)
            free_plat++;
        else
        {
            if (free_plat == 0)
                ans++;
            else
                free_plat--;
        }
    }
    return ans;
}

int main()
{
    double trainsArray[6][2] = {{2, 2.3}, {2.1, 3.4}, {3, 3.2}, {3.2, 4.3}, {3.5, 4}, {5, 5.2}};

    vector<pair<double, double>> trains;

    for (int i = 0; i < 6; i++)
        trains.push_back(make_pair(trainsArray[i][0], trainsArray[i][1]));

    int ans = minPlatforms(trains);

    cout << ans << endl;
    return 0;
}