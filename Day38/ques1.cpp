#include <bits/stdc++.h>
using namespace std;

char fun(int k)
{
    string s = "a";

    while ((int)s.size() < k)
    {
        string next = "";
        for (char ch : s)
        {
            next += (ch == 'z') ? 'a' : (ch + 1);
        }
        s += next;
    }

    return s[k - 1];
}

int main()
{
    int k;
    cin >> k;
    cout << fun(k) << endl;
    return 0;
}
