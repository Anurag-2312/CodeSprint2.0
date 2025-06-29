#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string fun(string exp)
{
    int num = 0, den = 1;
    int i = 0, n = exp.size();

    while (i < n)
    {
        int sign = 1;
        if (exp[i] == '+' || exp[i] == '-')
        {
            sign = (exp[i] == '+') ? 1 : -1;
            i++;
        }

        int curr = 0;
        while (i < n && isdigit(exp[i]))
        {
            curr = curr * 10 + (exp[i] - '0');
            i++;
        }

        i++;
        int currden = 0;
        while (i < n && isdigit(exp[i]))
        {
            currden = currden * 10 + (exp[i] - '0');
            i++;
        }

        curr *= sign;

        int lcm = den * currden / gcd(den, currden);
        num = num * (lcm / den) + curr * (lcm / currden);
        den = lcm;

        int common = gcd(abs(num), den);
        num /= common;
        den /= common;
    }

    return to_string(num) + "/" + to_string(den);
}

int main()
{
    string s;
    cin >> s;
    cout << fun(s) << endl;
    return 0;
}
