#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
                count++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << "total student seated :" << count << endl;
    return 0;
}