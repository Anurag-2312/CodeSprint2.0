#include <bits/stdc++.h>
using namespace std;

string fun(string s)
{
    string result = "";
    int bal = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (bal > 0)
            {
                result += s[i];
            }
            bal++;
        }
        else
        {
            bal--;
            if (bal > 0)
            {
                result += s[i];
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << fun(s) << endl;
    return 0;
}
