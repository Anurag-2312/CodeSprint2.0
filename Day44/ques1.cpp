#include <bits/stdc++.h>
using namespace std;

bool fun(string s, string t)
{
    unordered_map<char, int> mpt;
    unordered_map<char, int> tpt;

    for (int i = 0; i < s.size(); i++)
    {
        if (mpt.find(s[i]) == mpt.end())
        {
            mpt[s[i]] = i;
        }
        if (tpt.find(t[i]) == tpt.end())
        {
            tpt[t[i]] = i;
        }
        if (mpt[s[i]] != tpt[t[i]])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    if (fun(s, t))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
