#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    string j, s; // j= jewels , s= stones //
    cin >> j >> s;

    map<char, int> mp;

    for (int i = 0; i < j.size(); i++)
    {
        mp[j[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}