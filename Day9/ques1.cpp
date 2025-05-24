#include <bits/stdc++.h>
using namespace std;

vector<int> fun(string s, string p)
{
    vector<int> res;
    if (s.size() < p.size())
        return res;

    vector<int> pc(26, 0), wc(26, 0);
    int m = p.size(), n = s.size();

    for (int i = 0; i < m; ++i)
    {
        pc[p[i] - 'a']++;
        wc[s[i] - 'a']++;
    }

    if (pc == wc)
        res.push_back(0);

    for (int i = m; i < n; ++i)
    {
        wc[s[i] - 'a']++;
        wc[s[i - m] - 'a']--;
        if (wc == pc)
            res.push_back(i - m + 1);
    }

    return res;
}

int main()
{
    string s, p;
    cout << "Enter logStream: ";
    cin >> s;

    cout << "Enter pattern: ";
    cin >> p;
    vector<int> ans = fun(s, p);
    for (int i : ans)
        cout << i << " ";

    return 0;
}
