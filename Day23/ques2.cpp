#include <bits/stdc++.h>
using namespace std;

string fun(string s)
{
    queue<int> radiant, dire;
    int n = s.length();

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    while (!radiant.empty() && !dire.empty())
    {
        int r = radiant.front();
        radiant.pop();
        int d = dire.front();
        dire.pop();

        if (r < d)
            radiant.push(r + n);
        else
            dire.push(d + n);
    }

    return radiant.empty() ? "Dire" : "Radiant";
}

int main()
{
    string s;
    cout << "Enter the senate string: ";
    cin >> s;

    string ans = fun(s);
    cout << "Winning party: " << ans << endl;
    return 0;
}
