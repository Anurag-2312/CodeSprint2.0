#include <bits/stdc++.h>
using namespace std;

string fun(string &s)
{
    unordered_map<char, int> mp;
    queue<char> q;
    string result = "";

    for (char ch : s)
    {
        mp[ch]++;
        q.push(ch);

        while (!q.empty() && mp[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            result += '#';
        }
        else
        {
            result += q.front();
        }
    }

    return result;
}

int main()
{
    string s;
    cout << "Enter the characters: ";
    cin >> s;

    string ans = fun(s);
    cout << ans << endl;

    return 0;
}
