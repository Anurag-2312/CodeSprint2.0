#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;

    for (char ch : s)
    {
        mp[ch]++;
    }

    int freq = mp.begin()->second;

    bool bal = true;
    for (auto it : mp)
    {
        if (it.second != freq)
        {
            bal = false;
            break;
        }
    }

    if (bal)
    {
        cout << "Aashriya smiles: Emotional balance found." << endl;
    }
    else
    {
        cout << "Aashriya wonders: These thoughts were scattered." << endl;
    }
    return 0;
}