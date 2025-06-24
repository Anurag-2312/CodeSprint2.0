#include <bits/stdc++.h>
using namespace std;

double fun(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 1 / fun(x, -n);

    double half = fun(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

int main()
{
    double x;
    int n;
    cout << "Enter base: ";
    cin >> x;
    cout << "Enter exponent: ";
    cin >> n;

    double result = fun(x, n);
    cout << fixed << result << endl;
    return 0;
}
