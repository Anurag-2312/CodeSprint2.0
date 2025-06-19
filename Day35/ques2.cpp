#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    map<int, int> mp;
    for (int p : arr)
    {
        mp[p]++;
    }

    int result = 0;

    while (!mp.empty())
    {
        int current = mp.begin()->first;

        while (mp.count(current))
        {
            mp[current]--;
            if (mp[current] == 0)
                mp.erase(current);
            current++;
        }

        result++;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << fun(arr) << endl;
    return 0;
}
