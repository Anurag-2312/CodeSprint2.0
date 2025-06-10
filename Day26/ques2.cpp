#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        if (mp[a] == mp[b]) return a < b;
        return mp[a] > mp[b]; });

    for (int c : arr)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
