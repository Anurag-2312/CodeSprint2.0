#include <bits/stdc++.h>
using namespace std;

vector<int> findMatches(string text, string pattern)
{
    vector<int> res;
    int n = text.size(), m = pattern.size();

    if (m > n)
        return res;

    for (int i = 0; i <= n - m; i++)
    {
        if (text.substr(i, m) == pattern)
        {
            res.push_back(i);
        }
    }

    return res;
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> indices = findMatches(text, pattern);

    if (indices.empty())
    {
        cout << "No matches found.\n";
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int i : indices)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
