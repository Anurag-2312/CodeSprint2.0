#include <bits/stdc++.h>
using namespace std;

double gsum(int n)
{
    double sum = 0;
    double i = 0;
    while (i <= n)
    {
        sum += (double)1 / pow(3, i);
        i++;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    cout << gsum(n) << endl;
}