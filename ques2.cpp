#include <bits/stdc++.h>
using namespace std;
bool hasVowel(string Name)
{
    char ch = Name[0];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "enter total patient :\n";
    cin >> n;

    vector<string> ans;
    vector<string> P(n);

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (hasVowel(P[i]) && mp.find(P[i]) == mp.end())
        {
            mp[P[i]] = 1;
            ans.push_back(P[i]);
        }
    }
    cout << ans.size() << endl;
    for (string s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}