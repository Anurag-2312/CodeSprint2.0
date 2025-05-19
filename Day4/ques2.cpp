#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n > 10)
    {
        cout << "The body achieves what the mind believes\n";
    }
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < (n - i) * 3 / 2; k++)
        {
            cout << " ";
        }
        if (i % 2 == 1)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << "   ";
                count++;
            }
        }
        else
        {
            for (int j = i; j >= 1; j--)
            {
                cout << j << "   ";
                count++;
            }
        }
        cout << endl;
    }
    cout << "Total Number printed :" << count << endl;
    return 0;
}