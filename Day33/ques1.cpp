#include <bits/stdc++.h>
using namespace std;

bool fun(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (int theme : arr)
    {
        mp[theme]++;
    }

    int total = mp.size();
    int count = 0;

    for (auto it : mp)
    {
        if (it.second >= 2)
        {
            count++;
        }
    }
    if (total >= 2 * k)
        return true;

    int need = 2 * k - total;
    return count >= need;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (fun(n, k, arr))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
