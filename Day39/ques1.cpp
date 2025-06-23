#include <bits/stdc++.h>
using namespace std;

int idx = 0;

string fun(string &s)
{
    string res = "";

    while (idx < s.length() && s[idx] != ']')
    {
        if (isdigit(s[idx]))
        {
            int k = 0;
            while (isdigit(s[idx]))
            {
                k = k * 10 + (s[idx] - '0');
                idx++;
            }

            idx++;
            string x = fun(s);
            idx++;

            while (k--)
            {
                res += x;
            }
        }
        else
        {
            res += s[idx++];
        }
    }

    return res;
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    idx = 0;
    string ans = fun(s);
    cout << ans << endl;

    return 0;
}
