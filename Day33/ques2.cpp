#include <bits/stdc++.h>
using namespace std;

int fun(string s)
{
    int i = 0, j = s.length() - 1;
    int flips = 0;

    while (i < j)
    {
        while (i < j && s[i] != '1')
        {
            i++;
        }

        while (i < j && s[j] != '0')
        {
            j--;
        }

        if (i < j)
        {
            flips++;
            i++;
            j--;
        }
    }

    return flips;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << fun(s) << endl;
    return 0;
}
