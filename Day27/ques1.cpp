#include <bits/stdc++.h>
using namespace std;

vector<string> fun(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i)
        v.push_back({arr[i], i});

    sort(v.rbegin(), v.rend());

    vector<string> res(n);
    for (int i = 0; i < n; ++i)
    {
        int idx = v[i].second;
        if (i == 0)
            res[idx] = "Gold Medal";
        else if (i == 1)
            res[idx] = "Silver Medal";
        else if (i == 2)
            res[idx] = "Bronze Medal";
        else
            res[idx] = to_string(i + 1);
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter number of robots: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the scores: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<string> result = fun(arr);

    cout << "Ranks: ";
    for (string s : result)
        cout << s << " ";
    cout << endl;

    return 0;
}
