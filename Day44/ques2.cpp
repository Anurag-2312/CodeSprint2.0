#include <bits/stdc++.h>
using namespace std;

int mask(string &word)
{
    int bit = 0;
    for (char c : word)
        bit = bit | (1 << (c - 'a'));
    return bit;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    vector<int> masks(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
        masks[i] = mask(words[i]);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((masks[i] & masks[j]) == 0)
            {
                int len = words[i].length() * words[j].length();
                maxi = max(maxi, len);
            }
        }
    }

    cout << maxi << endl;
    return 0;
}
