#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &houses, vector<int> &heaters)
{
    sort(heaters.begin(), heaters.end());
    int radius = 0;

    for (int x : houses)
    {
        auto it = lower_bound(heaters.begin(), heaters.end(), x);
        int dist1 = (it != heaters.end()) ? abs(x - *it) : INT_MAX;
        int dist2 = (it != heaters.begin()) ? abs(x - *(prev(it))) : INT_MAX;
        int min_dist = min(dist1, dist2);
        radius = max(radius, min_dist);
    }

    return radius;
}

int main()
{
    int h, t;
    cin >> h;
    vector<int> houses(h);
    for (int i = 0; i < h; i++)
        cin >> houses[i];

    cin >> t;
    vector<int> heaters(t);
    for (int i = 0; i < t; i++)
        cin >> heaters[i];

    cout << "Radius :" << fun(houses, heaters) << endl;
    return 0;
}
