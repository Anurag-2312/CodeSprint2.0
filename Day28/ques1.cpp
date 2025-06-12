#include <bits/stdc++.h>
using namespace std;

string fun(string s)
{
    unordered_map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }

    priority_queue<pair<int, char>> maxheap;
    for (auto it : mp)
    {
        maxheap.push({it.second, it.first});
    }

    string result = "";
    pair<int, char> prev = {-1, '#'};

    while (!maxheap.empty())
    {
        auto curr = maxheap.top();
        maxheap.pop();
        result += curr.second;

        if (prev.first > 0)
        {
            maxheap.push(prev);
        }
        curr.first--;
        prev = curr;
    }

    return result.length() == s.length() ? result : "";
}

int main()
{
    string s;
    cin >> s;
    cout << "Output: " << fun(s) << endl;
    return 0;
}
