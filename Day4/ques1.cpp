#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = 1;
    int ad = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << d++ << ' ';
            }
            else if (i + j == n - 1)
            {
                cout << ad-- << ' ';
            }
            else
            {
                cout << "-" << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}