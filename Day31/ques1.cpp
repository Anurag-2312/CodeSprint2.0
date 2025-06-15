#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int count = 0;
    for (auto it1 : freq)
    {
        for (auto it2 : freq)
        {
            if (it1.first > it2.first)
            {
                count += it1.second * it2.second;
            }
        }
    }
    cout << count << endl;
    return 0;
}
